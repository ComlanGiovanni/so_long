/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:41:41 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/18 15:48:14 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void    ft_print_map_better_format(t_game *game)
{
    int idx;
    int reset;

    idx = 0;
    reset = 1;
    while (idx < game->map_len)
    {
        if (game->map[idx])
            ft_printf("%c", game->map[idx]);
        if (reset == game->width)
        {
            ft_printf("\n");
            reset = 0;
        }
        idx++;
        reset++;
    }
}

void    ft_print_game_info(t_game *game, int key_code)
{
    ft_printf("----------------------------------\n");
    ft_printf("**********************************\n");
	ft_printf("* Key pressed : %d               *\n", key_code);
	ft_printf("* Life :                          *\n");
	ft_printf("* Remaining coin : 69             *\n");
	ft_printf("* Status : i or m                 *\n");
	ft_printf("* Number of Lava : 4              *\n");
	ft_printf("* Number of Ennemie : 2           *\n");
	ft_printf("* Storage : %d                    *\n", game->storage);
	ft_printf("* Map coin : %d                   *\n", game->coin);
	ft_printf("* Step counter : %d               *\n", game->step);
	ft_printf("* Facing : %c                     *\n", game->direction);
    ft_printf("**********************************\n");
	ft_printf("----------------------------------\n");
}

    /*
    hard code all direction fct ???? huuuuunnn
    hard ocde 4 state
    hard code print 4 direction
    */