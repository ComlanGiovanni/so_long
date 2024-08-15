/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pawn_patrolling_utils_tree_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:48:11 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 14:36:01 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_check_valid_map_for_pawn_positions(t_game *game)
{
	if (!game \
		|| (game->map.grid == NULL) \
		|| (game->map.size.x <= 0x0) \
		|| (game->map.size.y <= 0x0))
		ft_print_error(PAWNS_POS_FAIL, game);
}

void	ft_check_row_for_pawn_positions(char *row, t_game *game)
{
	if (row == NULL)
		ft_print_error(PAWNS_ROW_NULL, game);
}

void	ft_update_pawn_grid(t_game *game, t_point old_position, \
	t_point new_position)
{
	game->map.grid[old_position.y][old_position.x] = VOID_CHAR;
	game->map.grid[new_position.y][new_position.x] = PAWN_CHAR;
}
