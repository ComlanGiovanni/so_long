/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:02:13 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 14:41:56 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//make a fct to return the good usleep in fonction of the limitation
//fps limiation usleep(game->fps.limitation); usleep(15000);

int	ft_update(t_game *game)
{
	if (game->state == STATE_PAUSED)
	{
		ft_draw_pause_message(game);
		return (EXIT_SUCCESS);
	}
	if (game->player.life <= 0x0)
		game->state = STATE_LOSE;
	if (game->state == STATE_PLAYING)
	{
		ft_update_fps(game);
		ft_update_camera(game);
		ft_play_animation(game);
		ft_check_coin_collected(game);
		mlx_clear_window(game->mlx, game->win);
		ft_put_sprites_by_line(game);
		ft_print_info_on_window(game);
	}
	if (game->state == STATE_WIN)
		ft_win_game(game);
	else if (game->state == STATE_LOSE)
		ft_lose_game(game);
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
	if (game->map.info.nbr_pawn && game->fps.elapsed_time >= 1.0)
	{
		if (game->fps.last_time.tv_sec % 0x2)
			system("aplay sounds/special-effects/clock_tic.wav \
			> /dev/null 2>&1 &");
		else
			system("aplay sounds/special-effects/clock_tac.wav \
			> /dev/null 2>&1 &");
		ft_move_pawn(game);
		if (game->map.info.nbr_monster)
			ft_a_star_monster_movement(game);
	}
}
