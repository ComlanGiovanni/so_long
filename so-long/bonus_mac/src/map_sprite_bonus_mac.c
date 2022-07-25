/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sprite_bonus_mac.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:44:49 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/25 17:08:25 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_mac/so_long_bonus_mac.h"

/**
 * @brief 
 * 			
 * 
 * 		we split for 25 line norm so see ft_put_all_sprites_to_line comment			
 * 
 * 
 * @param game 
 * @param width 
 * @param height 
 */

void	ft_key_sprite(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->key.animation.frame_0, width * IMG_SIZE, height * IMG_SIZE);
}

void	ft_lava_sprite(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->lava.animation.frame_0, width * IMG_SIZE, height * IMG_SIZE);
}

void	ft_love_sprite(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->love.animation.frame_0, width * IMG_SIZE, height * IMG_SIZE);
}

void	ft_exit_sprite(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->door.closed.frame_0, width * IMG_SIZE, height * IMG_SIZE);
}

void	ft_ground_sprite(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->map.ground, width * IMG_SIZE, height * IMG_SIZE);
}
