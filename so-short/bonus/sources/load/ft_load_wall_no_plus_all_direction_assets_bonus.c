/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_wall_no_plus_all_direction_assets_b        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:36:54 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/17 00:41:28 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_wall_no_neighbors_four_direction_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/no_neighbors_four_direction/wall_no_neighbors_four_direction_frame_0.xpm",
		PATH_ASSET"wall/no_neighbors_four_direction/wall_no_neighbors_four_direction_frame_1.xpm",
		PATH_ASSET"wall/no_neighbors_four_direction/wall_no_neighbors_four_direction_frame_2.xpm"};
	const char	*error_messages[] = {
		"Gearjsdsneric message change soon",
		"Generv dsvic message change soon",
		"Generiwewec message change soon"};

	ft_load_animation_sprites(&(game->wall.no_neighbors_four_direction), game, paths,
		error_messages);
}

void	ft_load_wall_north_plus_south_plus_west_plus_east_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/north_plus_south_plus_west_plus_east/wall_north_plus_south_plus_west_plus_east_frame_0.xpm",
		PATH_ASSET"wall/north_plus_south_plus_west_plus_east/wall_north_plus_south_plus_west_plus_east_frame_1.xpm",
		PATH_ASSET"wall/north_plus_south_plus_west_plus_east/wall_north_plus_south_plus_west_plus_east_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic mwefewessage change soon",
		"Generic wevwemessage change soon",
		"Generic vsdvsmessage change soon"};

	ft_load_animation_sprites(&(game->wall.north_plus_south_plus_west_plus_east), game, paths,
		error_messages);
}
