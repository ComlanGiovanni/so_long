/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_border_tree_assets_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:00:06 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:42:28 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_foliage_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"foliage/foliage_frame_0.xpm",
		PATH_ASSET"foliage/foliage_frame_1.xpm",
		PATH_ASSET"foliage/foliage_frame_2.xpm"};

	ft_load_animation_sprites(&(game->foliage.animation), \
		game, paths, paths);
}

void	ft_load_bog_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"bog/bog_frame_0.xpm",
		PATH_ASSET"bog/bog_frame_1.xpm",
		PATH_ASSET"bog/bog_frame_2.xpm"};

	ft_load_animation_sprites(&(game->bog.animation), \
		game, paths, paths);
}

void	ft_load_snail_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"snail/snail_frame_0.xpm",
		PATH_ASSET"snail/snail_frame_1.xpm",
		PATH_ASSET"snail/snail_frame_2.xpm"};

	ft_load_animation_sprites(&(game->snail.animation), \
		game, paths, paths);
}

void	ft_load_pillar_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"pillar/pillar_frame_0.xpm",
		PATH_ASSET"pillar/pillar_frame_1.xpm",
		PATH_ASSET"pillar/pillar_frame_2.xpm"};

	ft_load_animation_sprites(&(game->pillar.animation), \
		game, paths, paths);
}
