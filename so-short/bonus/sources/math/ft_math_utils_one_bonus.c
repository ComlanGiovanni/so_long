/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils_one_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 02:18:29 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:43:25 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	ft_is_same_point(t_point a, t_point b)
{
	return ((a.x == b.x) && (a.y == b.y));
}

float	ft_roundf(float number)
{
	if (number >= 0.0f)
		return ((int)(number + 0.5f));
	else
		return ((int)(number - 0.5f));
}
