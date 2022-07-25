/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_management_mac.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:34:07 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/25 17:08:01 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_mac/so_long_bonus_mac.h"
#include <time.h>

/**
 * @brief 
 * 
 * 	this fct simply display the number of life of the player
 * 		whe loop by the life.player.map, and print the small love.icon
 * 				10x10 at the x y and we also reset
 * 			the x position to 0 to print at the next line y
 * 
 * is not great display because for 100 life we dont manage to print all
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

/**
 * @brief 
 * 		
 * 		we simply generate a random int 
 * 			aka direction for the
 * 			ft_move_lava(game);
 * 			
 * 	no good place found stay here
 * 
 * sleep(1); dont work kinda wierd
 * 
 * @param game 
 */
void	ft_random_lava_move(t_game *game)
{
	int	random;

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
	ft_move_lava(game);
}
