/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monster_a_star_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:45:24 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:46:06 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_check_neighbor_node(t_game *game, t_a_star_node *current, \
	t_point pos)
{
	t_a_star_node	*node;

	node = ft_init_create_neighbor_node(game, current, pos);
	if (!ft_check_if_point_is_in_list(game->monster.a_star.lists.open, \
		game->monster.a_star.lists.open_count, pos))
		ft_add_to_open_list(game->monster.a_star.lists.open, \
			&(game->monster.a_star.lists.open_count), node);
	else
		free(node);
}

void	ft_explore_neighbors_node(t_game *game, t_a_star_node *current)
{
	int		index;
	t_point	neighbor_pos;

	index = 0x0;
	while (index < FANTASTIC)
	{
		neighbor_pos = ft_get_neighbor_position(game, current, index);
		if (ft_node_is_valid_and_not_in_closed(game, neighbor_pos))
			ft_check_neighbor_node(game, current, neighbor_pos);
		index++;
	}
}

void	ft_process_a_star_node(t_game *game)
{
	t_a_star_node	*current;

	ft_sort_open_list(game->monster.a_star.lists.open, \
		game->monster.a_star.lists.open_count);
	current = game->monster.a_star.lists.open[0];
	ft_check_if_current_node_is_player_position(game, current);
	ft_remove_from_open_list(game->monster.a_star.lists.open, \
		&(game->monster.a_star.lists.open_count));
	game->monster.a_star.lists.closed[\
		game->monster.a_star.lists.closed_count++] = current;
	ft_explore_neighbors_node(game, current);
}
