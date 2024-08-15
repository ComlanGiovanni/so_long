/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pawn_patrolling_utils_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:18:36 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 14:40:02 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	ft_is_pawn_position_valid(t_game *game, t_point pos, t_pawn_movement *pawn)
{
	return (!((pos.x < 0x0) || (pos.x >= game->map.size.x) || (pos.y < 0x0) \
		|| (pos.y >= game->map.size.y) \
		|| !ft_is_position_free_for_pawn(game->map.grid, pos) \
		|| ft_absolute_value(pos.x - pawn->initial_position.x) \
		> pawn->steps_need || ft_absolute_value(pos.y \
		- pawn->initial_position.y) > pawn->steps_need));
}

int	ft_is_position_free_for_pawn(char **grid, t_point pos)
{
	return ((grid[pos.y][pos.x] == VOID_CHAR) \
		| (grid[pos.y][pos.x] == PLAYER_CHAR));
}

int	ft_is_pawn_obstacle(char **grid, t_point pos)
{
	return (grid[pos.y][pos.x] != VOID_CHAR \
		&& grid[pos.y][pos.x] != PLAYER_CHAR);
}

t_bool	ft_is_position_within_bounds_for_pawn(t_point pos, t_point size)
{
	return ((pos.x >= 0x0) \
		&& (pos.x < size.x) \
		&& (pos.y >= 0x0) \
		&& (pos.y < size.y));
}

t_bool	ft_pawn_can_move_to_position(t_game *game, t_point pos)
{
	return (ft_is_position_within_bounds_for_pawn(pos, game->map.size) \
		&& ft_is_position_free_for_pawn(game->map.grid, pos));
}
