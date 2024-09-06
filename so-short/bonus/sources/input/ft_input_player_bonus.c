/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:11 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:09:02 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	ft_input_manager(int key_code, t_game *game)
{
	ft_exit_handler_helper(game, key_code);
	ft_check_konami_code(game, key_code);
	if (game->state == STATE_MENU || game->state == STATE_PAUSED \
		|| game->state == STATE_WIN || game->state == STATE_LOSE)
		ft_menu_input_manager(game, key_code);
	else if (game->state == STATE_PLAYING)
	{
		if (key_code == LINUX_LETTER_P)
			ft_toggle_pause(game);
		else
			ft_movement_input(game, key_code);
	}
	return (EXIT_SUCCESS);
}

void	ft_movement_input(t_game *game, int key_code)
{
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
	ft_exit_handler_helper(game, key_code);
}

void	ft_move_player(t_game *game, int new_x, int new_y)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	next_tile = game->map.grid[new_y][new_x];
	if (next_tile == PAWN_CHAR)
		ft_deactivate_pawn_at_position(game, (t_point){new_x, new_y});
	ft_handle_box_movement(game, (t_point){new_x, new_y}, &next_tile);
	if (ft_handle_teleport(game, (t_point){new_x, new_y}, next_tile))
		return ;
	if (ft_play_can_move_to_tile(game, next_tile))
	{
		game->map.grid[y][x] = VOID_CHAR;
		game->map.grid[new_y][new_x] = PLAYER_CHAR;
		game->player.movement.current_position.x = new_x;
		game->player.movement.current_position.y = new_y;
		ft_play_movement_sound(game);
		ft_handle_tile_action(game, next_tile);
	}
}

void	ft_exit_handler_helper(t_game *game, int key_code)
{
	if (key_code == LINUX_ESC_KEY)
		ft_exit_game(game);
}

void	ft_toggle_pause(t_game *game)
{
	if (game->state == STATE_PAUSED)
		game->state = STATE_PLAYING;
	else
		game->state = STATE_PAUSED;
}
