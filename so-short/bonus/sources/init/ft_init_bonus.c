/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:20:05 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/18 14:44:16 by gicomlan         ###   ########.fr       */
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
	//game->wall.animation.frames = 64;
	game->grass.animation.frames = GRASS_FRAMES;
	game->tree.animation.frames = TREE_FRAMES;
	game->trees.animation.frames = TREES_FRAMES;
	game->reed.animation.frames = REED_FRAMES;
	game->husks.animation.frames = HUSKS_FRAMES;
	game->fungus.animation.frames = FUNGUS_FRAMES;
	game->fungi.animation.frames = FUNGI_FRAMES;
	game->flower.animation.frames = FLOWER_FRAMES;
	game->algae.animation.frames = ALGAE_FRAMES;
	game->water.animation.frames = WATER_FRAMES;
	game->crab.animation.frames = CRAB_FRAMES;
	game->foliage.animation.frames = FOLIAGE_FRAMES;
	game->bog.animation.frames = BOG_FRAMES;
	game->snail.animation.frames = SNAIL_FRAMES;
	game->pillar.animation.frames = PILLAR_FRAMES;
	game->hedge.animation.frames = HEDGE_FRAMES;
}

void	ft_init_digits_frames(t_game *game)
{
	game->hud.digits.zero.frames = DIGITS_EVEN_FRAMES;
	game->hud.digits.one.frames = DIGITS_ODD_FRAMES;
	game->hud.digits.two.frames = DIGITS_EVEN_FRAMES;
	game->hud.digits.three.frames = DIGITS_ODD_FRAMES;
	game->hud.digits.four.frames = DIGITS_EVEN_FRAMES;
	game->hud.digits.five.frames = DIGITS_ODD_FRAMES;
	game->hud.digits.six.frames = DIGITS_EVEN_FRAMES;
	game->hud.digits.seven.frames = DIGITS_ODD_FRAMES;
	game->hud.digits.eight.frames = DIGITS_ODD_FRAMES;
	game->hud.digits.nine.frames = DIGITS_EVEN_FRAMES;
}

void ft_init_odd_alphabet_frames(t_game *game)
{
	game->hud.alphabet.a.frames = ALPHABET_FRAMES;
	game->hud.alphabet.c.frames = ALPHABET_FRAMES;
	game->hud.alphabet.e.frames = ALPHABET_FRAMES;
	game->hud.alphabet.g.frames = ALPHABET_FRAMES;
	game->hud.alphabet.i.frames = ALPHABET_FRAMES;
	game->hud.alphabet.k.frames = ALPHABET_FRAMES;
	game->hud.alphabet.m.frames = ALPHABET_FRAMES;
	game->hud.alphabet.o.frames = ALPHABET_FRAMES;
	game->hud.alphabet.q.frames = ALPHABET_FRAMES;
	game->hud.alphabet.s.frames = ALPHABET_FRAMES;
	game->hud.alphabet.u.frames = ALPHABET_FRAMES;
	game->hud.alphabet.w.frames = ALPHABET_FRAMES;
	game->hud.alphabet.y.frames = ALPHABET_FRAMES;
}

void ft_init_even_alphabet_frames(t_game *game)
{
	game->hud.alphabet.b.frames = ALPHABET_FRAMES;
	game->hud.alphabet.d.frames = ALPHABET_FRAMES;
	game->hud.alphabet.f.frames = ALPHABET_FRAMES;
	game->hud.alphabet.h.frames = ALPHABET_FRAMES;
	game->hud.alphabet.j.frames = ALPHABET_FRAMES;
	game->hud.alphabet.l.frames = ALPHABET_FRAMES;
	game->hud.alphabet.n.frames = ALPHABET_FRAMES;
	game->hud.alphabet.p.frames = ALPHABET_FRAMES;
	game->hud.alphabet.r.frames = ALPHABET_FRAMES;
	game->hud.alphabet.t.frames = ALPHABET_FRAMES;
	game->hud.alphabet.v.frames = ALPHABET_FRAMES;
	game->hud.alphabet.x.frames = ALPHABET_FRAMES;
	game->hud.alphabet.z.frames = ALPHABET_FRAMES;
}

void ft_init_alphabet_frames(t_game *game)
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
}

void ft_init_others_frames(t_game *game)
{
	game->player.frames = PLAYER_FRAMES;
	game->door.closed.frames = DOOR_OPEN_FRAMES;
	game->door.open.frames = DOOR_CLOSED_FRAMES;
}

void	ft_init_frames(t_game *game)
{
	ft_init_enemies_frames(game);
	ft_init_gameplay_frames(game);
	ft_init_others_frames(game);
	ft_init_digits_frames(game);
	ft_init_alphabet_frames(game);
	ft_init_borders_frames(game);
	ft_init_wall_bit_masking_frames(game);
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
	game->map.info.nbr_monster = FALSE;
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


