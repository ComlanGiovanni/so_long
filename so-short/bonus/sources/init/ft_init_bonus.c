/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:20:05 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 01:19:23 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_camera(t_game *game)
{
	game->camera.current.x = game->player.movement.current_position.x;
	game->camera.current.y = game->player.movement.current_position.y;
	game->camera.target.x = game->player.movement.current_position.x;
	game->camera.target.y = game->player.movement.current_position.y;
	game->camera.shake_intensity = 0.0;
	game->camera.shake_speed = 0.0;
	game->camera.lerp_speed = 0.0;
}

//make position offset ?
//missing t_point for life
// game->hud.storage.x = 200;
// game->hud.storage.y = 300;

void ft_init_hud_sprites_position(t_game *game)
{
	game->hud.step.x = 5;
	game->hud.step.y = game->window.height - 150;
	game->hud.fps.x = 5;
	game->hud.fps.y = game->window.height - 100;
	game->hud.direction.x = 5;
	game->hud.direction.y = 320;
	game->hud.keys.x = 5;
	game->hud.keys.y = game->window.height - 200;
	//game->hud.direction.x = ;
	//game->hud.direction.y = ;
}

void	ft_init_borders_frames(t_game *game)
{
	game->wall.animation.frames = 64;
	game->grass.animation.frames = 12;
	game->tree.animation.frames = 42;
	game->trees.animation.frames = 24;
	game->reed.animation.frames = 64;
	game->husks.animation.frames = 48;
	game->fungus.animation.frames = 55;
	game->fungi.animation.frames = 32;
	game->flower.animation.frames = 128;
	game->algae.animation.frames = 16;
	game->water.animation.frames = 56;
	game->crab.animation.frames = 33;
	game->foliage.animation.frames = 65;
	game->bog.animation.frames = 21;
	game->snail.animation.frames = 73;
	game->pillar.animation.frames = 28;
	game->hedge.animation.frames = 77;
}

void	ft_init_digits_frames(t_game *game)
{
	game->hud.digits.zero.frames = 64;
	game->hud.digits.one.frames = 2;
	game->hud.digits.two.frames = 12;
	game->hud.digits.three.frames = 7;
	game->hud.digits.four.frames = 12;
	game->hud.digits.five.frames = 7;
	game->hud.digits.six.frames = 12;
	game->hud.digits.seven.frames = 7;
	game->hud.digits.eight.frames = 7;
	game->hud.digits.nine.frames = 12;
}

void ft_init_odd_alphabet_frames(t_game *game)
{
	game->hud.alphabet.a.frames = 12;
	game->hud.alphabet.c.frames = 12;
	game->hud.alphabet.e.frames = 12;
	game->hud.alphabet.g.frames = 12;
	game->hud.alphabet.i.frames = 12;
	game->hud.alphabet.k.frames = 12;
	game->hud.alphabet.m.frames = 12;
	game->hud.alphabet.o.frames = 12;
	game->hud.alphabet.q.frames = 12;
	game->hud.alphabet.s.frames = 12;
	game->hud.alphabet.u.frames = 12;
	game->hud.alphabet.w.frames = 12;
	game->hud.alphabet.y.frames = 12;
}

void ft_init_even_alphabet_frames(t_game *game)
{
	game->hud.alphabet.b.frames = 12;
	game->hud.alphabet.d.frames = 12;
	game->hud.alphabet.f.frames = 12;
	game->hud.alphabet.h.frames = 12;
	game->hud.alphabet.j.frames = 12;
	game->hud.alphabet.l.frames = 12;
	game->hud.alphabet.n.frames = 12;
	game->hud.alphabet.p.frames = 12;
	game->hud.alphabet.r.frames = 12;
	game->hud.alphabet.t.frames = 12;
	game->hud.alphabet.v.frames = 12;
	game->hud.alphabet.x.frames = 12;
	game->hud.alphabet.z.frames = 12;
}

void ft_init_alphabet_frames(t_game *game)
{
	ft_init_odd_alphabet_frames(game);
	ft_init_even_alphabet_frames(game);
}

void	ft_init_enemies_frames(t_game *game)
{
	game->lava.animation.frames = 24;
	game->keke.frames = 24;
	game->pawn.animation.frames = 32;
}

void	ft_init_gameplay_frames(t_game *game)
{
	game->portal.n.frames = 24;
	game->portal.z.frames = 24;
	game->box.animation.frames = 42;
	game->key.animation.frames = 6;
	game->love.animation.frames = 48;
}

void ft_init_others_frames(t_game *game)
{
	game->player.frames = 9;
	game->door.closed.frames = 24;
	game->door.open.frames = 24;
}

void	ft_init_frames(t_game *game)
{
	ft_init_enemies_frames(game);
	ft_init_gameplay_frames(game);
	ft_init_others_frames(game);
	ft_init_digits_frames(game);
	ft_init_alphabet_frames(game);
	ft_init_borders_frames(game);
}

void	ft_init_fps(t_game *game)
{
	clock_gettime(1, &game->fps.current_time);
	game->fps.frame_count = 0;
	game->fps.fps = 0.0;
	game->fps.last_time = game->fps.current_time;
	game->fps.elapsed = 0.0;
}

/**
 * @brief
 *
 * 		init to 0 height step
 * 				and init width to the
 * 		len of line send to the fct
 * 					the copy the line in map
 *	game->window.img = NULL;//
 * game->window.img_data = NULL;//
 * @param game
 * @param line
 */

void	ft_init_map_info(t_game *game, char *line)
{
	game->height = FALSE;
	game->width = ft_strlen(line) - TRUE;
	game->map.map_str = ft_custom_strdup(line);
	game->window.width = 0x0;
	game->window.height = 0x0;
	game->window.size_line = 0x0;
	game->window.bpp = 0x0;
	game->window.endian = 0x0;
	free(line);
}

void	ft_init_game_info(t_game *game)
{
	game->map.info.nbr_player = FALSE;
	game->map.info.nbr_key = FALSE;
	game->map.info.nbr_exit = FALSE;
	game->map.info.nbr_lava = FALSE;
	game->map.info.nbr_keke = FALSE;
	game->map.info.nbr_love = FALSE;
	game->map.info.nbr_wall = TRUE;
	game->map.info.nbr_pawn = FALSE;
	game->map.info.nbr_void = FALSE;
	game->map.info.nbr_box = FALSE;
	game->map.info.nbr_grass = FALSE;
	game->map.info.nbr_portal_1 = FALSE;
	game->map.info.nbr_portal_2 = FALSE;
	game->map.border_width = BORDERS_WIDTH;
}


