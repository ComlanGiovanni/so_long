/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:01:54 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/15 02:14:48 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	if (game->map[idx - game->width] == EXIT_CHAR  && game->storage == game->coin)
		ft_win_game(game);//for bonus call next stage
	else if (game->map[idx - game->width] != WALL_CHAR && game->map[idx - game->width] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx - game->width] = PLAYER_CHAR;
		game->step++;
		game->direction = 'u';
		//ft_printf("%d\n", game->step);
		//for bonus use mlx string pu with a special font ?
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
	if (game->map[idx + game->width] == EXIT_CHAR && game->storage == game->coin)
		ft_win_game(game);////for bonus call next stage
	else if (game->map[idx + game->width] != WALL_CHAR && game->map[idx + game->width] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx + game->width] = PLAYER_CHAR;
		game->step++;
		game->direction = 'd';
		//ft_printf("%d\n", game->step);
		//for bonus use mlx string pu with a special font ?
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
		ft_win_game(game);////for bonus call next stage
	else if (game->map[idx - 1] != WALL_CHAR && game->map[idx - 1] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx - 1] = PLAYER_CHAR;
		game->step++;
		game->direction = 'l';
		//ft_printf("step : %d\n", game->step);
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
	if (game->map[idx + game->width] == COIN_CHAR)
		game->storage++;
	if (game->map[idx + game->width] == EXIT_CHAR && game->storage == game->coin)
		ft_win_game(game);////for bonus call next stage
	else if (game->map[idx + 1] != WALL_CHAR && game->map[idx + 1] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx + 1] = PLAYER_CHAR;
		game->step++;
		game->direction = 'r';
		//ft_printf("%d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}
