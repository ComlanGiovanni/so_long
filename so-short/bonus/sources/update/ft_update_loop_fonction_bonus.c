/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_loop_fonction_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:39:28 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/09 17:34:41 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_update_playing_state(t_game *game)
{
	ft_update_fps(game);
	ft_update_camera(game);
	ft_play_animation(game);
	ft_check_coin_collected(game);
	mlx_clear_window(game->mlx, game->win);
	ft_put_sprites_by_line(game);
	ft_print_info_on_window(game);
	if (game->player.life <= 0x0)
	{
		game->state = STATE_LOSE;
		ft_lose_game(game);
	}
}

void	ft_update_win_lose_state(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	if (game->state == STATE_WIN)
		ft_draw_win_menu(game);
	else if (game->state == STATE_LOSE)
		ft_draw_game_over_menu(game);
	game->menu.restart_button.is_hovered = \
		(game->menu.selected_button == 0x0);
	game->menu.main_menu_button.is_hovered = \
		(game->menu.selected_button == 0x1);
	game->menu.quit_button.is_hovered = \
		(game->menu.selected_button == 0x2);
}

void	ft_update_menu_state(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	ft_draw_main_menu(game);
	game->menu.start_button.is_hovered = \
		(game->menu.selected_button == 0x0);
	game->menu.levels_button.is_hovered = \
		(game->menu.selected_button == 0x1);
	game->menu.quit_button.is_hovered = \
		(game->menu.selected_button == 0x2);
}

void	ft_update_pause_state(t_game *game)
{
	ft_draw_pause_message(game);
	ft_draw_pause_menu(game);
	game->menu.resume_button.is_hovered = \
		(game->menu.selected_button == 0x0);
	game->menu.restart_button.is_hovered = \
		(game->menu.selected_button == 0x1);
	game->menu.main_menu_button.is_hovered = \
		(game->menu.selected_button == 0x2);
	game->menu.quit_button.is_hovered = \
		(game->menu.selected_button == 0x3);
}

void	ft_update_game_elements(t_game *game)
{
	if ((game->map.info.nbr_pawn || game->map.info.nbr_monster) \
		&& game->fps.elapsed_time >= 1.0)
	{
		if (game->fps.last_time.tv_sec % 0x2)
			system("paplay sounds/special-effects/clock_tic.wav > \
				/dev/null 2>&1 &");
		else
			system("paplay sounds/special-effects/clock_tac.wav > \
				/dev/null 2>&1 &");
		ft_move_pawn(game);
		if (game->map.info.nbr_monster)
			ft_a_star_monster_movement(game);
	}
}
