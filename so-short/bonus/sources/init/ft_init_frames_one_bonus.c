/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_frames_one_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:20:23 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 16:21:07 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_alphabet_frames(t_game *game)
{
	ft_init_odd_alphabet_frames(game);
	ft_init_even_alphabet_frames(game);
}

void	ft_init_enemies_frames(t_game *game)
{
	game->lava.animation.frames = LAVA_FRAMES;
	game->monster.frames = MONSTER_FRAMES;
	game->pawn.animation.frames = PAWN_FRAMES;
}

void	ft_init_gameplay_frames(t_game *game)
{
	game->portal.n.frames = PORTAL_N_FRAMES;
	game->portal.z.frames = PORTAL_Z_FRAMES;
	game->box.animation.frames = BOX_FRAMES;
	game->key.animation.frames = KEY_FRAMES;
	game->love.animation.frames = LOVE_FRAMES;
	game->love.icon.animation.frames = LOVE_ICON_FRAMES;
}

void	ft_init_others_frames(t_game *game)
{
	game->player.frames = PLAYER_FRAMES;
	game->door.closed.frames = DOOR_OPEN_FRAMES;
	game->door.open.frames = DOOR_CLOSED_FRAMES;
}
