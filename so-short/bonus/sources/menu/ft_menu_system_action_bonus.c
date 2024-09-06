/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_system_action.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:18:05 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 17:28:51 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//MACRO Restart game
void	ft_restart_game(t_game *game)
{
	system("pkill paplay > /dev/null 2>&1");
	ft_printf("\nRestart game %s\n", game->map.map_name);
	ft_free_pawns_array(game);
	ft_reset_grid(game);
	ft_init_fps(game);
	ft_init_player_info(game);
	ft_update_player_position(game);
	ft_dir_player_by_pos_exit_after_launch(game);
	ft_init_monster_info(game);
	ft_init_pawns_array(game);
	game->key_collected = 0x0;
	game->state = STATE_PLAYING;
	ft_play_random_theme();
}

void	ft_start_game(t_game *game)
{
	ft_restart_game(game);
}

//MACROS
void	ft_play_levels(t_game *game)
{
	ft_printf("Levels button cliqued, DLC option %s\n", game->map.map_name);
}

void	ft_resume_game(t_game *game)
{
	ft_toggle_pause(game);
}

void	ft_return_to_main_menu(t_game *game)
{
	system("pkill paplay > /dev/null 2>&1");
	game->state = STATE_MENU;
}
