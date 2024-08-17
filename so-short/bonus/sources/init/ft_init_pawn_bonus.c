/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pawn_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:25:44 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/17 02:58:15 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_pawns_array(t_game *game)
{
	game->pawn.pawns_array = (t_pawn_movement *)malloc(game->map.info.nbr_pawn \
			* sizeof(t_pawn_movement));
	if (!game->pawn.pawns_array)
		ft_print_error(PAWNS_MALLOC_FAIL, game);
	ft_find_pawn_positions(game);
	ft_find_farthest_position_for_pawn(game);
}

void	ft_initialize_pawn(t_game *game, long long int index, int x, int y)
{
	if (index >= game->map.info.nbr_pawn)
		ft_print_error(HOW_IS_POSSIBLE, game);
	game->pawn.pawns_array[index].initial_position = (t_point){x, y};
	game->pawn.pawns_array[index].current_position = (t_point){x, y};
	game->pawn.pawns_array[index].target_position = (t_point){x, y};
	game->pawn.pawns_array[index].direction = " ";
	game->pawn.pawns_array[index].is_returning = FALSE;
	game->pawn.pawns_array[index].is_active = TRUE;
	game->pawn.pawns_array[index].is_available = TRUE;
	game->pawn.pawns_array[index].steps_taken = 0x0;
	game->pawn.pawns_array[index].steps_need = 0x0;
}
