/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:01:54 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/18 14:55:50 by gcomlan          ###   ########.fr       */
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

int     ft_input_manager(int key_code, t_game *game)
{
	if (key_code == MAC_ESC_KEY)
		ft_exit_game(game);
	if (key_code == MAC_W_KEY || key_code == MAC_UP_ARROW_KEY || key_code == MAC_UP_PAV_NUM_KEY)
	{
		game->sprite.player_up = game->sprite.player_up_frame_move;
		game->direction = 'u';
		ft_move_up(game);
	}
    if (key_code == MAC_S_KEY || key_code == MAC_DOWN_ARROW_KEY || key_code == MAC_DOWN_PAV_NUM_KEY)
	{
		game->sprite.player_down = game->sprite.player_down_frame_move;
		game->direction = 'd';
		ft_move_down(game);
	}
	if (key_code == MAC_A_KEY || key_code == MAC_LEFT_ARROW_KEY || key_code == MAC_LEFT_PAV_NUM_KEY)
	{
		game->sprite.player_left = game->sprite.player_left_frame_move;
		game->direction = 'l';
		ft_move_left(game);
	}
	if (key_code == MAC_D_KEY || key_code == MAC_RIGHT_ARROW_KEY || key_code == MAC_RIGHT_PAV_NUM_KEY)
	{
		game->sprite.player_right = game->sprite.player_right_frame_move;
		game->direction = 'r';
		ft_move_right(game);
	}
	ft_print_game_info(game, key_code);
	return (EXIT_SUCCESS);
}

/*
make a fct for move
and by the keycodepresse asign
the variable game->width by 1 or
change the sign for some condition
*/

void	ft_move_up(t_game *game)
{
    int	idx;;

	idx = 0;

	//game->sprite.player_up = game->sprite.player_up_frame_move;
	while (idx++ < game->map_len)
	{
		if (game->map[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map[idx - game->width] == COIN_CHAR)
		game->storage++;
	if (game->map[idx - game->width] == EXIT_CHAR  && game->coin == game->storage)
		ft_win_game(game);
	else if (game->map[idx - game->width] != WALL_CHAR && game->map[idx - game->width] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx - game->width] = PLAYER_CHAR;
		game->step++;
		//game->direction = 'u';
		//ft_printf("Step counter : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

void	ft_move_down(t_game *game)
{
	int	idx;

	idx = 0;
	//game->sprite.player_down = game->sprite.player_down_frame_move;
	while (idx++ < game->map_len)
	{
		if (game->map[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map[idx + game->width] == COIN_CHAR)
		game->storage++;
	if (game->map[idx + game->width] == EXIT_CHAR && game->coin == game->storage)
		ft_win_game(game);
	else if (game->map[idx + game->width] != WALL_CHAR && game->map[idx + game->width] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx + game->width] = PLAYER_CHAR;
		game->step++;
		//game->direction = 'd';
		//ft_printf("Step counter : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

void	ft_move_left(t_game *game)
{
    int	idx;

	idx = 0;
	//game->sprite.player_left = game->sprite.player_left_frame_move;
	while (idx++ <game->map_len)
	{
		if (game->map[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map[idx - 1] == COIN_CHAR)
		game->storage++;
	if (game->map[idx - 1] == EXIT_CHAR && game->storage == game->coin)
		ft_win_game(game);
	else if (game->map[idx - 1] != WALL_CHAR && game->map[idx - 1] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx - 1] = PLAYER_CHAR;
		game->step++;
		//game->direction = 'l';
		//ft_printf("Step counter : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

void	ft_move_right(t_game *game)
{
    int	idx;

	idx = 0;
	//game->sprite.player_right = game->sprite.player_right_frame_move;
	while (idx++ < game->map_len)
	{
		if (game->map[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map[idx + 1] == COIN_CHAR)
		game->storage++;
	if (game->map[idx + 1] == EXIT_CHAR && game->storage == game->coin)
		ft_win_game(game);
	else if (game->map[idx + 1] != WALL_CHAR && game->map[idx + 1] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx + 1] = PLAYER_CHAR;
		game->step++;
		//game->direction = 'r';
		//ft_printf("Step counter : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}