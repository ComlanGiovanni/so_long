/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin_noise_theme_one_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:36:54 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:39:05 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

const char	*get_fill_grass_chars(void)
{
	static const char	fill_chars[] = {GRASS_CHAR};

	return (fill_chars);
}

const char	*get_fill_swamp_chars(void)
{
	static const char	fill_chars[] = {TREE_CHAR, FOLIAGE_CHAR, PILLAR_CHAR, \
		TREES_CHAR, FUNGUS_CHAR, FUNGI_CHAR};

	return (fill_chars);
}

const char	*get_fill_versaille_chars(void)
{
	static const char	fill_chars[] = {FLOWER_CHAR, HEDGE_CHAR, \
		BOG_CHAR, FLOWER_CHAR};

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
