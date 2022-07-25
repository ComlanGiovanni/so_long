/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_bonus_mac.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:23:45 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/25 17:08:16 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_mac/so_long_bonus_mac.h"

/**
 * @brief 
 * 
 * 		Check after load to prevent segfault of all the loaded sprite
 * 			set of the frame of the animation in the struct
 *				print the good errorr message
 * 		Here lava love wall ground sprite close and open sprite
 * 
 * 	ground is xpm black void only one the rest have 3 state frame 012
 * 				we also load the love icon struct 10x10
 * 			we can load the key icon struc in the future
 *				to display the number of key we have
 *				Same for step and small icon step(DLC 5)
 * 
 * 
 * @param game 
 */

void	ft_load_lava_sprites(t_game *game)
{
	int			width;
	int			height;

	game->lava.animation.frames = 24;
	game->lava.animation.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/lava/lava_frame_0.xpm", &width, &height);
	if (game->lava.animation.frame_0 == NULL)
		ft_print_error(LAVA_0_XPM_ERROR);
	game->lava.animation.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/lava/lava_frame_1.xpm", &width, &height);
	if (game->lava.animation.frame_1 == NULL)
		ft_print_error(LAVA_1_XPM_ERROR);
	game->lava.animation.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/lava/lava_frame_2.xpm", &width, &height);
	if (game->lava.animation.frame_2 == NULL)
		ft_print_error(LAVA_2_XPM_ERROR);
}

void	ft_load_key_sprites(t_game *game)
{
	int	width;
	int	height;

	game->key.animation.frames = 6;
	game->key.animation.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/key/key_frame_0.xpm", &width, &height);
	if (game->key.animation.frame_0 == NULL)
		ft_print_error(KEY_0_XPM_ERROR);
	game->key.animation.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/key/key_frame_1.xpm", &width, &height);
	if (game->key.animation.frame_1 == NULL)
		ft_print_error(KEY_1_XPM_ERROR);
	game->key.animation.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/key/key_frame_2.xpm", &width, &height);
	if (game->key.animation.frame_2 == NULL)
		ft_print_error(KEY_2_XPM_ERROR);
}

void	ft_load_wall_sprites(t_game *game)
{
	int			width;
	int			height;

	game->wall.animation.frames = 12;
	game->wall.animation.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/wall/wall_frame_0.xpm", &width, &height);
	if (game->wall.animation.frame_0 == NULL)
		ft_print_error(WALL_0_XPM_ERROR);
	game->wall.animation.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/wall/wall_frame_1.xpm", &width, &height);
	if (game->wall.animation.frame_1 == NULL)
		ft_print_error(WALL_1_XPM_ERROR);
	game->wall.animation.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/wall/wall_frame_2.xpm", &width, &height);
	if (game->wall.animation.frame_2 == NULL)
		ft_print_error(WALL_2_XPM_ERROR);
}

void	ft_load_ground_sprites(t_game *game)
{
	int	width;
	int	height;

	game->map.ground = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/ground/ground.xpm", &width, &height);
	if (game->map.ground == NULL)
		ft_print_error(GROUND_XPM_ERROR);
}

void	ft_load_love_sprites(t_game *game)
{
	int	width;
	int	height;

	game->love.animation.frames = 48;
	game->love.animation.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/love/love_frame_0.xpm", &width, &height);
	if (game->love.animation.frame_0 == NULL)
		ft_print_error(LOVE_0_XPM_ERROR);
	game->love.animation.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/love/love_frame_1.xpm", &width, &height);
	if (game->love.animation.frame_1 == NULL)
		ft_print_error(LOVE_1_XPM_ERROR);
	game->love.animation.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/love/love_frame_2.xpm", &width, &height);
	if (game->love.animation.frame_2 == NULL)
		ft_print_error(LOVE_2_XPM_ERROR);
	game->love.icon = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/love/love_small_icon.xpm", &width, &height);
	if (game->love.icon == NULL)
		ft_print_error(LOVE_ICON_ERROR);
}
