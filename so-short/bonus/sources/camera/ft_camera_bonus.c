/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:05:20 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 22:39:30 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_camera_shake(t_game *game)
{
	const double	shake_intensity = 30.0;
	const double	shake_speed = 1.0;
	const double	shake_duration = 4.84;
	t_point			shake_offset;

	shake_offset.x = ft_sin(game->fps.elapsed * shake_speed) * shake_intensity;
	shake_offset.y = ft_sin(ft_fmod(game->fps.elapsed, shake_duration) \
			* shake_speed) * shake_intensity;
	game->camera.current.x += shake_offset.x;
	game->camera.current.y += shake_offset.y;
}

void	ft_update_camera(t_game *game)
{
	game->camera.lerp_speed = 0.02;
	game->camera.target.x = (game->player.movement.current_position.x \
			* IMG_SIZE) - ((game->width * IMG_SIZE) / 4);
	game->camera.target.y = (game->player.movement.current_position.y \
			* IMG_SIZE) - ((game->height * IMG_SIZE) / 4);
	game->camera.current.x = ft_linear_interpolation(game->camera.lerp_speed, \
			game->camera.current.x,
			game->camera.target.x);
	game->camera.current.y = ft_linear_interpolation(game->camera.lerp_speed, \
			game->camera.current.y,
			game->camera.target.y);
}
