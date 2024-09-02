/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monster_behaviour_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:25 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/26 23:36:39 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_direction_monster_after_launch(t_game *game)
{
	static int	random;

	srand((unsigned int)time(NULL));
	random = rand() % 4;
	if (random == 0x0)
		game->monster.direction = 'u';
	if (random == 0x1)
		game->monster.direction = 'd';
	if (random == 0x2)
		game->monster.direction = 'l';
	if (random == 0x3)
		game->monster.direction = 'r';
}

int	ft_is_monster_obstacle(char tile)
{
	return (tile == WALL_CHAR || tile == EXIT_CHAR || tile == KEY_CHAR \
		|| tile == MONSTER_CHAR || tile == LOVE_CHAR || tile == PORTAL_1_CHAR \
		|| tile == PORTAL_2_CHAR || tile == LAVA_CHAR || tile == PAWN_CHAR);
}
