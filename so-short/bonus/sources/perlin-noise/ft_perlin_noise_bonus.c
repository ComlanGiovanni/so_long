/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin_noise_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 01:16:16 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 14:26:08 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// Fonction pour initialiser les variables de Perlin
// vars->gradient.hash = 0;
// vars->gradient.x = 0.0f;
// vars->gradient.y = 0.0f;
static void	ft_init_perlin_vars(t_perlin_vars *vars)
{
	vars->grid_position_x = 0;
	vars->grid_position_y = 0;
	vars->relative_position_x = 0.0f;
	vars->relative_position_y = 0.0f;
	vars->fade_x = 0.0f;
	vars->fade_y = 0.0f;
	vars->permutation_index_lower_left = 0;
	vars->permutation_index_upper_left = 0;
	vars->gradient_lower_left = 0.0f;
	vars->gradient_lower_right = 0.0f;
	vars->gradient_upper_left = 0.0f;
	vars->gradient_upper_right = 0.0f;
	vars->interpolation_x_lower = 0.0f;
	vars->interpolation_x_upper = 0.0f;
}

static void	ft_copy_permutation_values(int *perm, const int *base_perm)
{
	int	index;

	index = 0x0;
	while (index < PERMUTATION_SIZE)
	{
		perm[index] = base_perm[index];
		perm[index + PERMUTATION_SIZE] = base_perm[index];
		index++;
	}
}

// Fonction pour mélanger le tableau de permutations
// Initialise le générateur de nombres aléatoires avec l'heure actuelle
// Génère un indice aléatoire
//as a seed provides different sequences on each run
static void	ft_shuffle_permutation(int *perm)
{
	int	i;
	int	j;
	int	temp;

	srand((unsigned int)time(NULL));
	i = PERMUTATION_SIZE - 0x1;
	while (i > 0x0)
	{
		j = rand() % (i + 0x1);
		temp = perm[i];
		perm[i] = perm[j];
		perm[j] = temp;
		i--;
	}
}

static void	ft_initialize_permutation_values(int *perm)
{
	static int	base_perm[PERMUTATION_SIZE] = {151, 160, 137, 91, 90, 15, \
		131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, \
		142, 8, 99, 37, 240, 21, 10, 23, 190, 6, 148, 247, 120, 234, 75, 0, \
		26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33, 88, \
		237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, \
		71, 134, 139, 48, 27, 166, 77, 146, 158, 231, 83, 111, 229, 122, \
		60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244, 102, \
		143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, \
		89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86, 164, 100, 109, \
		198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5, 202, 38, 147, \
		118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, \
		189, 28, 42, 223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, \
		70, 221, 153, 101, 155, 167, 43, 172, 9, 129, 22, 39, 253, 19, 98, \
		108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228, \
		251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, \
		145, 235, 249, 14, 239, 107, 49, 192, 214, 31, 181, 199, 106, 157, \
		184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254, 138, 236, 205, \
		93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, \
		156, 180};

	ft_copy_permutation_values(perm, base_perm);
	ft_shuffle_permutation(perm);
}

float	ft_perlin_noise(float x, float y)
{
	t_perlin_vars	vars;
	int				perm[PERMUTATION_SIZE * 2];

	ft_init_perlin_vars(&vars);
	ft_calculate_relatives_positions(&vars, x, y);
	ft_calculate_fades_values(&vars);
	ft_initialize_permutation_values(perm);
	ft_calculate_permutation_indices(&vars, perm);
	ft_calculate_gradients(&vars, perm);
	ft_calculate_interpolation_x(&vars);
	return (ft_linear_interpolation(vars.fade_y, vars.interpolation_x_lower, \
			vars.interpolation_x_upper));
}
