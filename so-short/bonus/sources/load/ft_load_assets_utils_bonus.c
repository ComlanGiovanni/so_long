/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:03:03 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 16:29:30 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_player_sprites(t_game *game)
{
	ft_load_player_up_sprites(game);
	ft_load_player_down_sprites(game);
	ft_load_player_left_sprites(game);
	ft_load_player_right_sprites(game);
	ft_load_player_current(game);
}

void	ft_load_monster_sprites(t_game *game)
{
	ft_load_monster_up_sprites(game);
	ft_load_monster_down_sprites(game);
	ft_load_monster_left_sprites(game);
	ft_load_monster_right_sprites(game);
	ft_load_monster_current(game);
}

void	ft_load_gameplay_sprites(t_game *game)
{
	ft_load_love_sprites(game);
	ft_load_love_icon_sprites(game);
	ft_load_key_sprites(game);
	ft_load_portal_n_sprites(game);
	ft_load_portal_z_sprites(game);
	ft_load_door_closed_sprites(game);
	ft_load_door_open_sprites(game);
}

void	ft_load_enemies_sprites(t_game *game)
{
	ft_load_lava_sprites(game);
	ft_load_pawn_sprites(game);
}

void	ft_load_borders_sprite(t_game *game)
{
	ft_load_grass_sprites(game);
	ft_load_tree_sprites(game);
	ft_load_trees_sprites(game);
	ft_load_reed_sprites(game);
	ft_load_husks_sprites(game);
	ft_load_fungus_sprites(game);
	ft_load_fungi_sprites(game);
	ft_load_flower_sprites(game);
	ft_load_algae_sprites(game);
	ft_load_water_sprites(game);
	ft_load_crab_sprites(game);
	ft_load_foliage_sprites(game);
	ft_load_bog_sprites(game);
	ft_load_snail_sprites(game);
	ft_load_pillar_sprites(game);
	ft_load_hedge_sprites(game);
}
