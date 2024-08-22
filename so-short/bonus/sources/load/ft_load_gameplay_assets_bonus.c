/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_gameplay_assets_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:17:02 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 16:27:49 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_lava_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"lava/lava_frame_0.xpm",
		PATH_ASSET"lava/lava_frame_1.xpm",
		PATH_ASSET"lava/lava_frame_2.xpm"};

	ft_load_animation_sprites(&(game->lava.animation), \
		game, paths, paths);
}

void	ft_load_key_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"key/key_frame_0.xpm",
		PATH_ASSET"key/key_frame_1.xpm",
		PATH_ASSET"key/key_frame_2.xpm"};

	ft_load_animation_sprites(&(game->key.animation), \
		game, paths, paths);
}

void	ft_load_love_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"love/love_frame_0.xpm",
		PATH_ASSET"love/love_frame_1.xpm",
		PATH_ASSET"love/love_frame_2.xpm"};

	ft_load_animation_sprites(&(game->love.animation), \
		game, paths, paths);
	ft_load_sprite_frame(&(game->love.nope), game,
		PATH_ASSET"love/love_frame_nope.xpm",
		PATH_ASSET"love/love_frame_nope.xpm");
}

void	ft_load_love_icon_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"love/icon/love_icon_yes_frame_0.xpm",
		PATH_ASSET"love/icon/love_icon_yes_frame_1.xpm",
		PATH_ASSET"love/icon/love_icon_yes_frame_2.xpm"};

	ft_load_animation_sprites(&(game->love.icon.animation), \
		game, paths, paths);
}

void	ft_load_box_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"box/box_frame_0.xpm",
		PATH_ASSET"box/box_frame_1.xpm",
		PATH_ASSET"box/box_frame_2.xpm"};

	ft_load_animation_sprites(&(game->box.animation), \
		game, paths, paths);
}
