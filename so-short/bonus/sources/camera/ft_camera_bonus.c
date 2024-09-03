/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:05:20 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/03 15:15:50 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_camera_shake(t_game *game)
{
	const double	shake_intensity = 20.0;
	const double	shake_speed = 1.0;
	const double	shake_duration = 2.84;
	t_point			shake_offset;

	shake_offset.x = ft_sin(game->fps.elapsed * shake_speed) * shake_intensity;
	shake_offset.y = ft_sin(ft_fmod(game->fps.elapsed, shake_duration) \
			* shake_speed) * shake_intensity;
	game->camera.current.x += shake_offset.x;
	game->camera.current.y += shake_offset.y;
}

void	ft_update_camera(t_game *game)
{
	game->camera.target.x = ((game->player.movement.current_position.x \
			* IMG_SIZE) - ((game->width * IMG_SIZE) / 0x4) + (IMG_SIZE / 0x2));
	game->camera.target.y = ((game->player.movement.current_position.y \
			* IMG_SIZE) - ((game->height * IMG_SIZE) / 0x4) + (IMG_SIZE / 0x2));
	game->camera.current.x = ft_roundf(ft_linear_interpolation(
				game->camera.lerp_speed, game->camera.current.x, \
				game->camera.target.x));
	game->camera.current.y = ft_roundf(ft_linear_interpolation(
				game->camera.lerp_speed, game->camera.current.y, \
				game->camera.target.y));
}
