/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_border_two_assets_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:59:20 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:42:09 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_fungi_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"fungi/fungi_frame_0.xpm",
		PATH_ASSET"fungi/fungi_frame_1.xpm",
		PATH_ASSET"fungi/fungi_frame_2.xpm"};

	ft_load_animation_sprites(&(game->fungi.animation), \
		game, paths, paths);
}

void	ft_load_flower_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"flower/flower_frame_0.xpm",
		PATH_ASSET"flower/flower_frame_1.xpm",
		PATH_ASSET"flower/flower_frame_2.xpm"};

	ft_load_animation_sprites(&(game->flower.animation), \
		game, paths, paths);
}

void	ft_load_algae_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"algae/algae_frame_0.xpm",
		PATH_ASSET"algae/algae_frame_1.xpm",
		PATH_ASSET"algae/algae_frame_2.xpm"};

	ft_load_animation_sprites(&(game->algae.animation), \
		game, paths, paths);
}

void	ft_load_water_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"water/water_frame_0.xpm",
		PATH_ASSET"water/water_frame_1.xpm",
		PATH_ASSET"water/water_frame_2.xpm"};

	ft_load_animation_sprites(&(game->water.animation), \
		game, paths, paths);
}

void	ft_load_crab_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"crab/crab_frame_0.xpm",
		PATH_ASSET"crab/crab_frame_1.xpm",
		PATH_ASSET"crab/crab_frame_2.xpm"};

	ft_load_animation_sprites(&(game->crab.animation), \
		game, paths, paths);
}
