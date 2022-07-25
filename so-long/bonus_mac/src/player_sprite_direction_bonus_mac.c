/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite_direction_bonus_mac.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:54:16 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/25 17:08:35 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_mac/so_long_bonus_mac.h"

/**
 * @brief 
 * 
 * 					see ft_put_all_sprites_to_line 
 * 			because its only because of 25 line norm we here
 * 
 * 	But we print but the direction the good loade fram of player move
 * this frame_0 is alway changing in the animation_bonus fct for the iddle anim
 * 
 * @param game 
 * @param width 
 * @param height 
 */
void	ft_player_sprite_call(t_game *game, int width, int height)
{
	if (game->map.map_str[height * game->width + width] == PLAYER_CHAR
		&& game->player.direction == 'd')
		ft_down_sprite(game, width, height);
	else if (game->map.map_str[height * game->width + width] == PLAYER_CHAR
		&& game->player.direction == 'u')
		ft_up_sprite(game, width, height);
	else if (game->map.map_str[height * game->width + width] == PLAYER_CHAR
		&& game->player.direction == 'l')
		ft_left_sprite(game, width, height);
	else if (game->map.map_str[height * game->width + width] == PLAYER_CHAR
		&& game->player.direction == 'r')
		ft_right_sprite(game, width, height);
}

/**
 * @brief 
 * 
 * 	25 line norm small fct because of long struct name and inception
 * 
 * @param game 
 * @param width 
 * @param height 
 */
void	ft_down_sprite(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.down_anim.frame_0, width * IMG_SIZE,
		height * IMG_SIZE);
}

void	ft_up_sprite(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.up_anim.frame_0, width * IMG_SIZE, height * IMG_SIZE);
}

void	ft_left_sprite(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.left_anim.frame_0, width * IMG_SIZE,
		height * IMG_SIZE);
}

void	ft_right_sprite(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.right_anim.frame_0, width * IMG_SIZE,
		height * IMG_SIZE);
}
