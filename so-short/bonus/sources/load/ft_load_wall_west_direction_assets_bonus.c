/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_wall_west_direction_assets_bonus.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:01:57 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/17 00:47:54 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_wall_west_plus_east_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/west_plus_east/wall_west_plus_east_frame_0.xpm",
		PATH_ASSET"wall/west_plus_east/wall_west_plus_east_frame_1.xpm",
		PATH_ASSET"wall/west_plus_east/wall_west_plus_east_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic me2312ssage change soon",
		"Generic m2234essage change soon",
		"Generic m324ssage change soon"};

	ft_load_animation_sprites(&(game->wall.west_plus_east), game, paths,
		error_messages);
}

