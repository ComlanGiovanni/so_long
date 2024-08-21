/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin_noise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:49:59 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/21 16:54:24 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>

# define PERMUTATION_SIZE 		256


typedef struct s_perlin_vars			t_perlin_vars;
typedef struct s_fill_char_state		t_fill_char_state;
typedef struct s_uv_params				t_uv_params;;
typedef const char	*(*t_fill_char_function)(void);
typedef enum e_map_char					t_map_char;

float	ft_perlin_noise(float x, float y);
static void	ft_init_perlin_vars(t_perlin_vars *vars);
void	ft_calculate_relatives_positions(t_perlin_vars *vars, float x, float y);
int ft_floor(float value);
void	ft_calculate_fades_values(t_perlin_vars *vars);
float	ft_fade(float relative_position_fade_factor);
void	ft_initialize_permutation_values(int *perm);
void	ft_copy_permutation_values(int *perm, const int *base_perm);
static void	ft_shuffle_permutation(int *perm);
void	ft_calculate_permutation_indices(t_perlin_vars *vars, int *perm);
void	ft_calculate_gradients(t_perlin_vars *vars, int *perm);
float	ft_gradient(int hash, float x, float y);
static void	ft_determine_uv(t_uv_params *params);
static float	ft_compute_gradient(int h, float fade_x, float fade_y);
void	ft_calculate_interpolation_x(t_perlin_vars *vars);
float	ft_linear_interpolation(float interpolation_factor, float start,
		float end);
const char	*get_fill_marsh_chars(void);
const char	*get_fill_fen_chars(void);
const char	*get_fill_favorite_theme_chars(void);
const char	*get_fill_beach_chars(void);
const char	*get_fill_water_chars(void);
const char	*get_fill_grass_chars(void);
const char	*get_fill_swamp_chars(void);
const char	*get_fill_versaille_chars(void);
const char	*get_fill_hedge_chars(void);
const char	*get_fill_flower_chars(void);
const char	*get_fill_forest_chars(void);
void	ft_initialize_fill_chars(t_fill_char_state *state);
char	ft_determine_fill_char(float noise_value, t_fill_char_state	state);

enum	e_map_char
{
	EXIT_CHAR = 'E',
	LOVE_CHAR = 'S',
	KEY_CHAR = 'C',
	PLAYER_CHAR = 'P',
	WALL_CHAR = '1',
	VOID_CHAR = '0',
	BOX_CHAR = 'B',
	PORTAL_1_CHAR = 'Z',
	PORTAL_2_CHAR = 'N',
	LAVA_CHAR = 'L',
	MONSTER_CHAR = 'K',
	PAWN_CHAR = 'W',
	GRASS_CHAR = '#',
	TREE_CHAR = '@',
	TREES_CHAR = '$',
	REED_CHAR = '%',
	HUSKS_CHAR = '&',
	FUNGUS_CHAR = '?',
	FUNGI_CHAR = '!',
	FLOWER_CHAR = '+',
	ALGAE_CHAR = '*',
	WATER_CHAR = '=',
	VISITED_CHAR = 'V',
	CRAB_CHAR = '~',
	FOLIAGE_CHAR = '"',
	BOG_CHAR = '.',
	SNAIL_CHAR = ',',
	PILLAR_CHAR = '|',
	HEDGE_CHAR = '/',
};

struct s_uv_params
{
	int			hash;
	float		x;
	float		y;
	float		*fade_x;
	float		*fade_y;
};


struct s_perlin_vars
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
};

struct s_fill_char_state
{
	const char		*selected_fill_chars;
	int				selected_fill_chars_size;
};

float	ft_perlin_noise(float x, float y)
{
	t_perlin_vars	vars;
	int		perm[PERMUTATION_SIZE * 2];

	ft_init_perlin_vars(&vars);
	ft_calculate_relatives_positions(&vars, x, y);
	ft_calculate_fades_values(&vars);
	ft_initialize_permutation_values(perm);
	ft_calculate_permutation_indices(&vars, perm);
	ft_calculate_gradients(&vars, perm);
	ft_calculate_interpolation_x(&vars);
	return (ft_linear_interpolation(vars.fade_y, vars.interpolation_x_lower,
			vars.interpolation_x_upper));
}

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

void	ft_calculate_relatives_positions(t_perlin_vars *vars, float x, float y)
{
	vars->grid_position_x = (int)ft_floor(x) & 255;
	vars->grid_position_y = (int)ft_floor(y) & 255;
	vars->relative_position_x = x - ft_floor(x);
	vars->relative_position_y = y - ft_floor(y);
	// printf("\n\nGrid_position_x -> %d", vars->grid_position_x);
	// printf("\nGrid_position_y -> %d", vars->grid_position_y);
	// printf("\nfloor_x -> %d", ft_floor(x));
	// printf("\nfloor_y -> %d", ft_floor(x));
	// printf("\nRelative_position_x -> %f", vars->relative_position_x);
	// printf("\nRelative_position_y -> %f", vars->relative_position_x);
}

int ft_floor(float value)
{
	int int_value;

	int_value = (int)value;
	if (value < int_value)
		return (int_value - 0x1);
	else
		return (int_value);
}

void	ft_calculate_fades_values(t_perlin_vars *vars)
{
	vars->fade_x = ft_fade(vars->relative_position_x);
	vars->fade_y = ft_fade(vars->relative_position_y);
}

float	ft_fade(float relative_position_fade_factor)
{
	return (relative_position_fade_factor * relative_position_fade_factor
		* relative_position_fade_factor * (relative_position_fade_factor
			* (relative_position_fade_factor * 6 - 15) + 10));
}

void	ft_initialize_permutation_values(int *perm)
{
	static int	base_perm[PERMUTATION_SIZE] = {151, 160, 137, 91, 90, 15, 131, 13,
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

void	ft_copy_permutation_values(int *perm, const int *base_perm)
{
	int	index;

	index = 0;
	while (index < PERMUTATION_SIZE)
	{
		perm[index] = base_perm[index];
		perm[index + PERMUTATION_SIZE] = base_perm[index];
		index++;
	}
}

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

void	ft_calculate_interpolation_x(t_perlin_vars *vars)
{
	vars->interpolation_x_lower = ft_linear_interpolation(
			vars->fade_x, vars->gradient_lower_left,
			vars->gradient_lower_right);
	vars->interpolation_x_upper = ft_linear_interpolation(
			vars->fade_x, vars->gradient_upper_left,
			vars->gradient_upper_right);
}

float	ft_linear_interpolation(float interpolation_factor, float start,
		float end)
{
	return (start + interpolation_factor * (end - start));
}

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
}

char	ft_determine_fill_char(float noise_value, t_fill_char_state	state)
{
	const char			*selected_fill_chars;
	int					index;
	float				range_size;

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

int	main(void)
{
	float	y;
	float	x;
	float	noise_value;
	t_fill_char_state	state;
	ft_initialize_fill_chars(&state);
	y = 0.0f;
	while (y < 8.0f)
	{
		x = 0.0f;
		while (x < 8.0f)
		{
			noise_value = ft_perlin_noise(x, y);
			printf("%c", ft_determine_fill_char(noise_value, state));
			x += 0.1f;
		}
		printf("\n");
		y += 0.1f;
	}
	return (0);
}
