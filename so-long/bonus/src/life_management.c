/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:34:07 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/22 04:40:45 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

/**
 * @brief 
 * 
 * 	this fct simply display the number of life of the player
 * 		whe loop by the life.player.map, and print the small love.icon
 * 				10x10 at the x y and we also reset
 * 			the x position to 0 to print at the next line y
 * 
 * is not the greated display because for 100 life we dont manage to print all
 * 		for DLC we can stack every heath
 * 
 * @param game 
 */
void	ft_display_life_on_windows(t_game *game)
{
	int	idx;
	int	x;
	int	y;

	idx = FALSE;
	x = 5;
	y = 5;
	while (idx < game->player.life)
	{
		if (x > 500)
		{
			y = 15;
			x = FALSE;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->love.icon, x, y);
		idx++;
		x += 15;
	}
	if (game->player.life == FALSE)
		ft_lose_game(game);
}
