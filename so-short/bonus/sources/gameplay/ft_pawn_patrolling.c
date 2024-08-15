/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pawn_patrolling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:58:49 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 15:13:21 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_move_pawn(t_game *game)
{
	int				index;
	t_pawn_movement	*pawn;

	index = 0x0;
	while (index < game->map.info.nbr_pawn)
	{
		pawn = &game->pawn.pawns_array[index];
		if (pawn->is_returning)
			ft_handle_pawn_returning(game, pawn);
		else
			ft_handle_pawn_movement(game, pawn);
		index++;
	}
}

t_bool	ft_handle_pawn_collision(t_game *game, \
	t_pawn_movement *pawn, t_point next_pos)
{
	if (game->map.grid[next_pos.y][next_pos.x] == PLAYER_CHAR)
	{
		game->map.grid[pawn->current_position.y][pawn->current_position.x] \
			= VOID_CHAR;
		ft_player_get_hit(game);
		pawn->is_active = FALSE;
		pawn->is_available = FALSE;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_handle_pawn_returning(t_game *game, t_pawn_movement *pawn)
{
	const char	*reverse_direction = \
		ft_get_pawn_reverse_direction(pawn->direction);
	t_point		next_pos;

	if (!pawn->is_active)
		return ;
	next_pos = ft_get_pawn_next_position(pawn->current_position, \
			reverse_direction);
	if (ft_handle_pawn_collision(game, pawn, next_pos))
		return ;
	if (!ft_is_pawn_position_valid(game, next_pos, pawn) \
		|| (pawn->current_position.x == pawn->initial_position.x
			&& pawn->current_position.y == pawn->initial_position.y))
		pawn->is_returning = FALSE;
	else
	{
		ft_update_pawn_grid(game, pawn->current_position, next_pos);
		pawn->current_position = next_pos;
	}
}

void	ft_handle_pawn_movement(t_game *game, t_pawn_movement *pawn)
{
	t_point	next_pos;

	if (!pawn->is_active)
		return ;
	next_pos = ft_get_pawn_next_position(pawn->current_position, \
		pawn->direction);
	if (ft_handle_pawn_collision(game, pawn, next_pos))
		return ;
	if (!ft_is_pawn_position_valid(game, next_pos, pawn))
		pawn->is_returning = TRUE;
	else
	{
		ft_update_pawn_grid(game, pawn->current_position, next_pos);
		pawn->current_position = next_pos;
		if (pawn->current_position.x == pawn->target_position.x
			&& pawn->current_position.y == pawn->target_position.y)
			pawn->is_returning = TRUE;
	}
}

const char	*ft_get_pawn_reverse_direction(const char *direction)
{
	if (ft_strcmp((char *)direction, DOW_DIRECTION) == 0x0)
		return (UP_DIRECTION);
	else if (ft_strcmp((char *)direction, LEFT_DIRECTION) == 0x0)
		return (RIGHT_DIRECTION);
	else if (ft_strcmp((char *)direction, UP_DIRECTION) == 0x0)
		return (DOW_DIRECTION);
	else if (ft_strcmp((char *)direction, RIGHT_DIRECTION) == 0x0)
		return (LEFT_DIRECTION);
	else if (ft_strcmp((char *)direction, DOWN_RIGHT_DIRECTION) == 0x0)
		return (UP_LEFT_DIRECTION);
	else if (ft_strcmp((char *)direction, DOWN_LEFT_DIRECTION) == 0x0)
		return (UP_RIGHT_DIRECTION);
	else if (ft_strcmp((char *)direction, UP_RIGHT_DIRECTION) == 0x0)
		return (DOWN_LEFT_DIRECTION);
	else if (ft_strcmp((char *)direction, UP_LEFT_DIRECTION) == 0x0)
		return (DOWN_RIGHT_DIRECTION);
	return (direction);
}
