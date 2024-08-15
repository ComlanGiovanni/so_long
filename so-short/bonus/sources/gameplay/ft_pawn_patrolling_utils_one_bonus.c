/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pawn_patrolling_utils_one_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:18:34 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 15:13:19 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

t_point	ft_calculate_farthest_position(t_point start_position, \
	const char *direction, t_game *game)
{
	t_point	current_position;
	t_point	next_position;

	current_position = start_position;
	while (TRUE)
	{
		next_position = ft_get_pawn_next_position(current_position, direction);
		if (!ft_pawn_can_move_to_position(game, next_position))
			break ;
		current_position = next_position;
	}
	return (current_position);
}

size_t	ft_calculate_steps(t_point start, t_point end, const char *direction)
{
	if (ft_strcmp((char *)direction, UP_DIRECTION) == 0 \
		|| ft_strcmp((char *)direction, DOW_DIRECTION) == 0 \
		|| ft_strcmp((char *)direction, UP_LEFT_DIRECTION) == 0 \
		|| ft_strcmp((char *)direction, UP_RIGHT_DIRECTION) == 0)
		return (ft_absolute_value(end.y - start.y));
	return (ft_absolute_value(end.x - start.x));
}

t_point	ft_get_pawn_next_position(t_point current, const char *direction)
{
	t_point	delta;

	delta = ft_get_pawn_direction_delta(direction);
	current.x += delta.x;
	current.y += delta.y;
	return (current);
}

t_point	ft_get_pawn_direction_delta(const char *direction)
{
	static const t_direction_map	direction_map[] = {
	{DOW_DIRECTION, {0x0, 0x1}}, {LEFT_DIRECTION, {-1, 0x0}},
	{UP_DIRECTION, {0x0, -1}}, {RIGHT_DIRECTION, {0x1, 0x0}},
	{DOWN_RIGHT_DIRECTION, {1, 0x1}}, {DOWN_LEFT_DIRECTION, {-1, 0x1}},
	{UP_RIGHT_DIRECTION, {0x1, -1}}, {UP_LEFT_DIRECTION, {-1, -1}}
	};
	size_t							index;
	t_point							delta;

	index = 0x0;
	delta = (t_point){0x0, 0x0};
	while (index < sizeof(direction_map) / sizeof(direction_map[0]))
	{
		if (ft_strcmp((char *)direction, \
			(char *)direction_map[index].name) == 0x0)
		{
			delta = direction_map[index].delta;
			break ;
		}
		index++;
	}
	return (delta);
}

void	ft_find_best_direction_for_pawn(t_game *game, t_pawn_movement *pawn)
{
	const char				*dir_names[COMPASS] = {
		DOW_DIRECTION, DOWN_LEFT_DIRECTION, LEFT_DIRECTION, UP_LEFT_DIRECTION,
		UP_DIRECTION, UP_RIGHT_DIRECTION, RIGHT_DIRECTION, DOWN_RIGHT_DIRECTION
	};
	int						dir_index;
	t_direction_evaluation	eval;

	eval = (t_direction_evaluation){0x0, \
	pawn->current_position, dir_names[0x0]};
	dir_index = 0x0;
	while (dir_index < COMPASS)
	{
		ft_evaluate_pawn_direction(game, pawn, dir_names[dir_index], &eval);
		dir_index++;
	}
	ft_update_pawn_best_direction(pawn, &eval);
}
