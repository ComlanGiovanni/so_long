/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:59:15 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/19 20:19:51 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// game->map.info.nbr_grass = (game->map.size.x * game->map.size.y)
// 	- game->map.len;
void	ft_setup_map(t_game *game)
{
	ft_printf(GRID_SIZE_PRINT"\t[%d %d]\n", \
		game->map.size.x, game->map.size.y);
	ft_print_initial_positions(game);
	ft_update_map_matrice(game);
	ft_print_display_grid(game->map.matrice);
	game->map.grid = ft_create_map_with_border(game);
	ft_printf(NEW_GRID_MSG);
	ft_print_display_grid(game->map.grid);
	ft_update_map_positions(game);
	ft_printf(GRID_SIZE_PRINT"\t[%d %d]\n", \
		game->map.size.x, game->map.size.y);
	ft_display_position(game->map.start, game->map.end,
		game->map.portal_1_pos, game->map.portal_2_pos);
	ft_update_player_position(game);
	ft_init_pawns_array(game);
}

void	ft_play_random_theme(void)
{
	static int	random;

	srand((unsigned int)time(NULL));
	random = rand() % 0x4;
	if (random == 0x0)
		system("aplay sounds/theme/baba_is_you_on_the_island.wav \
			> /dev/null 2>&1 &");
	if (random == 1)
		system("aplay sounds/theme/baba_is_you_theme.wav \
			> /dev/null 2>&1 &");
	if (random == 2)
		system("aplay sounds/theme/baba_is_you_water_is_sink_the_lake.wav \
			> /dev/null 2>&1 &");
	if (random == 3)
		system("aplay \
			sounds/theme/baba_is_you_crystal_is_still_crystal_cave.wav \
			> /dev/null 2>&1 &");
}
