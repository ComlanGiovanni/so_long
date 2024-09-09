/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2024/09/09 17:07:59 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 *
 * 	Free of last minutes, need to read the project again for better free fct
 * 	we need to free all the image load in sprites before so we check and free
 * 	then the map in str (alway check if exist)
 * 	then we destroy the game (mlx, win)
 * 	then the display (mlx)
 * 	and at the end we need to free the mlx and the game we malloc in the main
 *
 *
 * @param game
 */
void	ft_free_all(t_game *game)
{
	mlx_loop_end(game->mlx);
	ft_free_player(game);
	ft_free_player_move(game);
	ft_free_map_love_lava(game);
	ft_free_key_wall_door(game);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	free(game);
}

void	ft_free_player(t_game *game)
{
	if (game->player.up_anim.frame_2)
		mlx_destroy_image(game->mlx, game->player.up_anim.frame_2);
	if (game->player.up_anim.frame_1)
		mlx_destroy_image(game->mlx, game->player.up_anim.frame_1);
	if (game->player.down_anim.frame_1)
		mlx_destroy_image(game->mlx, game->player.down_anim.frame_1);
	if (game->player.down_anim.frame_2)
		mlx_destroy_image(game->mlx, game->player.down_anim.frame_2);
	if (game->player.left_anim.frame_1)
		mlx_destroy_image(game->mlx, game->player.left_anim.frame_1);
	if (game->player.left_anim.frame_2)
		mlx_destroy_image(game->mlx, game->player.left_anim.frame_2);
	if (game->player.right_anim.frame_1)
		mlx_destroy_image(game->mlx, game->player.right_anim.frame_1);
	if (game->player.right_anim.frame_2)
		mlx_destroy_image(game->mlx, game->player.right_anim.frame_2);
	if (game->player.right_anim.frame_0)
		mlx_destroy_image(game->mlx, game->player.right_anim.frame_0);
	if (game->player.left_anim.frame_0)
		mlx_destroy_image(game->mlx, game->player.left_anim.frame_0);
	if (game->player.up_anim.frame_0)
		mlx_destroy_image(game->mlx, game->player.up_anim.frame_0);
	if (game->player.down_anim.frame_0)
		mlx_destroy_image(game->mlx, game->player.down_anim.frame_0);
}

void	ft_free_player_move(t_game *game)
{
	if (game->player.up_anim.frame_move)
		mlx_destroy_image(game->mlx, game->player.up_anim.frame_move);
	if (game->player.down_anim.frame_move)
		mlx_destroy_image(game->mlx, game->player.down_anim.frame_move);
	if (game->player.left_anim.frame_move)
		mlx_destroy_image(game->mlx, game->player.left_anim.frame_move);
	if (game->player.right_anim.frame_move)
		mlx_destroy_image(game->mlx, game->player.right_anim.frame_move);
}

void	ft_free_map_love_lava(t_game *game)
{
	if (game->map.map_str)
		free(game->map.map_str);
	if (game->map.ground)
		mlx_destroy_image(game->mlx, game->map.ground);
	if (game->love.icon)
		mlx_destroy_image(game->mlx, game->love.icon);
	if (game->love.animation.frame_1)
		mlx_destroy_image(game->mlx, game->love.animation.frame_1);
	if (game->love.animation.frame_2)
		mlx_destroy_image(game->mlx, game->love.animation.frame_2);
	if (game->lava.animation.frame_1)
		mlx_destroy_image(game->mlx, game->lava.animation.frame_1);
	if (game->lava.animation.frame_2)
		mlx_destroy_image(game->mlx, game->lava.animation.frame_2);
	if (game->lava.animation.frame_0)
		mlx_destroy_image(game->mlx, game->lava.animation.frame_0);
	if (game->love.animation.frame_0)
		mlx_destroy_image(game->mlx, game->love.animation.frame_0);
}

void	ft_free_key_wall_door(t_game *game)
{
	if (game->key.animation.frame_1)
		mlx_destroy_image(game->mlx, game->key.animation.frame_1);
	if (game->key.animation.frame_2)
		mlx_destroy_image(game->mlx, game->key.animation.frame_2);
	if (game->wall.animation.frame_1)
		mlx_destroy_image(game->mlx, game->wall.animation.frame_1);
	if (game->wall.animation.frame_2)
		mlx_destroy_image(game->mlx, game->wall.animation.frame_2);
	if (game->door.open.frame_1)
		mlx_destroy_image(game->mlx, game->door.open.frame_1);
	if (game->door.open.frame_2)
		mlx_destroy_image(game->mlx, game->door.open.frame_2);
	if (game->door.closed.frame_0)
		mlx_destroy_image(game->mlx, game->door.closed.frame_0);
	if (game->door.closed.frame_1)
		mlx_destroy_image(game->mlx, game->door.closed.frame_1);
	if (game->door.closed.frame_2)
		mlx_destroy_image(game->mlx, game->door.closed.frame_2);
	if (game->key.animation.frame_0)
		mlx_destroy_image(game->mlx, game->key.animation.frame_0);
	if (game->wall.animation.frame_0)
		mlx_destroy_image(game->mlx, game->wall.animation.frame_0);
	if (game->door.open.frame_0)
		mlx_destroy_image(game->mlx, game->door.open.frame_0);
}
