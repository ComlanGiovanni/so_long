/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_sprite_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:28:39 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 15:57:12 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

/*
	repating myself here how can i fix it ?
	// remove after for test hors is usefull i we put 0 but bro ....
	if (player->frames == 0)
		return ;
	//game->player.frames = 9;
*/

void	ft_player_animation(t_player *player)
{
	static int	frame;

	if (frame == player->frames)
	{
		player->up_anim.frame_0 = player->up_anim.frame_1;
		player->down_anim.frame_0 = player->down_anim.frame_1;
		player->left_anim.frame_0 = player->left_anim.frame_1;
		player->right_anim.frame_0 = player->right_anim.frame_1;
	}
	else if (frame >= player->frames * 2)
	{
		player->up_anim.frame_0 = player->up_anim.frame_2;
		player->down_anim.frame_0 = player->down_anim.frame_2;
		player->left_anim.frame_0 = player->left_anim.frame_2;
		player->right_anim.frame_0 = player->right_anim.frame_2;
		frame = 0;
	}
	frame += 1;
}

void	ft_load_player_up_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player.up_anim.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/up/player_up_frame_0.xpm",
			&width, &height);
	if (game->player.up_anim.frame_0 == NULL)
		ft_print_error(PLAYER_U_0_ERROR);
	game->player.up_anim.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/up/player_up_frame_1.xpm",
			&width, &height);
	if (game->player.up_anim.frame_1 == NULL)
		ft_print_error(PLAYER_U_1_ERROR);
	game->player.up_anim.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/up/player_up_frame_2.xpm",
			&width, &height);
	if (game->player.up_anim.frame_2 == NULL)
		ft_print_error(PLAYER_U_2_ERROR);
	game->player.up_anim.frame_move = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/up/player_up_frame_move.xpm",
			&width, &height);
	if (game->player.up_anim.frame_move == NULL)
		ft_print_error(PLAYER_U_M_ERROR);
}

void	ft_load_player_down_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player.down_anim.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/down/player_down_frame_0.xpm",
			&width, &height);
	if (game->player.down_anim.frame_0 == NULL)
		ft_print_error(PLAYER_D_0_ERROR);
	game->player.down_anim.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/down/player_down_frame_1.xpm",
			&width, &height);
	if (game->player.down_anim.frame_1 == NULL)
		ft_print_error(PLAYER_D_1_ERROR);
	game->player.down_anim.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/down/player_down_frame_2.xpm",
			&width, &height);
	if (game->player.down_anim.frame_2 == NULL)
		ft_print_error(PLAYER_D_2_ERROR);
	game->player.down_anim.frame_move = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/down/player_down_frame_move.xpm",
			&width, &height);
	if (game->player.down_anim.frame_move == NULL)
		ft_print_error(PLAYER_D_M_ERROR);
}

void	ft_load_player_left_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player.left_anim.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/left/player_left_frame_0.xpm",
			&width, &height);
	if (game->player.left_anim.frame_0 == NULL)
		ft_print_error(PLAYER_L_0_ERROR);
	game->player.left_anim.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/left/player_left_frame_1.xpm",
			&width, &height);
	if (game->player.left_anim.frame_1 == NULL)
		ft_print_error(PLAYER_L_1_ERROR);
	game->player.left_anim.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/left/player_left_frame_2.xpm",
			&width, &height);
	if (game->player.left_anim.frame_2 == NULL)
		ft_print_error(PLAYER_L_2_ERROR);
	game->player.left_anim.frame_move = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/left/player_left_frame_move.xpm",
			&width, &height);
	if (game->player.left_anim.frame_move == NULL)
		ft_print_error(PLAYER_L_M_ERROR);
}

void	ft_load_player_right_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player.right_anim.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/right/player_right_frame_0.xpm",
			&width, &height);
	if (game->player.right_anim.frame_0 == NULL)
		ft_print_error(PLAYER_R_0_ERROR);
	game->player.right_anim.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/right/player_right_frame_1.xpm",
			&width, &height);
	if (game->player.right_anim.frame_1 == NULL)
		ft_print_error(PLAYER_R_1_ERROR);
	game->player.right_anim.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/right/player_right_frame_2.xpm",
			&width, &height);
	if (game->player.right_anim.frame_2 == NULL)
		ft_print_error(PLAYER_R_2_ERROR);
	game->player.right_anim.frame_move = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/right/player_right_frame_move.xpm",
			&width, &height);
	if (game->player.right_anim.frame_move == NULL)
		ft_print_error(PLAYER_R_M_ERROR);
}
