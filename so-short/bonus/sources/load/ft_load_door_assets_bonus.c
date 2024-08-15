/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_door_assets_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:10:49 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/13 13:00:18 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_door_closed_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"door/closed/door_closed_frame_0.xpm",
		PATH_ASSET"door/closed/door_closed_frame_1.xpm",
		PATH_ASSET"door/closed/door_closed_frame_2.xpm"};
	const char	*error_messages[] = {
		DOOR_C_0_XPM_ERROR,
		DOOR_C_1_XPM_ERROR,
		DOOR_C_2_XPM_ERROR};

	ft_load_animation_sprites((t_animation *)&(game->door.closed), game, paths,
		error_messages);
}

void	ft_load_door_open_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"door/open/door_open_frame_0.xpm",
		PATH_ASSET"door/open/door_open_frame_1.xpm",
		PATH_ASSET"door/open/door_open_frame_2.xpm"};
	const char	*error_messages[] = {
		DOOR_O_0_XPM_ERROR,
		DOOR_O_1_XPM_ERROR,
		DOOR_O_2_XPM_ERROR};

	ft_load_animation_sprites((t_animation *)&(game->door.open), game, paths,
		error_messages);
}
