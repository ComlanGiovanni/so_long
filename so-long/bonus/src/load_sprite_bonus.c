/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:23:45 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/18 23:11:04 by gcomlan          ###   ########.fr       */
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

/*

void	ft_load_player_up_sprite(t_game *game)
{
	int			width;
	int			height;

    game->player.anim_up.frames = 9;
	if ((game->player.anim_up.frame_0 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/up/player_up_frame_0.xpm", &width, &height)) == NULL)
		ft_print_error("player_up_frame_0.xpm");
	if ((game->player.anim_up.frame_1 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/up/player_up_frame_1.xpm", &width, &height)) == NULL)
		ft_print_error("player_up_frame_1.xpm");
	if ((game->player.anim_up.frame_2 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/up/player_up_frame_2.xpm", &width, &height)) == NULL)
		ft_print_error("player_up_frame_2.xpm");
    if ((game->player.anim_up.frame_move = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/up/player_up_frame_move.xpm", &width, &height)) == NULL)
		ft_print_error("player_up_frame_move.xpm");
}

void	ft_load_player_down_sprite(t_game *game)
{
	int			width;
	int			height;

    game->player.anim_down.frames = 9;
	if ((game->player.anim_down.frame_0 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/down/player_down_frame_0.xpm", &width, &height)) == NULL)
		ft_print_error("player_down_frame_0.xpm");
	if ((game->player.anim_down.frame_1 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/down/player_down_frame_1.xpm", &width, &height)) == NULL)
		ft_print_error("player_down_frame_1.xpm");
	if ((game->player.anim_down.frame_2 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/down/player_down_frame_2.xpm", &width, &height)) == NULL)
		ft_print_error("player_down_frame_2.xpm");
    if ((game->player.anim_down.frame_move = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/down/player_down_frame_move.xpm", &width, &height)) == NULL)
		ft_print_error("player_down_frame_move.xpm");
}

*/