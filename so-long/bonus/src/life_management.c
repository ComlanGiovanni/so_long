/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:34:07 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 13:44:10 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	ft_display_life_on_windows(t_game *game)
{
	int	idx;
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
}
