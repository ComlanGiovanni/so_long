/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:01:54 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 16:48:46 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

/*
				IDEAD
		DIAGONAL MOVE IF 7 9 1 3 is pressed
	fct who combine move (up + left) by the  vailableness up up or let etc


    else
        iddle animation counter 5 sec

*/

int	ft_input_manager(int key_code, t_game *game)
{
	if (key_code == MAC_ESC_KEY)
		ft_exit_game(game);
	if (key_code == MAC_W_KEY || key_code == MAC_UP_ARROW_KEY
		|| key_code == MAC_UP_PAV_NUM_KEY)
		ft_input_up(game);
	if (key_code == MAC_S_KEY || key_code == MAC_DOWN_ARROW_KEY
		|| key_code == MAC_DOWN_PAV_NUM_KEY)
		ft_input_down(game);
	if (key_code == MAC_A_KEY || key_code == MAC_LEFT_ARROW_KEY
		|| key_code == MAC_LEFT_PAV_NUM_KEY)
		ft_input_left(game);
	if (key_code == MAC_D_KEY || key_code == MAC_RIGHT_ARROW_KEY
		|| key_code == MAC_RIGHT_PAV_NUM_KEY)
		ft_input_right(game);
	ft_print_game_info(game, key_code);
	return (EXIT_SUCCESS);
}

/*
make a fct for move
and by the keycodepresse asign
the variable game->width by 1 or
change the sign for some condition

//game->sprite.player_up = game->sprite.player_up_frame_move;

//game->direction = 'u';
//ft_printf("Step counter : %d\n", game->step);
*/

void	ft_move_up(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx++ < game->map.len)
	{
		if (game->map.map_str[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map.map_str[idx - game->width] == KEY_CHAR)
		game->player.storage++;
	if (game->map.map_str[idx - game->width] == LOVE_CHAR)
		game->player.life++;
	if (game->map.map_str[idx - game->width] == LAVA_CHAR)
		game->player.life--;
	if (game->map.map_str[idx - game->width] == EXIT_CHAR
		&& game->map.nbr_key == game->player.storage)
		ft_win_game(game);
	else if (game->map.map_str[idx - game->width] != WALL_CHAR
		&& game->map.map_str[idx - game->width] != EXIT_CHAR)
	{
		game->map.map_str[idx] = VOID_CHAR;
		game->map.map_str[idx - game->width] = PLAYER_CHAR;
		game->player.step++;
		ft_put_sprites_by_line(game);
	}
}

/*
	need to watch overflex if anyint
	storage or life ou sa ne sert a rine paceque
	la possiiliter aue ca arriv est ultra longue et rare ??

//game->sprite.player_down = game->sprite.player_down_frame_move;

//game->direction = 'd';
//ft_printf("Step counter : %d\n", game->step);
*/

void	ft_move_down(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx++ < game->map.len)
	{
		if (game->map.map_str[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map.map_str[idx + game->width] == KEY_CHAR)
		game->player.storage++;
	if (game->map.map_str[idx + game->width] == LOVE_CHAR)
		game->player.life++;
	if (game->map.map_str[idx + game->width] == LAVA_CHAR)
		game->player.life--;
	if (game->map.map_str[idx + game->width] == EXIT_CHAR
		&& game->map.nbr_key == game->player.storage)
		ft_win_game(game);
	else if (game->map.map_str[idx + game->width] != WALL_CHAR
		&& game->map.map_str[idx + game->width] != EXIT_CHAR)
	{
		game->map.map_str[idx] = VOID_CHAR;
		game->map.map_str[idx + game->width] = PLAYER_CHAR;
		game->player.step++;
		ft_put_sprites_by_line(game);
	}
}

//game->sprite.player_left = game->sprite.player_left_frame_move;

//game->direction = 'l';
//ft_printf("Step counter : %d\n", game->step);

void	ft_move_left(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx++ < game->map.len)
	{
		if (game->map.map_str[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map.map_str[idx - 1] == KEY_CHAR)
		game->player.storage++;
	if (game->map.map_str[idx - 1] == LOVE_CHAR)
		game->player.life++;
	if (game->map.map_str[idx - 1] == LAVA_CHAR)
		game->player.life--;
	if (game->map.map_str[idx - 1] == EXIT_CHAR
		&& game->player.storage == game->map.nbr_key)
		ft_win_game(game);
	else if (game->map.map_str[idx - 1] != WALL_CHAR
		&& game->map.map_str[idx - 1] != EXIT_CHAR)
	{
		game->map.map_str[idx] = VOID_CHAR;
		game->map.map_str[idx - 1] = PLAYER_CHAR;
		game->player.step++;
		ft_put_sprites_by_line(game);
	}
}

//game->sprite.player_right = game->sprite.player_right_frame_move;

//game->direction = 'r';
//ft_printf("Step counter : %d\n", game->step);

void	ft_move_right(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx++ < game->map.len)
	{
		if (game->map.map_str[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map.map_str[idx + 1] == KEY_CHAR)
		game->player.storage++;
	if (game->map.map_str[idx + 1] == LOVE_CHAR)
		game->player.life++;
	if (game->map.map_str[idx + 1] == LAVA_CHAR)
		game->player.life--;
	if (game->map.map_str[idx + 1] == EXIT_CHAR
		&& game->player.storage == game->map.nbr_key)
		ft_win_game(game);
	else if (game->map.map_str[idx + 1] != WALL_CHAR
		&& game->map.map_str[idx + 1] != EXIT_CHAR)
	{
		game->map.map_str[idx] = VOID_CHAR;
		game->map.map_str[idx + 1] = PLAYER_CHAR;
		game->player.step++;
		ft_put_sprites_by_line(game);
	}
}
