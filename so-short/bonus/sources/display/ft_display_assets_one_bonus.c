/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_one_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:23:59 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:10:39 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_handle_exit_portals_sprites(t_game *game, char tile, \
	t_point sprite_position)
{
	if (tile == EXIT_CHAR)
	{
		if (game->player.storage == game->map.info.nbr_key)
			ft_put_sprite(game, game->door.open.current, sprite_position);
		else
			ft_exit_sprite(game, sprite_position);
	}
	else if (tile == PORTAL_1_CHAR)
		ft_portal_n_sprite(game, sprite_position);
	else if (tile == PORTAL_2_CHAR)
		ft_portal_z_sprite(game, sprite_position);
}

void	ft_handle_enemies_sprites(t_game *game, char tile, \
	t_point sprite_position)
{
	if (tile == LAVA_CHAR)
		ft_lava_sprite(game, sprite_position);
	else if (tile == PAWN_CHAR)
		ft_pawn_sprite(game, sprite_position);
}
