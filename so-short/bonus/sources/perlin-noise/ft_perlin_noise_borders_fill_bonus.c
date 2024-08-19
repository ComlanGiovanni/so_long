/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin_noise_borders_fill_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:32:24 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/19 21:42:02 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

const char	*get_fill_marsh_chars(void)
{
	static const char	fill_chars[] = {WATER_CHAR, GRASS_CHAR, FLOWER_CHAR,
		TREE_CHAR, TREES_CHAR, REED_CHAR, ALGAE_CHAR, FUNGI_CHAR,
		FUNGUS_CHAR, HUSKS_CHAR};

	return (fill_chars);
}

const char	*get_fill_fen_chars(void)
{
	static const char	fill_chars[] = {WATER_CHAR, GRASS_CHAR,
		FLOWER_CHAR, TREE_CHAR};

	return (fill_chars);
}

const char	*get_fill_favorite_theme_chars(void)
{
	static const char	fill_chars[] = {WATER_CHAR, VOID_CHAR, GRASS_CHAR,
		HEDGE_CHAR, BOG_CHAR, VOID_CHAR, VOID_CHAR};

	return (fill_chars);
}

const char	*get_fill_beach_chars(void)
{
	static const char	fill_chars[] = {WATER_CHAR, GRASS_CHAR, CRAB_CHAR, SNAIL_CHAR};

	return (fill_chars);
}

const char	*get_fill_water_chars(void)
{
	static const char	fill_chars[] = {WATER_CHAR};

	return (fill_chars);
}

const char	*get_fill_grass_chars(void)
{
	static const char	fill_chars[] = {GRASS_CHAR};

	return (fill_chars);
}

const char	*get_fill_swamp_chars(void)
{
	static const char	fill_chars[] = {TREE_CHAR, FOLIAGE_CHAR, PILLAR_CHAR, TREES_CHAR, FUNGUS_CHAR, FUNGI_CHAR};

	return (fill_chars);
}

const char	*get_fill_versaille_chars(void)
{
	static const char	fill_chars[] = {FLOWER_CHAR, HEDGE_CHAR, BOG_CHAR, FLOWER_CHAR};

	return (fill_chars);
}

const char	*get_fill_hedge_chars(void)
{
	static const char	fill_chars[] = {HEDGE_CHAR};

	return (fill_chars);
}

const char	*get_fill_flower_chars(void)
{
	static const char	fill_chars[] = {FLOWER_CHAR};

	return (fill_chars);
}

const char	*get_fill_forest_chars(void)
{
	static const char	fill_chars[] = {WATER_CHAR, GRASS_CHAR, TREE_CHAR, FOLIAGE_CHAR};

	return (fill_chars);
}

typedef const char	*(*t_fill_char_function)(void);

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
	ft_printf("Theme picked :num_sets %d i->%d\n\n%s",num_sets, set_index, \
		fill_char_functions[set_index]());
}

char	ft_determine_fill_char(float noise_value, t_fill_char_state	state)
{
	//t_fill_char_state	state;
	const char			*selected_fill_chars;
	int					index;
	float				range_size;
	//pu the stae before filling and calling perlin noise to see if theme is good
	//initialize_fill_chars(&state);
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
