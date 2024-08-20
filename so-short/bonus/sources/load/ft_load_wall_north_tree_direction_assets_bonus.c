/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_wall_north_tree_direction_assets_bo        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:04:49 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:33:35 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_wall_north_plus_west_plus_east_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/north_plus_west_plus_east/"
		"wall_north_plus_west_plus_east_frame_0.xpm",
		PATH_ASSET"wall/north_plus_west_plus_east/"
		"wall_north_plus_west_plus_east_frame_1.xpm",
		PATH_ASSET"wall/north_plus_west_plus_east/"
		"wall_north_plus_west_plus_east_frame_2.xpm"};

	ft_load_animation_sprites(&(game->wall.north_plus_west_plus_east), \
		game, paths, paths);
}

void	ft_load_wall_north_plus_south_plus_west_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/north_plus_south_plus_west/"
		"wall_north_plus_south_plus_west_frame_0.xpm",
		PATH_ASSET"wall/north_plus_south_plus_west/"
		"wall_north_plus_south_plus_west_frame_1.xpm",
		PATH_ASSET"wall/north_plus_south_plus_west/"
		"wall_north_plus_south_plus_west_frame_2.xpm"};

	ft_load_animation_sprites(&(game->wall.north_plus_south_plus_west), \
		game, paths, paths);
}

void	ft_load_wall_north_plus_south_plus_east_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/north_plus_south_plus_east/"
		"wall_north_plus_south_plus_east_frame_0.xpm",
		PATH_ASSET"wall/north_plus_south_plus_east/"
		"wall_north_plus_south_plus_east_frame_1.xpm",
		PATH_ASSET"wall/north_plus_south_plus_east/"
		"wall_north_plus_south_plus_east_frame_2.xpm"};

	ft_load_animation_sprites(&(game->wall.north_plus_south_plus_east), \
		game, paths, paths);
}
