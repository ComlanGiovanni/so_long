/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin_noise_theme_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:36:52 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:38:50 by gicomlan         ###   ########.fr       */
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
	static const char	fill_chars[] = {WATER_CHAR, GRASS_CHAR, \
		CRAB_CHAR, SNAIL_CHAR};

	return (fill_chars);
}

const char	*get_fill_water_chars(void)
{
	static const char	fill_chars[] = {WATER_CHAR};

	return (fill_chars);
}
