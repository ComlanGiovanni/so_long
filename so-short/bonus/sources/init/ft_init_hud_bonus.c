/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hud_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:34:38 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 16:25:45 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_digits_images(t_game *game, void **digit_images)
{
	const t_animation	*digits[] = {
		&game->hud.digits.zero, &game->hud.digits.one, &game->hud.digits.two,
		&game->hud.digits.three, &game->hud.digits.four, &game->hud.digits.five,
		&game->hud.digits.six, &game->hud.digits.seven, &game->hud.digits.eight,
		&game->hud.digits.nine
	};
	int					index;

	index = 0x0;
	while (index < DIGIT_COUNT)
	{
		digit_images[index] = digits[index]->current;
		index++;
	}
}

static void	ft_init_letter_images(t_game *game, void **letter_images, \
	int start_index)
{
	const t_animation	*letters[] = {
		&game->hud.alphabet.a, &game->hud.alphabet.b, &game->hud.alphabet.c,
		&game->hud.alphabet.d, &game->hud.alphabet.e, &game->hud.alphabet.f,
		&game->hud.alphabet.g, &game->hud.alphabet.h, &game->hud.alphabet.i,
		&game->hud.alphabet.j, &game->hud.alphabet.k, &game->hud.alphabet.l,
		&game->hud.alphabet.m, &game->hud.alphabet.n, &game->hud.alphabet.o,
		&game->hud.alphabet.p, &game->hud.alphabet.q, &game->hud.alphabet.r,
		&game->hud.alphabet.s, &game->hud.alphabet.t, &game->hud.alphabet.u,
		&game->hud.alphabet.v, &game->hud.alphabet.w, &game->hud.alphabet.x,
		&game->hud.alphabet.y, &game->hud.alphabet.z
	};
	int					letter_index;
	int					current_index;

	letter_index = start_index;
	current_index = 0x0;
	while (letter_index < ALPHABET_COUNT)
	{
		letter_images[letter_index] = letters[letter_index]->current;
		letter_index += 0x2;
		current_index++;
	}
}

void	ft_init_even_letter_images(t_game *game, void **letter_images)
{
	ft_init_letter_images(game, letter_images, 0x0);
}

void	ft_init_odd_letter_images(t_game *game, void **letter_images)
{
	ft_init_letter_images(game, letter_images, 0x1);
}
