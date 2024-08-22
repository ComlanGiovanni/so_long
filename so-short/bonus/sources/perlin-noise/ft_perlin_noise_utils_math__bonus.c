/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin_noise_utils_math__bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:11:02 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 14:22:52 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

static void	ft_determine_uv(t_uv_params *params)
{
	if (params->hash < 8)
	{
		*(params->fade_x) = params->x;
		*(params->fade_y) = params->y;
	}
	else
	{
		*(params->fade_x) = params->y;
		if (params->hash == 12 || params->hash == 14)
			*(params->fade_y) = params->x;
		else
			*(params->fade_y) = 0.0;
	}
}

static float	ft_compute_gradient(int h, float fade_x, float fade_y)
{
	float	result;

	result = 0.0;
	if (h & 1)
		result -= fade_x;
	else
		result += fade_x;
	if (h & 2)
		result -= fade_y;
	else
		result += fade_y;
	return (result);
}

float	ft_fade(float relative_position_fade_factor)
{
	return (relative_position_fade_factor * relative_position_fade_factor
		* relative_position_fade_factor * (relative_position_fade_factor
			* (relative_position_fade_factor * 6 - 15) + 10));
}

int	ft_floor(float value)
{
	int	int_value;

	int_value = (int)value;
	if (value < int_value)
		return (int_value - 0x1);
	else
		return (int_value);
}

// Fonction pour extraire les 4 bits les moins significatifs du hash
/*
The ft_compute_h function extracts the 4 least significant bits from the hash,
	used to determine gradient directions.
*/
// Fonction pour calculer le gradient final à partir du hash
float	ft_gradient(int hash, float x, float y)
{
	int			h;
	float		fade_x;
	float		fade_y;
	t_uv_params	uv_params;

	h = (hash & 15);
	uv_params.hash = h;
	uv_params.x = x;
	uv_params.y = y;
	uv_params.fade_x = &fade_x;
	uv_params.fade_y = &fade_y;
	ft_determine_uv(&uv_params);
	return (ft_compute_gradient(h, fade_x, fade_y));
}
