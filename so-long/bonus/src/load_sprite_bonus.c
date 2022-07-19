/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:23:45 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/19 02:29:01 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	ft_load_lava_sprite(t_game *game)
{
	int			width;
	int			height;

    game->lava.animation.frames = 24;
	if ((game->lava.animation.frame_0 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/lava/lava_frame_0.xpm", &width, &height)) == NULL)
		ft_print_error("lava_frame_0.xpm");
	if ((game->lava.animation.frame_1 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/lava/lava_frame_1.xpm", &width, &height)) == NULL)
		ft_print_error("lava_frame_1.xpm");
	if ((game->lava.animation.frame_2 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/lava/lava_frame_2.xpm", &width, &height)) == NULL)
		ft_print_error("lava_frame_2.xpm");
}

void	ft_load_key_sprite(t_game *game)
{
	int			width;
	int			height;

    game->key.animation.frames = 6;
	if ((game->key.animation.frame_0 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/key/key_frame_0.xpm", &width, &height)) == NULL)
		ft_print_error(KEY_XPM_ERROR);
	if ((game->key.animation.frame_1 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/key/key_frame_1.xpm", &width, &height)) == NULL)
		ft_print_error("key_frame_1.xpm");
	if ((game->key.animation.frame_2 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/key/key_frame_2.xpm", &width, &height)) == NULL)
		ft_print_error("key_frame_2.xpm");
}

void	ft_load_wall_sprite(t_game *game)
{
	int			width;
	int			height;

    game->wall.animation.frames = 12;
	if ((game->wall.animation.frame_0 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/wall/wall_frame_0.xpm", &width, &height)) == NULL)
		ft_print_error(WALL_0_XPM_ERROR);
	if ((game->wall.animation.frame_1 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/wall/wall_frame_1.xpm", &width, &height)) == NULL)
		ft_print_error("wall_frame_1.xpm");
	if ((game->wall.animation.frame_2 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/wall/wall_frame_2.xpm", &width, &height)) == NULL)
		ft_print_error("wall_frame_2.xpm");
}
