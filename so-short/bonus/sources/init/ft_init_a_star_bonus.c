/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_a_star_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:46:58 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/19 19:12:52 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

t_a_star_node	*ft_init_monster_start_node(t_point start, t_point goal)
{
	t_a_star_node	*start_node;

	start_node = (t_a_star_node *)malloc(sizeof(t_a_star_node));
	if (!start_node)
		return (NULL);
	start_node->pos = start;
	start_node->cost_from_start = 0x0;
	start_node->total_cost = ft_manhattan_heuristic_distance(start, goal);
	start_node->parent = NULL;
	return (start_node);
}

t_a_star_node	*ft_init_create_neighbor_node(t_game *game, \
	t_a_star_node *current, t_point pos)
{
	t_a_star_node	*node;

	node = (t_a_star_node *)malloc(sizeof(t_a_star_node));
	if (!node)
		ft_print_error(NEIGHBOR_INIT_FAIL, game);
	node->pos = pos;
	node->cost_from_start = current->cost_from_start + 0x1;
	node->total_cost = node->cost_from_start \
		+ ft_manhattan_heuristic_distance(pos, \
			game->monster.a_star.neighbor.goal);
	node->parent = current;
	return (node);
}

void	ft_init_neighbor_data(t_game *game, t_point goal)
{
	game->monster.a_star.neighbor.goal = goal;
	game->monster.a_star.neighbor.directions[0x0] = (t_point){0x0, -1};
	game->monster.a_star.neighbor.directions[0x1] = (t_point){0x0, 0x1};
	game->monster.a_star.neighbor.directions[0x2] = (t_point){-1, 0x0};
	game->monster.a_star.neighbor.directions[0x3] = (t_point){1, 0x0};
	game->monster.a_star.neighbor.dir_char[0x0] = 'u';
	game->monster.a_star.neighbor.dir_char[0x1] = 'd';
	game->monster.a_star.neighbor.dir_char[0x2] = 'l';
	game->monster.a_star.neighbor.dir_char[0x3] = 'r';
}

void	ft_init_a_star_lists(t_game *game)
{
	game->monster.a_star.lists.open_count = 0x0;
	game->monster.a_star.lists.closed_count = 0x0;
	game->monster.a_star.lists.open = (t_a_star_node **)malloc(game->map.len \
		* sizeof(t_a_star_node *));
	game->monster.a_star.lists.closed = (t_a_star_node **)malloc(game->map.len \
		* sizeof(t_a_star_node *));
	if (!game->monster.a_star.lists.open || !game->monster.a_star.lists.closed)
		ft_print_error(A_STAR_LIST_FAIL, game);
}

void	ft_init_a_star_data(t_game *game, t_point *start, \
	t_point *goal, t_a_star_node **start_node)
{
	*start = ft_find_pos_char(game->map.grid, game->map.size, MONSTER_CHAR);
	*goal = game->player.movement.current_position;
	*start_node = ft_init_monster_start_node(*start, *goal);
	if (!*start_node)
		ft_print_error(NODE_INIT_FAIL, game);
	ft_init_a_star_lists(game);
	ft_add_to_open_list(game->monster.a_star.lists.open, \
		&(game->monster.a_star.lists.open_count), *start_node);
	ft_init_neighbor_data(game, *goal);
}
