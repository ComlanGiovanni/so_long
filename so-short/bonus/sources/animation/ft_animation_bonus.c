/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:10:53 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:26:26 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_play_animation(t_game *game)
{
	ft_pawn_animation(&game->pawn.animation);
	ft_player_animation(&game->player);
	ft_monster_animation(&game->monster);
	ft_lava_animation(&game->lava.animation);
	ft_key_animation(&game->key.animation);
	ft_box_animation(&game->box.animation);
	ft_portal_n_animation(&game->portal.n);
	ft_portal_z_animation(&game->portal.z);
	ft_door_open_animation(&game->door.open);
	ft_door_closed_animation(&game->door.closed);
	ft_borders_animation(game);
	ft_life_management(game);
	ft_love_icon_animation(&game->love.icon.animation);
	ft_digits_animation(game);
	ft_alphabet_animation(game);
	ft_wall_animation(game);
}
