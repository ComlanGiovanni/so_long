/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:32:20 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/03 22:34:20 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_check_coin_collected(t_game *game)
{
	if ((game->map.info.nbr_key == game->player.storage) \
		&& !game->key_collected)
	{
		game->key_collected = 1;
		system("paplay sounds/theme/all_key_collected.wav \
			> /dev/null 2>&1 &");
	}
}

void	ft_draw_pause_message(t_game *game)
{
	if (game->state == STATE_PAUSED)
		ft_display_string_sprites(game, "PAUSE", \
			game->hud.position.pause);
}

void	ft_update_map_matrice(t_game *game)
{
	if (game->map.matrice != NULL)
		ft_clean_grid_map(game->map.matrice, game->height);
	game->map.matrice = ft_split_map(game);
}

void	ft_update_player_position(t_game *game)
{
	game->player.movement.current_position.x = game->map.start.x;
	game->player.movement.current_position.y = game->map.start.y;
}

void	ft_update_map_positions(t_game *game)
{
	game->map.start = ft_find_pos_char(game->map.grid, \
		game->map.size, PLAYER_CHAR);
	game->map.end = ft_find_pos_char(game->map.grid, \
		game->map.size, EXIT_CHAR);
	game->map.portal_1_pos = ft_find_pos_char(game->map.grid, \
		game->map.size, PORTAL_1_CHAR);
	game->map.portal_2_pos = ft_find_pos_char(game->map.grid, \
		game->map.size, PORTAL_2_CHAR);
	if ((game->map.start.x == -1 && game->map.start.y == -1)
		|| (game->map.end.x == -1 && game->map.end.y == -1))
		ft_free_and_print(game->map.matrice, game, NO_POSITION_FOUND);
}
