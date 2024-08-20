/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_border_one_assets_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:59:18 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:41:36 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_tree_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"tree/tree_frame_0.xpm",
		PATH_ASSET"tree/tree_frame_1.xpm",
		PATH_ASSET"tree/tree_frame_2.xpm"};

	ft_load_animation_sprites(&(game->tree.animation), \
		game, paths, paths);
}

void	ft_load_trees_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"trees/trees_frame_0.xpm",
		PATH_ASSET"trees/trees_frame_1.xpm",
		PATH_ASSET"trees/trees_frame_2.xpm"};

	ft_load_animation_sprites(&(game->trees.animation), \
		game, paths, paths);
}

void	ft_load_reed_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"reed/reed_frame_0.xpm",
		PATH_ASSET"reed/reed_frame_1.xpm",
		PATH_ASSET"reed/reed_frame_2.xpm"};

	ft_load_animation_sprites(&(game->reed.animation), \
		game, paths, paths);
}

void	ft_load_husks_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"husks/husks_frame_0.xpm",
		PATH_ASSET"husks/husks_frame_1.xpm",
		PATH_ASSET"husks/husks_frame_2.xpm"};

	ft_load_animation_sprites(&(game->husks.animation), \
		game, paths, paths);
}

void	ft_load_fungus_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"fungus/fungus_frame_0.xpm",
		PATH_ASSET"fungus/fungus_frame_1.xpm",
		PATH_ASSET"fungus/fungus_frame_2.xpm"};

	ft_load_animation_sprites(&(game->fungus.animation), \
		game, paths, paths);
}
