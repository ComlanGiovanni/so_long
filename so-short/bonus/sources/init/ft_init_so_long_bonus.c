/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_so_long_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:18:15 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 20:39:03 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_menu_buttons_position(t_game *game)
{
	game->menu.selected_button = 0x0;
	game->menu.start_button.position.x = ((game->window.width / 2) - 131);
	game->menu.start_button.position.y = 400;
	game->menu.levels_button.position.x = ((game->window.width / 2) - 131);
	game->menu.levels_button.position.y = 500;
	game->menu.quit_button.position.x = 0x0;
	game->menu.quit_button.position.y = 600;
	game->menu.resume_button.position.x = ((game->window.width / 2) - 142);
	game->menu.resume_button.position.y = 450;
	game->menu.restart_button.position.x = ((game->window.width / 2) - 142);
	game->menu.restart_button.position.y = 500;
	game->menu.main_menu_button.position.x = ((game->window.width / 2) - 142);
	game->menu.main_menu_button.position.y = 550;
}

void	ft_init_game(t_game *game, char *map_name)
{
	ft_check_map_argument(game, map_name);
	game->state = STATE_PLAYING;
	if (game->state == STATE_PLAYING)
	{
		ft_init_camera(game);
		ft_init_mlx(game);
		ft_init_frames(game);
		ft_load_sprites(game);
		ft_init_fps(game);
		ft_init_player_info(game);
		ft_init_monster_info(game);
		ft_read_map(game, map_name);
		ft_check_map(game);
		ft_setup_map(game);
		ft_print_map_info(game);
		ft_dir_player_by_pos_exit_after_launch(game);
		ft_map_fit_screen(game);
		ft_create_window(game);
		ft_init_hud_sprites_position(game);
		ft_display_sprites_addr(game);
		ft_init_menu_buttons_position(game);
	}
}

void	ft_init_player_info(t_game *game)
{
	game->player.life = 0x1;
	game->player.storage = FALSE;
	game->player.step = 0x0;
	game->player.storage = FALSE;
	game->player.movement.moved = FALSE;
	game->player.movement.current_position.x = FALSE;
	game->player.movement.current_position.y = FALSE;
}

void	ft_init_monster_info(t_game *game)
{
	game->monster.moved = FALSE;
	game->monster.step = FALSE;
	game->player.step = 0x0;
	ft_direction_monster_after_launch(game);
}

void	ft_check_map_argument(t_game *game, char *map_name)
{
	if (!ft_check_extension(map_name, BER_EXTENSION))
		ft_print_error_empty_and_free(EXTENSION_ERROR, game);
	game->map.map_name = map_name;
}
