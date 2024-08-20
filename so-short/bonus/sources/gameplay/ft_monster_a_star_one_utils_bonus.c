/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monster_a_star_one_utils_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:57:36 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:46:11 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

t_bool	ft_check_if_point_is_in_list(t_a_star_node **list, \
	int count, t_point pos)
{
	static int	index;

	index = 0x0;
	while (index < count)
	{
		if (ft_is_same_point((list[index]->pos), pos))
			return (TRUE);
		index++;
	}
	return (FALSE);
}

int	ft_node_is_valid_neighbor(t_game *game, int x, int y)
{
	return ((x >= 0x0) && (y >= 0x0) && (x < game->width) \
		&& (y < game->height) \
			&& ft_is_monster_walkable_point(game->map.grid, x, y));
}

void	ft_check_if_current_node_is_player_position(t_game *game, \
	t_a_star_node *current)
{
	t_point	start;

	start = ft_find_pos_char(game->map.grid, game->map.size, MONSTER_CHAR);
	if (ft_is_same_point(current->pos, game->player.movement.current_position))
		ft_find_monster_direction(game, current, start);
}
