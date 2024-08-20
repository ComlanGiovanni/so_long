/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_wall_north_direction_assets_bonus.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:59:48 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:47:04 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_wall_north_plus_south_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/north_plus_south/wall_north_plus_south_frame_0.xpm",
		PATH_ASSET"wall/north_plus_south/wall_north_plus_south_frame_1.xpm",
		PATH_ASSET"wall/north_plus_south/wall_north_plus_south_frame_2.xpm"};

	ft_load_animation_sprites(&(game->wall.north_plus_south), \
		game, paths, paths);
}

void	ft_load_wall_north_west_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/north_west/wall_north_west_frame_0.xpm",
		PATH_ASSET"wall/north_west/wall_north_west_frame_1.xpm",
		PATH_ASSET"wall/north_west/wall_north_west_frame_2.xpm"};

	ft_load_animation_sprites(&(game->wall.north_west), \
		game, paths, paths);
}

void	ft_load_wall_north_plus_east_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/north_plus_east/wall_north_plus_east_frame_0.xpm",
		PATH_ASSET"wall/north_plus_east/wall_north_plus_east_frame_1.xpm",
		PATH_ASSET"wall/north_plus_east/wall_north_plus_east_frame_2.xpm"};

	ft_load_animation_sprites(&(game->wall.north_plus_east), \
		game, paths, paths);
}
