/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_so_long_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:18:15 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 13:44:51 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_game(t_game *game, char *map_name)
{
	//ft_check_map_argument
	if (!ft_check_extension(map_name, BER_EXTENSION))
		ft_print_error_empty_and_free(EXTENSION_ERROR, game);
	game->map.map_name = map_name;
	game->state = STATE_PLAYING;
	if (game->state == STATE_PLAYING)
	{
		ft_init_camera(game);
		ft_init_mlx(game);
		ft_init_frames(game);
		ft_load_sprites(game);
		ft_init_fps(game);
		ft_init_player_info(game);
		ft_init_keke_info(game);
		ft_read_map(game, map_name);
		ft_check_map(game);
		ft_setup_map(game);
		ft_print_map_info(game);
		ft_dir_player_by_pos_exit_after_launch(game);
		ft_create_window(game);
		ft_init_hud_sprites_position(game);
		ft_display_sprites_addr(game);
		ft_play_random_theme();
	}
}


/**
 * @brief
 *
 * 		This fct set all the player stat in game.player[]
 * 				1 life because 1 is enough
 * 			0 for storage step  and the frames is 9
 * 				after several test 9 feel good
 * 		we also generate randomly a direction of the first
 * 			int of the player to give player more life
 * 		we use srand rand of 4 digit (up down left right)
 * 						u d l r
 *
 * @param game
 */
void	ft_init_player_info(t_game *game)
{
	game->player.life = 3;
	game->player.storage = FALSE;
	game->player.step = 0;
	game->player.storage = FALSE;
	game->player.movement.moved = FALSE;
	game->player.movement.current_position.x = FALSE;
	game->player.movement.current_position.y = FALSE;
	//ft_dir_player_by_pos_exit_after_launch(game);
}

void	ft_init_keke_info(t_game *game)
{
	game->keke.moved = FALSE;
	game->keke.step = FALSE;
	game->player.step = 0;
	ft_direction_keke_after_launch(game);
}
