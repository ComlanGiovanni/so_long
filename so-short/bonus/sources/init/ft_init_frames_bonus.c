/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_frames_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:18:49 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/19 19:22:57 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

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

void	ft_init_borders_frames(t_game *game)
{
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

void	ft_init_odd_alphabet_frames(t_game *game)
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

void	ft_init_even_alphabet_frames(t_game *game)
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
