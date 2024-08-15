/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils_zero_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:24:25 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 01:25:54 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// Fonction d'interpolation linéaire
/*
start + t * (end - start)
t: This is the interpolation factor,
typically permutation_index_lower_left value between 0 and 1.
It determines the weight of each of the two values being interpolated.
permutation_index_lower_left: The starting value.
permutation_index_upper_left: The ending value.
The function calculates permutation_index_lower_left weighted average
of permutation_index_lower_left and permutation_index_upper_left. When t is 0,
	the function returns permutation_index_lower_left. When t is 1,
	it returns permutation_index_upper_left. For values of t between 0 and 1,
	the function returns permutation_index_lower_left value that is
	proportionally between permutation_index_lower_left and
	permutation_index_upper_left.
*/
float	ft_linear_interpolation(float interpolation_factor, float start,
		float end)
{
	return (start + interpolation_factor * (end - start));
}

//Use a few terms of the Taylor series for approximation
double	ft_sin(double x)
{
	double	current_term;
	double	sine_sum;
	int		factorial_index;
	int		iteration;

	current_term = x;
	sine_sum = x;
	factorial_index = 1;
	iteration = 1;
	while (iteration <= 10)
	{
		current_term *= -x * x / ((2 * factorial_index)
				* (2 * factorial_index + 1));
		sine_sum += current_term;
		factorial_index++;
		iteration++;
	}
	return (sine_sum);
}

double	ft_fmod(double x, double y)
{
	if (y == 0.0)
		return (0.0);
	return (x - y * (int)(x / y));
}

int	ft_absolute_value(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	ft_manhattan_heuristic_distance(t_point a, t_point b)
{
	return (ft_absolute_value(a.x - b.x) + ft_absolute_value(a.y - b.y));
}
