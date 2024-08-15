/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:11 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 13:38:41 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//remove this shit
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//remove this shit

void toggle_pause(t_game *game) {
    if (game->state == STATE_PAUSED) {
        game->state = STATE_PLAYING;
    } else {
        game->state = STATE_PAUSED;
    }
}

/**
 * @brief
 *
 * 		this fct will be trigger by mlx_hook in the main
 * 	mlx_hook is alway listening if there i KEY_PRESS -> 2 x_event
 * the send it to input manager as a int, look at the mlx_hook
 * 	prototype, the here i manager wasd up down left right arrow
 * 				and also 4 8 6 2 pav num
 * 		those are set in the enumeration in .h  t_key_code
 *
 * for each direction we call the good fct and seed the t_game pointer
 * 			alway returning 0 -> EXIT_SUCCESS
 *
 *
 *  //recup key_code and put in game struct
 *
 * @param key_code
 * @param game
 * @return int
 */
int	ft_input_manager(int key_code, t_game *game)
{
	//ft_move_pawn(game);
	if (key_code == 112)//make enumaration for input ?abcd
	{ // 'P' key for pause
		//game->paused = !game->paused;
		toggle_pause(game);
		return (EXIT_SUCCESS);
	}
	if (game->state == STATE_PAUSED)
		return (EXIT_SUCCESS);
	if (game->map.info.nbr_keke)
		ft_a_star_keke_movement(game);
	if ((key_code == LINUX_W_KEY || key_code == LINUX_UP_ARROW_KEY
			|| key_code == LINUX_UP_PAV_NUM_KEY))
		ft_input_up(game);
	if ((key_code == LINUX_S_KEY || key_code == LINUX_DOWN_ARROW_KEY
			|| key_code == LINUX_DOWN_PAV_NUM_KEY))
		ft_input_down(game);
	if ((key_code == LINUX_A_KEY || key_code == LINUX_LEFT_ARROW_KEY
			|| key_code == LINUX_LEFT_PAV_NUM_KEY))
		ft_input_left(game);
	if ((key_code == LINUX_D_KEY || key_code == LINUX_RIGHT_ARROW_KEY
			|| key_code == LINUX_RIGHT_PAV_NUM_KEY))
		ft_input_right(game);
	if (key_code == LINUX_ESC_KEY)
		ft_exit_game(game);
	return (EXIT_SUCCESS);
}

t_bool	can_move_to_tile(t_game *game, char next_tile)
{
	if (next_tile == LOVE_CHAR && game->player.life >= 6)
	{
		// Trigger feedback (e.g., camera shake) when trying to take more lives than allowed
		ft_baba_forbidden(game);
		ft_camera_shake(game);
		ft_printf("Maximum life is 3");
		return FALSE;
	}
	return (next_tile != WALL_CHAR && next_tile != BOX_CHAR
		&& !(next_tile == EXIT_CHAR && game->map.info.nbr_key != game->player.storage));
}

// Helper function to handle teleportation
t_bool	handle_teleport(t_game *game, int new_x, int new_y, char next_tile)
{
	if (next_tile == 'N' || next_tile == 'Z')
	{
		game->map.grid[game->player.movement.current_position.y][game->player.movement.current_position.x] = VOID_CHAR;
		ft_teleport_player(game, new_y, new_x);
		return (TRUE);
	}
	return (FALSE);
}

// Helper function to handle moving boxes
void	handle_box_movement(t_game *game, int new_x, int new_y, char *next_tile)
{
	t_point	new_pos;

	new_pos.x = new_x;
	new_pos.y = new_y;
	if (*next_tile == BOX_CHAR)
	{
		ft_move_box(game, new_pos, new_y - game->player.movement.current_position.y, new_x - game->player.movement.current_position.x);
		*next_tile = game->map.grid[new_y][new_x]; // Re-evaluate the next tile
	}
}

void ft_random_pawn_activation(t_game *game) {
    // Seed the random number generator once at the start of the program, not here
    int random_index = rand() % game->map.info.nbr_pawn;

    // Toggle the activation status of a random pawn
	if (game->pawn.pawns_array[random_index].is_available)
    	game->pawn.pawns_array[random_index].is_active = !game->pawn.pawns_array[random_index].is_active;
}


void	ft_move_player(t_game *game, int new_x, int new_y)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	next_tile = game->map.grid[new_y][new_x];
	if (game->map.info.nbr_pawn)
		ft_random_pawn_activation(game);
	handle_box_movement(game, new_x, new_y, &next_tile);
	if (handle_teleport(game, new_x, new_y, next_tile))
		return;
	if (can_move_to_tile(game, next_tile))
	{
		game->map.grid[y][x] = VOID_CHAR;
		game->map.grid[new_y][new_x] = PLAYER_CHAR;
		game->player.movement.current_position.x = new_x;
		game->player.movement.current_position.y = new_y;
		ft_play_movement_sound(game);
		ft_handle_tile_action(game, next_tile);
	}
}

void	ft_move_up(t_game *game)
{
	int x = game->player.movement.current_position.x;
	int y = game->player.movement.current_position.y;
	if (y > 0)
		ft_move_player(game, x, y - 1);
}

void	ft_move_down(t_game *game)
{
	int x = game->player.movement.current_position.x;
	int y = game->player.movement.current_position.y;
	if (y < game->height - 1)
		ft_move_player(game, x, y + 1);
}

void	ft_move_left(t_game *game)
{
	int x = game->player.movement.current_position.x;
	int y = game->player.movement.current_position.y;
	if (x > 0)
		ft_move_player(game, x - 1, y);
}

void	ft_move_right(t_game *game)
{
	int x = game->player.movement.current_position.x;
	int y = game->player.movement.current_position.y;
	if (x < game->width - 1)
		ft_move_player(game, x + 1, y);
}

// void	ft_move_up(t_game *game)
// {
// 	int		x;
// 	int		y;
// 	char	next_tile;

// 	x = game->player.movement.current_position.x;
// 	y = game->player.movement.current_position.y;
// 	if (y > 0)
// 	{
// 		next_tile = game->map.grid[y - 1][x];
// 		ft_handle_tile_action(game, next_tile);
// 		if (next_tile == BOX_CHAR)
// 		{
// 			ft_move_box(game, y - 1, x, -1, 0);
// 			next_tile = game->map.grid[y - 1][x];
// 		}
// 		if (next_tile == 'N' || next_tile == 'Z')
// 		{
// 			game->map.grid[y][x] = VOID_CHAR;
// 			ft_teleport_player(game, y - 1, x);
// 			return ;
// 		}
// 		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR
// 			&& !(next_tile == EXIT_CHAR
// 				&& game->map.info.nbr_key != game->player.storage)
// 			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
// 		{
// 			game->map.grid[y][x] = VOID_CHAR;
// 			game->map.grid[y - 1][x] = PLAYER_CHAR;
// 			ft_play_movement_sound(game);
// 			game->player.movement.current_position.y -= 1;
// 			//ft_handle_tile_action(game, next_tile);
// 		}
// 	}
// }

// void	ft_move_down(t_game *game)
// {
// 	int		x;
// 	int		y;
// 	char	next_tile;

// 	x = game->player.movement.current_position.x;
// 	y = game->player.movement.current_position.y;
// 	if (y < game->height - 1)
// 	{
// 		next_tile = game->map.grid[y + 1][x];
// 		if (next_tile == BOX_CHAR)
// 		{
// 			ft_move_box(game, y + 1, x, 1, 0);
// 			next_tile = game->map.grid[y + 1][x];
// 		}
// 		if (next_tile == 'N' || next_tile == 'Z')
// 		{
// 			game->map.grid[y][x] = VOID_CHAR;
// 			ft_teleport_player(game, y + 1, x);
// 			return ;
// 		}
// 		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR
// 			&& !(next_tile == EXIT_CHAR
// 				&& game->map.info.nbr_key != game->player.storage)
// 			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
// 		{
// 			game->map.grid[y][x] = VOID_CHAR;
// 			game->map.grid[y + 1][x] = PLAYER_CHAR;
// 			ft_play_movement_sound(game);
// 			game->player.movement.current_position.y += 1;
// 			//ft_handle_tile_action(game, next_tile);
// 		}
// 		ft_handle_tile_action(game, next_tile);
// 	}
// }

// void	ft_move_left(t_game *game)
// {
// 	int		x;
// 	int		y;
// 	char	next_tile;

// 	x = game->player.movement.current_position.x;
// 	y = game->player.movement.current_position.y;
// 	if (x > 0)
// 	{
// 		next_tile = game->map.grid[y][x - 1];
// 		ft_handle_tile_action(game, next_tile);
// 		if (next_tile == BOX_CHAR)
// 		{
// 			ft_move_box(game, y, x - 1, 0, -1);
// 			next_tile = game->map.grid[y][x - 1];
// 		}
// 		if (next_tile == 'N' || next_tile == 'Z')
// 		{
// 			game->map.grid[y][x] = VOID_CHAR;
// 			ft_teleport_player(game, y, x - 1);
// 			return ;
// 		}
// 		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR
// 			&& !(next_tile == EXIT_CHAR
// 				&& game->map.info.nbr_key != game->player.storage)
// 			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
// 		{
// 			game->map.grid[y][x] = VOID_CHAR;
// 			game->map.grid[y][x - 1] = PLAYER_CHAR;
// 			ft_play_movement_sound(game);
// 			game->player.movement.current_position.x -= 1;
// 			//ft_handle_tile_action(game, next_tile);
// 		}
// 	}
// }

// void	ft_move_right(t_game *game)
// {
// 	int		x;
// 	int		y;
// 	char	next_tile;

// 	x = game->player.movement.current_position.x;
// 	y = game->player.movement.current_position.y;
// 	if (x < game->width - 1)
// 	{
// 		next_tile = game->map.grid[y][x + 1];
// 		ft_handle_tile_action(game, next_tile);
// 		if (next_tile == BOX_CHAR)
// 		{
// 			ft_move_box(game, y, x + 1, 0, 1);
// 			next_tile = game->map.grid[y][x + 1];
// 		}
// 		if (next_tile == 'N' || next_tile == 'Z')
// 		{
// 			game->map.grid[y][x] = VOID_CHAR;
// 			ft_teleport_player(game, y, x + 1);
// 			return ;
// 		}
// 		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR
// 			&& !(next_tile == EXIT_CHAR
// 				&& game->map.info.nbr_key != game->player.storage)
// 			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
// 		{
// 			game->map.grid[y][x] = VOID_CHAR;
// 			game->map.grid[y][x + 1] = PLAYER_CHAR;
// 			ft_play_movement_sound(game);
// 			game->player.movement.current_position.x += 1;
// 			//ft_handle_tile_action(game, next_tile);
// 		}
// 	}
// }
