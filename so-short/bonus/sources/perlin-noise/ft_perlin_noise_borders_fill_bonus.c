/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin_noise_borders_fill_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:32:24 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:38:39 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_initialize_fill_chars(t_fill_char_state *state)
{
	static t_fill_char_function	fill_char_functions[] = {
		get_fill_marsh_chars, get_fill_fen_chars, get_fill_favorite_theme_chars,
		get_fill_beach_chars, get_fill_water_chars, get_fill_swamp_chars,
		get_fill_versaille_chars, get_fill_hedge_chars, get_fill_flower_chars,
		get_fill_forest_chars
	};
	int							num_sets;
	int							set_index;
	static int					fill_char_set_sizes[] = {0xa, 0x4, 0x7,
		0x4, 0x1, 0x1, 0x6, 0x4, 0x1, 0x1, 0x4};

	num_sets = sizeof(fill_char_functions) / sizeof(fill_char_functions[0x0]);
	srand((unsigned int)time(NULL));
	set_index = rand() % num_sets;
	state->selected_fill_chars = fill_char_functions[set_index]();
	state->selected_fill_chars_size = fill_char_set_sizes[set_index];
}

char	ft_determine_fill_char(float noise_value, t_fill_char_state	state)
{
	const char			*selected_fill_chars;
	int					index;
	float				range_size;

	selected_fill_chars = state.selected_fill_chars;
	range_size = 2.0 / state.selected_fill_chars_size;
	if (noise_value < -1.0)
		noise_value = -1.0;
	if (noise_value > 1.0)
		noise_value = 1.0;
	index = (int)((noise_value + 1.0) / range_size);
	if (index < 0x0)
		index = 0x0;
	if (index >= state.selected_fill_chars_size)
		index = state.selected_fill_chars_size - 0x1;
	return (selected_fill_chars[index]);
}
