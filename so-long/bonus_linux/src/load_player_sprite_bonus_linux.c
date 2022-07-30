/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_sprite_bonus_linux.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:28:39 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/31 00:45:41 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief 
 * 
 * 			Same thing for every animation 
 * 
 * 	so every x.frames and x.frame * 2
 *  	we change the frame_0 to the 1 when we hit
 * 			the frame fof the object aka frame count
 * 				in the fct, then change it to frame 2
 * 					when we hit the double of the frame
 * 						the reset it to 0 again and again
 * 
 * 	same but we change every state of the player
 * 		in can we are facing up down left and right
 * 
 * @param player 
 */
void	ft_player_animation(t_player *player)
{
	static int	frame;

	if (frame == player->frames)
	{
		player->up_anim.current = player->up_anim.frame_1;
		player->down_anim.current = player->down_anim.frame_1;
		player->left_anim.current = player->left_anim.frame_1;
		player->right_anim.current = player->right_anim.frame_1;
	}
	else if (frame >= player->frames * 2)
	{
		player->up_anim.current = player->up_anim.frame_2;
		player->down_anim.current = player->down_anim.frame_2;
		player->left_anim.current = player->left_anim.frame_2;
		player->right_anim.current = player->right_anim.frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

/**
 * @brief 
 * 
 * 		Check after load to prevent segfault 
 * 			of all the loaded sprite
 *			print the good error message
 * 		Here player sprite close and open sprite
 * 				UP sprite frame 0 1 2 move
 * 
 * @param game 
 */
void	ft_load_player_up_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player.up_anim.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/up/player_up_frame_0.xpm",
			&width, &height);
	if (game->player.up_anim.frame_0 == NULL)
		ft_print_error(PLAYER_U_0_ERROR, game);
	game->player.up_anim.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/up/player_up_frame_1.xpm",
			&width, &height);
	if (game->player.up_anim.frame_1 == NULL)
		ft_print_error(PLAYER_U_1_ERROR, game);
	game->player.up_anim.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/up/player_up_frame_2.xpm",
			&width, &height);
	if (game->player.up_anim.frame_2 == NULL)
		ft_print_error(PLAYER_U_2_ERROR, game);
	game->player.up_anim.frame_move = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/up/player_up_frame_move.xpm",
			&width, &height);
	if (game->player.up_anim.frame_move == NULL)
		ft_print_error(PLAYER_U_M_ERROR, game);
}

/**
 * @brief 
 * 
 * 		Check after load to prevent segfault 
 * 			of all the loaded sprite
 *			print the good error message
 * 		Here player sprite close and open sprite
 * 				DOWN sprite frame 0 1 2 move
 * 
 * @param game 
 */
void	ft_load_player_down_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player.down_anim.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/down/player_down_frame_0.xpm",
			&width, &height);
	if (game->player.down_anim.frame_0 == NULL)
		ft_print_error(PLAYER_D_0_ERROR, game);
	game->player.down_anim.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/down/player_down_frame_1.xpm",
			&width, &height);
	if (game->player.down_anim.frame_1 == NULL)
		ft_print_error(PLAYER_D_1_ERROR, game);
	game->player.down_anim.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/down/player_down_frame_2.xpm",
			&width, &height);
	if (game->player.down_anim.frame_2 == NULL)
		ft_print_error(PLAYER_D_2_ERROR, game);
	game->player.down_anim.frame_move = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/down/player_down_frame_move.xpm",
			&width, &height);
	if (game->player.down_anim.frame_move == NULL)
		ft_print_error(PLAYER_D_M_ERROR, game);
}

/**
 * @brief 
 * 
 * 		Check after load to prevent segfault 
 * 			of all the loaded sprite
 *			print the good error message
 * 		Here player sprite close and open sprite
 * 				LEFT sprite frame 0 1 2 move
 * 
 * @param game 
 */
void	ft_load_player_left_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player.left_anim.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/left/player_left_frame_0.xpm",
			&width, &height);
	if (game->player.left_anim.frame_0 == NULL)
		ft_print_error(PLAYER_L_0_ERROR, game);
	game->player.left_anim.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/left/player_left_frame_1.xpm",
			&width, &height);
	if (game->player.left_anim.frame_1 == NULL)
		ft_print_error(PLAYER_L_1_ERROR, game);
	game->player.left_anim.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/left/player_left_frame_2.xpm",
			&width, &height);
	if (game->player.left_anim.frame_2 == NULL)
		ft_print_error(PLAYER_L_2_ERROR, game);
	game->player.left_anim.frame_move = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/left/player_left_frame_move.xpm",
			&width, &height);
	if (game->player.left_anim.frame_move == NULL)
		ft_print_error(PLAYER_L_M_ERROR, game);
}

/**
 * @brief 
 * 
 * 		Check after load to prevent segfault 
 * 			of all the loaded sprite
 *			print the good error message
 * 		Here player sprite close and open sprite
 * 				RIGHT sprite frame 0 1 2 move
 * 
 * @param game 
 */
void	ft_load_player_right_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player.right_anim.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/right/player_right_frame_0.xpm",
			&width, &height);
	if (game->player.right_anim.frame_0 == NULL)
		ft_print_error(PLAYER_R_0_ERROR, game);
	game->player.right_anim.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/right/player_right_frame_1.xpm",
			&width, &height);
	if (game->player.right_anim.frame_1 == NULL)
		ft_print_error(PLAYER_R_1_ERROR, game);
	game->player.right_anim.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/right/player_right_frame_2.xpm",
			&width, &height);
	if (game->player.right_anim.frame_2 == NULL)
		ft_print_error(PLAYER_R_2_ERROR, game);
	game->player.right_anim.frame_move = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/player/right/player_right_frame_move.xpm",
			&width, &height);
	if (game->player.right_anim.frame_move == NULL)
		ft_print_error(PLAYER_R_M_ERROR, game);
}
