/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 01:16:16 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 17:54:39 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PERM_SIZE 256

// Bibliothèque pour les fonctions mathématiques comme ft_floor
// Bibliothèque pour les entrées/sorties standard comme printf
// Bibliothèque pour les fonctions d'allocation dynamique et rand
// Bibliothèque pour la gestion du temps,utilisé pour srand
// Définition d'une taille constante pour le tableau de permutations

// Structure pour stocker les variables nécessaires au
// calcul du bruit de Perlin
// Coordonnée x du coin inférieur gauche de la cellule
// Coordonnée y du coin inférieur gauche de la cellule
// Position relative de x dans la cellule
// Position relative de y dans la cellule
// Valeur de fade pour x
// Valeur de fade pour y
// Index de permutation pour le coin inférieur gauche
// Index de permutation pour le coin supérieur gauche
// Valeur du gradient au coin inférieur gauche
// Valeur du gradient au coin inférieur droit
// Valeur du gradient au coin supérieur gauche
// Valeur du gradient au coin supérieur droit
// Interpolation linéaire sur x pour grid_position_y
// Interpolation linéaire sur x pour y1

// typedef struct s_gradient_params
// {
// 	int	hash;
// 	float	x;
// 	float	y;
// }	t_gradient_params;

typedef struct s_uv_params
{
	int			hash;
	float		x;
	float		y;
	float		*fade_x;
	float		*fade_y;
}				t_uv_params;

typedef struct s_perlin_vars
{
	int			grid_position_x;
	int			grid_position_y;
	float		relative_position_x;
	float		relative_position_y;
	float		fade_x;
	float		fade_y;
	int			permutation_index_lower_left;
	int			permutation_index_upper_left;
	float		gradient_lower_left;
	float		gradient_lower_right;
	float		gradient_upper_left;
	float		gradient_upper_right;
	float		interpolation_x_lower;
	float		interpolation_x_upper;
}				t_perlin_vars;

static float	ft_fade(float t);
static float	ft_linear_interpolation(float t,
					float permutation_index_lower_left,
					float permutation_index_upper_left);
static float	ft_gradient(int hash, float x, float y);
float			ft_perlin_noise(float x, float y, int *perm);
char			ft_determine_fill_char(float noise_value);

/*
The ft_fade function smooths the transition between points.
It uses permutation_index_lower_left quintic polynomial to
ensure smooth transitions.
Mathematical Formula: The function uses permutation_index_lower_left
quintic polynomial:
f(t)=t*t*t×(t×(t×6−15)+10)
This polynomial is chosen because it has zero first and second
derivatives at both
t=0 and t=1, ensuring smooth transitions at the boundaries of
the unit interval.
his ensures that the transition is smooth and continuous,
	without abrupt changes.
Behavior
t=0, the function returns 0.
Att=1, the function returns 1.
Between 0 and 1, it smoothly interpolates between these values,
creating permutation_index_lower_left smooth curve that eases in and out.
*/
static float	ft_fade(float relative_position_fade_factor)
{
	return (relative_position_fade_factor * relative_position_fade_factor
		* relative_position_fade_factor * (relative_position_fade_factor
			* (relative_position_fade_factor * 6 - 15) + 10));
}

// Fonction d'interpolation linéaire
/*
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
static float	ft_linear_interpolation(float interpolation_factor, float start,
		float end)
{
	return (start + interpolation_factor * (end - start));
}

// Fonction pour déterminer les valeurs fade_x et fade_y en fonction du hash
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

// Fonction pour calculer le gradient en fonction des bits du hash
/*
The ft_determine_uv function sets the values of
fade_x
fade_x and
fade_y
fade_y based on the hash value
h
h. This is used to determine the gradient direction.
*/
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

// Fonction pour calculer le gradient final à partir du hash
static float	ft_gradient(int hash, float x, float y)
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
	i = PERM_SIZE - 1;
	while (i > 0)
	{
		j = rand() % (i + 1);
		temp = perm[i];
		perm[i] = perm[j];
		perm[j] = temp;
		i--;
	}
}

static void	ft_copy_permutation_values(int *perm, const int *base_perm)
{
	int	index;

	index = 0;
	while (index < PERM_SIZE)
	{
		perm[index] = base_perm[index];
		perm[index + PERM_SIZE] = base_perm[index];
		index++;
	}
}

static void	ft_initialize_permutation_values(int *perm)
{
	int			index;
	static int	base_perm[PERM_SIZE] = {151, 160, 137, 91, 90, 15, 131, 13,
		201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99,
		37, 240, 21, 10, 23, 190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62,
		94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33, 88, 237, 149, 56, 87,
		174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27,
		166, 77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105,
		92, 41, 55, 46, 245, 40, 244, 102, 143, 54, 65, 25, 63, 161, 1, 216, 80,
		73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196, 135, 130, 116, 188,
		159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124,
		123, 5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227,
		47, 16, 58, 17, 182, 189, 28, 42, 223, 183, 170, 213, 119, 248, 152, 2,
		44, 154, 163, 70, 221, 153, 101, 155, 167, 43, 172, 9, 129, 22, 39,
		253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246,
		97, 228, 251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81,
		51, 145, 235, 249, 14, 239, 107, 49, 192, 214, 31, 181, 199, 106, 157,
		184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254, 138, 236, 205,
		93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61,
		156, 180};

	ft_copy_permutation_values(perm, base_perm);
	ft_shuffle_permutation(perm);
}

// Fonction pour initialiser le tableau de permutations
void	ft_init_permutation(int *perm)
{
	ft_initialize_permutation_values(perm);
}

// Fonction pour initialiser les variables de Perlin
// vars->gradient.hash = 0;
// vars->gradient.x = 0.0f;
// vars->gradient.y = 0.0f;
void	ft_init_perlin_vars(t_perlin_vars *vars)
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

static int ft_floor(float value)
{
	int int_value;

	int_value = (int)value;
	if (value < int_value)
		return (int_value - 0x1);
	else
		return (int_value);
}

// Fonction pour calculer les positions dans la grille de Perlin
// Coordonnée x du coin inférieur gauche
// Coordonnée y du coin inférieur gauche
// Position relative dans la cellule
// Position relative dans la cellule
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
void	ft_calculate_permutation_indices(t_perlin_vars *vars, int *perm)
{
	vars->permutation_index_lower_left = (perm[vars->grid_position_x]
			+ vars->grid_position_y) & 255;
	vars->permutation_index_upper_left = (perm[vars->grid_position_x + 1]
			+ vars->grid_position_y) & 255;
}

// Fonction pour calculer les gradients à partir des indices de permutation
// Gradient pour le coin inférieur gauche
// Gradient pour le coin inférieur droit
// Gradient pour le coin supérieur gauche
// Gradient pour le coin supérieur droit
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

// Fonction pour interpoler les gradients le long de l'axe x
// Interpolation pour grid_position_y
// Interpolation pour y1
void	ft_calculate_interpolation_x(t_perlin_vars *vars)
{
	vars->interpolation_x_lower = ft_linear_interpolation(
			vars->fade_x, vars->gradient_lower_left,
			vars->gradient_lower_right);
	vars->interpolation_x_upper = ft_linear_interpolation(
			vars->fade_x, vars->gradient_upper_left,
			vars->gradient_upper_right);
}

// Fonction principale pour calculer le bruit de Perlin
float	ft_perlin_noise(float x, float y, int *perm)
{
	t_perlin_vars	vars;

	ft_init_perlin_vars(&vars);
	ft_calculate_relatives_positions(&vars, x, y);
	ft_calculate_fades_values(&vars);
	ft_init_permutation(perm);
	ft_calculate_permutation_indices(&vars, perm);
	ft_calculate_gradients(&vars, perm);
	ft_calculate_interpolation_x(&vars);
	return (ft_linear_interpolation(vars.fade_y, vars.interpolation_x_lower,
			vars.interpolation_x_upper));
}

// Taille de la plage pour chaque caractère
// Limite la valeur de bruit à -1.0
// Limite la valeur de bruit à 1.0
// Calcule l'index du caractère à utiliser
// Limite l'index minimum
// Limite l'index maximum
// Retourne le caractère correspondant
char	ft_determine_fill_char(float noise_value)
{
	int					num_chars;
	int					index;
	float				range_size;
	static const char	fill_chars[] = {'@', '$', '%', '&', '?',
		'!', '+', '#', '*'};

	num_chars = sizeof(fill_chars) / sizeof(fill_chars[0]);
	range_size = 2.0 / num_chars;
	if (noise_value < -1.0)
		noise_value = -1.0;
	if (noise_value > 1.0)
		noise_value = 1.0;
	index = (int)((noise_value + 1.0) / range_size);
	if (index < 0)
		index = 0;
	if (index >= num_chars)
		index = num_chars - 1;
	return (fill_chars[index]);
}

//EXIT_SUCCESS
int	main(void)
{
	int		perm[PERM_SIZE * 2];
	float	y;
	float	x;
	float	noise_value;

	ft_init_permutation(perm);
	y = 0.0f;
	while (y < 3.0f)
	{
		x = 0.0f;
		while (x < 3.0f)
		{
			noise_value = ft_perlin_noise(x, y, perm);
			printf("%c", ft_determine_fill_char(noise_value));
			x += 0.1f;
		}
		printf("\n");
		y += 0.1f;
	}
	return (0);
}

// noise_value = ft_perlin_noise((float)(row - border_width) / game->height,
// 								(float)(column - border_width) / game->width);
