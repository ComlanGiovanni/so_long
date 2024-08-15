/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:14:26 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:09:12 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

t_bool	ft_is_key_love_box_sprites(char tile)
{
	return ((tile == KEY_CHAR) || (tile == LOVE_CHAR) || (tile == BOX_CHAR));
}

t_bool	ft_is_exit_portals_sprites(char tile)
{
	return ((tile == EXIT_CHAR) || (tile == PORTAL_1_CHAR) \
		|| tile == (PORTAL_2_CHAR));
}

t_bool	ft_is_enemies_sprites(char tile)
{
	return ((tile == LAVA_CHAR) || (tile == PAWN_CHAR));
}

t_bool	ft_is_borders_sprites(char tile)
{
	return ((tile == GRASS_CHAR) || (tile == TREE_CHAR) \
		|| (tile == TREES_CHAR) || (tile == REED_CHAR) \
		|| (tile == HUSKS_CHAR) || (tile == FUNGUS_CHAR) \
		|| (tile == FUNGI_CHAR) || (tile == FLOWER_CHAR) \
		|| (tile == ALGAE_CHAR) || (tile == WATER_CHAR));
}

t_bool	ft_is_other_borders_sprites(char tile)
{
	return ((tile == CRAB_CHAR) || (tile == FOLIAGE_CHAR) \
		|| (tile == BOG_CHAR) || (tile == SNAIL_CHAR) \
		|| (tile == PILLAR_CHAR) || (tile == HEDGE_CHAR));
}
