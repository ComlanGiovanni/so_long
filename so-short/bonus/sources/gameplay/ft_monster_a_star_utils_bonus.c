/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monster_a_star_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:45:21 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:48:55 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

t_point	ft_get_neighbor_position(t_game *game, t_a_star_node *current, \
	int index)
{
	return ((t_point){current->pos.x \
		+ game->monster.a_star.neighbor.directions[index].x, \
			current->pos.y + \
				game->monster.a_star.neighbor.directions[index].y});
}

t_bool	ft_node_is_valid_and_not_in_closed(t_game *game, t_point pos)
{
	return (ft_node_is_valid_neighbor(game, pos.x, pos.y) \
		&& !ft_check_if_point_is_in_list(game->monster.a_star.lists.closed, \
			game->monster.a_star.lists.closed_count, pos));
}

int	ft_is_monster_walkable_point(char **grid, int x, int y)
{
	return ((grid[y][x] != WALL_CHAR)
		&& (grid[y][x] != KEY_CHAR) && (grid[y][x] != LOVE_CHAR)
			&& (grid[y][x] != EXIT_CHAR) && (grid[y][x] != PORTAL_1_CHAR)
				&& (grid[y][x] != PORTAL_2_CHAR) && (grid[y][x] != LAVA_CHAR)
					&& (grid[y][x] != PAWN_CHAR));
}
