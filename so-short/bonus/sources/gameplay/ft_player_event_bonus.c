/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_event_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:23:29 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 16:25:13 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_play_movement_sound(t_game *game)
{
	game->player.step++;
	system("aplay sounds/special-effects/baba_move.wav \
		> /dev/null 2>&1 &");
}

void	ft_player_take_coin(t_game *game)
{
	game->player.storage++;
	system("aplay sounds/special-effects/baba_take_key.wav \
		> /dev/null 2>&1 &");
}

void	ft_player_take_life(t_game *game)
{
	game->player.life++;
	system("aplay sounds/special-effects/baba_take_life.wav \
		> /dev/null 2>&1 &");
}

void	ft_player_get_hit(t_game *game)
{
	game->player.life--;
	system("aplay sounds/special-effects/baba_take_damage.wav \
		> /dev/null 2>&1 &");
	ft_camera_shake(game);
	//game->player.up_anim.current = game->player.up_anim.current
	//load read print or display on hud message or blood
}

void	ft_baba_forbidden(t_game *game)
{
	ft_camera_shake(game);
	//display on hud a message like can not take more than 6
}
