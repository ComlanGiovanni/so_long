/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:01:54 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/17 03:34:58 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


int     ft_input_manager(int key_code, t_game *game)
{
	if (key_code == ESC_KEY)
		ft_exit_game(game);
	if (key_code == W_KEY || key_code == UP_ARROW_KEY)
		ft_move_up(game);
    if (key_code == S_KEY || key_code == DOWN_ARROW_KEY)
		ft_move_down(game);
	if (key_code == A_KEY || key_code == LEFT_ARROW_KEY)
		ft_move_left(game);
	if (key_code == D_KEY || key_code == RIGHT_ARROW_KEY)
		ft_move_right(game);

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
    int	idx;
	int map_len;

	idx = 0;
	map_len = ft_strlen(game->map);
	/*
	at this point we should creat a game->map_len
	just after checking the validity of the map
	*/
	while (idx++ < map_len)
	{
		/*
		par quel magie on peux arriver la ?
		ft_check_playability already prevent it 
		*/
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
		ft_printf("step : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

void	ft_move_down(t_game *game)
{
	int	idx;
	int map_len;

	idx = 0;
	map_len = ft_strlen(game->map);
	while (idx++ < map_len)
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
		ft_printf("step : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

void	ft_move_left(t_game *game)
{
    int	idx;
	int map_len;

	idx = 0;
	map_len = ft_strlen(game->map);
	while (idx++ < map_len)
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
		ft_printf("step : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

void	ft_move_right(t_game *game)
{
    int	idx;
	int map_len;

	idx = 0;
	map_len = ft_strlen(game->map);
	while (idx++ < map_len)
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
		ft_printf("step : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}
