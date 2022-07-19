/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:34:07 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 00:55:24 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void display_life_on_windows(t_game *game)
{
    int idx;
    int	x;
	int	y;

    idx = 0;
    x = 5;
    y = 5;
    while (idx < game->player.life)
    {
        if (x > 500)
        {
            y = 15;
            x = 0;
        }
        mlx_put_image_to_window(game->mlx, game->win, game->love.icon, x, y);
        idx++;
        x += 15;
    }
    if (game->player.life == 0)
        ft_lose_game(game);
    //moving_lava(game);
}


/// make a fct that return a randon directon u d lr or a int

/*
void moving_lava(t_game *game)
{
    int random;

    srand(time(0));
    random = rand() % 4;
    if (random == 0)
        game->lava.move = 'u';
    if (random == 1)
        game->lava.move = 'd';
    if (random == 2)
        game->lava.move = 'l';
    if (random == 3)
        game->lava.move = 'r';

    int idx;

    idx = 0;
    game->lava.move = 'u';
    while (idx < game->map.len)
	{
		if (game->map.map_str[idx] == LAVA_CHAR)
			break ;
        if (game->lava.move == 'u')
        {
            if (game->map.map_str[idx - game->width] == VOID_CHAR)
            {
                game->map.map_str[idx - game->width] = LAVA_CHAR;
                //ft_put_sprites_by_line(game);
            }
        }
        idx++;
	}
}
&& game->map.map_str[idx - game->width] != EXIT_CHAR
        && game->map.map_str[idx - game->width] != LAVA_CHAR && game->map.map_str[idx - game->width] != LOVE_CHAR
        && game->map.map_str[idx - game->width] != KEY_CHAR

*/