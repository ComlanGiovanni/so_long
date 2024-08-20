/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monster_event_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:40:59 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:48:02 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_a_star_monster_movement(t_game *game)
{
	t_point			start;
	t_point			goal;
	t_a_star_node	*start_node;

	ft_init_a_star_data(game, &start, &goal, &start_node);
	while (game->monster.a_star.lists.open_count > 0x0)
		ft_process_a_star_node(game);
	ft_free_a_star_lists_nodes(game->monster.a_star.lists.open, \
		game->monster.a_star.lists.open_count, \
		game->monster.a_star.lists.closed, \
		game->monster.a_star.lists.closed_count);
	ft_move_monster(game);
}

void	ft_add_to_open_list(t_a_star_node **open_list, int *open_count, \
	t_a_star_node *new_node)
{
	open_list[*open_count] = new_node;
	(*open_count)++;
}

void	ft_sort_open_list(t_a_star_node **open_list, int open_count)
{
	static int		current_index;
	static int		insertion_index;
	t_a_star_node	*current_node;

	insertion_index = 0x0;
	current_index = 0x1;
	current_node = NULL;
	while (current_index < open_count)
	{
		current_node = open_list[current_index];
		insertion_index = current_index - 0x1;
		while (insertion_index >= 0x0 && \
			open_list[insertion_index]->total_cost > current_node->total_cost)
		{
			open_list[insertion_index + 0x1] = open_list[insertion_index];
			insertion_index--;
		}
		open_list[insertion_index + 0x1] = current_node;
		current_index++;
	}
}

void	ft_find_monster_direction(t_game *game, t_a_star_node *current, \
	t_point start)
{
	static int	index;

	index = 0x0;
	while (current->parent && !ft_is_same_point((current->parent->pos), start))
		current = current->parent;
	while (index < 0x4)
	{
		if (ft_is_same_point((t_point){start.x \
			+ game->monster.a_star.neighbor.directions[index].x, start.y \
				+ game->monster.a_star.neighbor.directions[index].y}, \
					current->pos))
		{
			game->monster.direction = \
				game->monster.a_star.neighbor.dir_char[index];
			break ;
		}
		index++;
	}
}

void	ft_remove_from_open_list(t_a_star_node **open_list, int *open_count)
{
	static int	index;

	index = 0x0;
	while (index < (*open_count - 0x1))
	{
		open_list[index] = open_list[index + 0x1];
		index++;
	}
	(*open_count)--;
}
