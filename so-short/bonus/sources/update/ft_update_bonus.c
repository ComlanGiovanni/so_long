/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:02:13 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:05:28 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	ft_update(t_game *game)
{
	mlx_mouse_get_pos(game->mlx, game->win, &game->mouse.mouse_position.x,
		&game->mouse.mouse_position.y);
	ft_check_mouse_hover(game);
	if (game->state == STATE_MENU)
		ft_update_menu_state(game);
	else if (game->state == STATE_PAUSED)
		ft_update_pause_state(game);
	else if (game->state == STATE_PLAYING)
		ft_update_playing_state(game);
	else if (game->state == STATE_WIN || game->state == STATE_LOSE)
		ft_update_win_lose_state(game);
	return (EXIT_SUCCESS);
}

//this shit is dirty time managment bad and movement in update fps
void	ft_update_fps(t_game *game)
{
	clock_gettime(1, &game->fps.current_time);
	game->fps.elapsed = (game->fps.current_time.tv_sec - \
		game->fps.last_time.tv_sec) + \
		(game->fps.current_time.tv_nsec - game->fps.last_time.tv_nsec) / 1e9;
	game->fps.elapsed_time = (game->fps.current_time.tv_sec - \
		game->fps.last_time.tv_sec) + \
		(game->fps.current_time.tv_nsec - game->fps.last_time.tv_nsec) / 1e9;
	game->fps.frame_count++;
	if (game->fps.elapsed >= 1.0)
	{
		game->fps.fps = game->fps.frame_count / game->fps.elapsed;
		game->fps.frame_count = 0x0;
		game->fps.last_time = game->fps.current_time;
	}
	ft_update_game_elements(game);
}

	// if (game->map.info.nbr_pawn && game->fps.elapsed_time >= 1.0)
	// {
	// 	if (game->fps.last_time.tv_sec % 0x2)
	// 		system("paplay sounds/special-effects/clock_tic.wav
	// 		> /dev/null 2>&1 &");
	// 	else
	// 		system("paplay sounds/special-effects/clock_tac.wav
	// 		> /dev/null 2>&1 &");
	// 	ft_move_pawn(game);
	// 	if (game->map.info.nbr_monster)
	// 		ft_a_star_monster_movement(game);
	// }
