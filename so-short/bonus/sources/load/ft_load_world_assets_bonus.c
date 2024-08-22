/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_world_assets_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:12:28 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 14:21:27 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//macro file ?
void	ft_load_ground_sprites(t_game *game)
{
	ft_load_sprite_frame(&(game->map.ground), \
		game, PATH_ASSET"ground/ground.xpm", "paths[0]");
}

void	ft_load_grass_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"grass/grass_frame_0.xpm",
		PATH_ASSET"grass/grass_frame_1.xpm",
		PATH_ASSET"grass/grass_frame_2.xpm"};

	ft_load_animation_sprites(&(game->grass.animation), \
	game, paths, paths);
}

void	ft_load_pawn_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"pawn/pawn_frame_0.xpm",
		PATH_ASSET"pawn/pawn_frame_1.xpm",
		PATH_ASSET"pawn/pawn_frame_2.xpm"};

	ft_load_animation_sprites(&(game->pawn.animation), \
		game, paths, paths);
}
