/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_player_gameplay_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:53:39 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/25 00:46:17 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

t_bool	ft_play_can_move_to_tile(t_game *game, char next_tile)
{
	if (next_tile == LOVE_CHAR && game->player.life >= PLAYER_MAX_LIFE)
	{
		ft_baba_forbidden(game);
		return (FALSE);
	}
	return (next_tile != WALL_CHAR && next_tile != BOX_CHAR
		&& !(next_tile == EXIT_CHAR
			&& game->map.info.nbr_key != game->player.storage));
}

// Helper function to handle teleportation
t_bool	ft_handle_teleport(t_game *game, t_point next_position, char next_tile)
{
	if (next_tile == 'N' || next_tile == 'Z')
	{
		game->map.grid[game->player.movement.current_position.y] \
			[game->player.movement.current_position.x] = VOID_CHAR;
		ft_teleport_player(game, next_position.y, next_position.x);
		return (TRUE);
	}
	return (FALSE);
}

// Helper function to handle moving boxes
void	ft_handle_box_movement(t_game *game, t_point next_position, \
	char *next_tile)
{
	if (*next_tile == BOX_CHAR)
	{
		ft_move_box(game, next_position, next_position.y
			- game->player.movement.current_position.y, next_position.x
			- game->player.movement.current_position.x);
		*next_tile = game->map.grid[next_position.y][next_position.x];
	}
}

void	ft_deactivate_pawn_at_position(t_game *game, t_point next_position)
{
	int				index;
	t_pawn_movement	*pawn;

	index = 0x0;
	while (index < game->map.info.nbr_pawn)
	{
		pawn = &game->pawn.pawns_array[index];
		if (pawn->current_position.x == next_position.x \
			&& pawn->current_position.y == next_position.y)
		{
			ft_player_get_hit(game);
			pawn->is_active = FALSE;
			break ;
		}
		index++;
	}
}
