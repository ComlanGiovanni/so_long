/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:01:54 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/13 03:32:27 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int     ft_input_manager()
{
	    //add fleche
	if (key == ESC )
		//exit the game;
	else if (key == W || key == w)
		ft_move_up();
    else if (key == S || key == s)
		ft_move_down();
	else if (key == A || key == a)
		ft_move_left();
	else if (key == D || key == d)
		ft_move_right();
    else
        /*iddle animation*/
	return (0);
}

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
		ft_printf("%d\n", game->step);
		//for bonus use mlx string pu with a special font ?
		ft_put_sprites_by_line(game);
	}
}

void	ft_move_left()
{
	int	idx;

	idx = 0;
    //print step_count;
}

void	ft_move_down()
{
	int	idx;

	idx = 0;
}

void	ft_move_right()
{
	int	idx;

	idx = 0;
    //print step_count;
}
