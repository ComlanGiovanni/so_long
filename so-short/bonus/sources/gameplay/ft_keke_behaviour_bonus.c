/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keke_behaviour_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:25 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 02:20:28 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_direction_keke_after_launch(t_game *game)
{
	static int	random;

	srand((unsigned int)time(NULL));
	random = rand() % 4;
	if (random == 0x0)
		game->keke.direction = 'u';
	if (random == 0x1)
		game->keke.direction = 'd';
	if (random == 0x2)
		game->keke.direction = 'l';
	if (random == 0x3)
		game->keke.direction = 'r';
}

int	ft_is_keke_obstacle(char tile)
{
	return (tile == WALL_CHAR || tile == EXIT_CHAR || tile == KEY_CHAR \
		|| tile == KEKE_CHAR || tile == LOVE_CHAR || tile == PORTAL_1_CHAR \
		|| tile == PORTAL_2_CHAR || tile == LAVA_CHAR);
}
