/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin_noise_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 01:16:16 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 17:50:50 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// Fonction pour calculer les positions dans la grille de Perlin
// Coordonnée x du coin inférieur gauche
// Coordonnée y du coin inférieur gauche
// Position relative dans la cellule
// Position relative dans la cellule
/*ermutation Table Size: The constant 255 is used because the
permutation table has a size of 256 elements. In Perlin noise,
the permutation table is typically duplicated to have 512 entries,
but the original size is 256.
Bitwise AND Operation: The operation & 255 is a bitwise AND operation
that ensures the result is within the range [0, 255]. This effectively
acts as a modulo operation with 256, ensuring that indices wrap around and
stay within the bounds of the permutation table.
Index Wrapping: By using & 255, you can efficiently wrap indices to ensure
they do not exceed the bounds of the permutation table. This is crucial for
 accessing the permutation table, as it is used to generate
 pseudo-random gradient vectors.*/
void	ft_calculate_relatives_positions(t_perlin_vars *vars, float x, float y)
{
	vars->grid_position_x = (int)ft_floor(x) & 255;
	vars->grid_position_y = (int)ft_floor(y) & 255;
	vars->relative_position_x = x - ft_floor(x);
	vars->relative_position_y = y - ft_floor(y);
}

// Fonction pour calculer les valeurs de fade (adoucissement) pour x et y
void	ft_calculate_fades_values(t_perlin_vars *vars)
{
	vars->fade_x = ft_fade(vars->relative_position_x);
	vars->fade_y = ft_fade(vars->relative_position_y);
}

// Fonction pour calculer les indices de permutation à partir des positions
// Index pour le coin inférieur gauche
// Index pour le coin supérieur gauche
/*ermutation Table Size: The constant 255 is used because the
permutation table has a size of 256 elements. In Perlin noise,
the permutation table is typically duplicated to have 512 entries,
but the original size is 256.
Bitwise AND Operation: The operation & 255 is a bitwise AND operation
that ensures the result is within the range [0, 255]. This effectively
acts as a modulo operation with 256, ensuring that indices wrap around and
stay within the bounds of the permutation table.
Index Wrapping: By using & 255, you can efficiently wrap indices to ensure
they do not exceed the bounds of the permutation table. This is crucial for
 accessing the permutation table, as it is used to generate
 pseudo-random gradient vectors.*/
void	ft_calculate_permutation_indices(t_perlin_vars *vars, int *perm)
{
	vars->permutation_index_lower_left = (perm[vars->grid_position_x]
			+ vars->grid_position_y) & 255;
	vars->permutation_index_upper_left = (perm[vars->grid_position_x + 1]
			+ vars->grid_position_y) & 255;
}

void	ft_calculate_gradients(t_perlin_vars *vars, int *perm)
{
	vars->gradient_lower_left = ft_gradient(
			perm[vars->permutation_index_lower_left],
			vars->relative_position_x,
			vars->relative_position_y);
	vars->gradient_lower_right = ft_gradient(
			perm[vars->permutation_index_upper_left],
			vars->relative_position_x - 1, vars->relative_position_y);
	vars->gradient_upper_left = ft_gradient(
			perm[vars->permutation_index_lower_left
			+ 1], vars->relative_position_x, vars->relative_position_y - 1);
	vars->gradient_upper_right = ft_gradient(
			perm[vars->permutation_index_upper_left + 1],
			vars->relative_position_x - 1, vars->relative_position_y - 1);
}

void	ft_calculate_interpolation_x(t_perlin_vars *vars)
{
	vars->interpolation_x_lower = ft_linear_interpolation(
			vars->fade_x, vars->gradient_lower_left,
			vars->gradient_lower_right);
	vars->interpolation_x_upper = ft_linear_interpolation(
			vars->fade_x, vars->gradient_upper_left,
			vars->gradient_upper_right);
}
