/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pawn_patrolling_utils_two_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:43:15 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 14:18:27 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_update_pawn_target(t_pawn_movement *pawn, t_point best_position, \
	const char *best_dir, size_t max_steps)
{
	pawn->target_position = best_position;
	pawn->direction = (char *)best_dir;
	pawn->steps_need = max_steps;
}

void	ft_find_farthest_position_for_pawn(t_game *game)
{
	int	index;

	index = 0x0;
	while (index < game->map.info.nbr_pawn)
	{
		ft_find_best_direction_for_pawn(game, &game->pawn.pawns_array[index]);
		ft_print_pawn_info(index, &game->pawn.pawns_array[index]);
		index++;
	}
}

void	ft_update_pawn_best_direction(t_pawn_movement *pawn, \
	t_direction_evaluation *eval)
{
	pawn->target_position = eval->best_position;
	pawn->direction = (char *)eval->best_dir;
	pawn->steps_need = eval->max_steps;
}

void	ft_evaluate_pawn_direction(t_game *game, t_pawn_movement *pawn, \
	const char *direction, t_direction_evaluation *eval)
{
	t_point	temp_farthest_position;
	size_t	steps;

	temp_farthest_position = \
		ft_calculate_farthest_position(pawn->current_position, \
			direction, game);
	steps = \
		ft_calculate_steps(pawn->current_position, \
			temp_farthest_position, direction);
	if (steps > eval->max_steps)
	{
		eval->max_steps = steps;
		eval->best_position = temp_farthest_position;
		eval->best_dir = direction;
	}
}

void	ft_find_pawn_positions(t_game *game)
{
	long long int	index;
	t_point			position;

	index = 0x0;
	ft_check_valid_map_for_pawn_positions(game);
	position.y = 0x0;
	while (position.y < game->map.size.y)
	{
		ft_check_row_for_pawn_positions(game->map.grid[position.y], game);
		position.x = 0x0;
		while (position.x < game->map.size.x)
		{
			if (game->map.grid[position.y][position.x] == '\0')
				break ;
			if (game->map.grid[position.y][position.x] == PAWN_CHAR)
				ft_initialize_pawn(game, index++, position.x, position.y);
			position.x++;
		}
		position.y++;
	}
	if (index < game->map.info.nbr_pawn)
		ft_print_error(NO_PAWNS_FOUND, game);
}
