/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin_noise_theme_two_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:39:32 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:39:41 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

const char	*get_fill_forest_chars(void)
{
	static const char	fill_chars[] = {WATER_CHAR, GRASS_CHAR, \
		TREE_CHAR, FOLIAGE_CHAR};

	return (fill_chars);
}
