/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_sprite_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:28:39 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/19 21:19:20 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

/*
	repating myself here how can i fix it ?
*/

void	ft_player_animation(t_player *player)
{
    static int	frame;
	if (player->frames == 0)// remove after for test hors is usefull i we put 0 but bro ....
		return ;
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
	int			width;
	int			height;

    game->player.frames = 9;
	if ((game->player.up_anim.frame_0 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/up/player_up_frame_0.xpm", &width, &height)) == NULL)
		ft_print_error(PLAYER_U_XPM_ERROR);//change name for all here
	if ((game->player.up_anim.frame_1 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/up/player_up_frame_1.xpm", &width, &height)) == NULL)
		ft_print_error("player_up_frame_1.xpm");//change name for all here
	if ((game->player.up_anim.frame_2 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/up/player_up_frame_2.xpm", &width, &height)) == NULL)
		ft_print_error("player_up_frame_2.xpm");//change name for all here
    if ((game->player.up_anim.frame_move = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/up/player_up_frame_move.xpm", &width, &height)) == NULL)
		ft_print_error("player_up_frame_move.xpm");//change name for all here
}


void	ft_load_player_down_sprites(t_game *game)
{
	int			width;
	int			height;

    //game->player.frames = 9;
	if ((game->player.down_anim.frame_0 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/down/player_down_frame_0.xpm", &width, &height)) == NULL)
		ft_print_error(PLAYER_D_XPM_ERROR);//change name for all here
	if ((game->player.down_anim.frame_1 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/down/player_down_frame_1.xpm", &width, &height)) == NULL)
		ft_print_error("player_down_frame_1.xpm");//change name for all here
	if ((game->player.down_anim.frame_2 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/down/player_down_frame_2.xpm", &width, &height)) == NULL)
		ft_print_error("player_down_frame_2.xpm");//change name for all here
    if ((game->player.down_anim.frame_move = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/down/player_down_frame_move.xpm", &width, &height)) == NULL)
		ft_print_error("player_down_frame_move.xpm");//change name for all here
}

void	ft_load_player_left_sprites(t_game *game)
{
	int			width;
	int			height;

    //game->player.frames = 9;
	if ((game->player.left_anim.frame_0 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/left/player_left_frame_0.xpm", &width, &height)) == NULL)
		ft_print_error(PLAYER_L_XPM_ERROR);//change name for all here
	if ((game->player.left_anim.frame_1 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/left/player_left_frame_1.xpm", &width, &height)) == NULL)
		ft_print_error("player_left_frame_1.xpm");//change name for all here
	if ((game->player.left_anim.frame_2 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/left/player_left_frame_2.xpm", &width, &height)) == NULL)
		ft_print_error("player_left_frame_2.xpm");//change name for all here
    if ((game->player.left_anim.frame_move = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/left/player_left_frame_move.xpm", &width, &height)) == NULL)
		ft_print_error("player_left_frame_move.xpm");//change name for all here
}

void	ft_load_player_right_sprites(t_game *game)
{
	int			width;
	int			height;

    //game->player.frames = 9;
	if ((game->player.right_anim.frame_0 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/right/player_right_frame_0.xpm", &width, &height)) == NULL)
		ft_print_error(PLAYER_R_XPM_ERROR);//change name for all here
	if ((game->player.right_anim.frame_1 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/right/player_right_frame_1.xpm", &width, &height)) == NULL)
		ft_print_error("player_up_frame_1.xpm");//change name for all here
	if ((game->player.right_anim.frame_2 = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/right/player_right_frame_2.xpm", &width, &height)) == NULL)
		ft_print_error("player_up_frame_2.xpm");//change name for all here
    if ((game->player.right_anim.frame_move = mlx_xpm_file_to_image(game->mlx, "assets/xpm/Bonus/player/right/player_right_frame_move.xpm", &width, &height)) == NULL)
		ft_print_error("player_up_frame_move.xpm");//change name for all here
}
