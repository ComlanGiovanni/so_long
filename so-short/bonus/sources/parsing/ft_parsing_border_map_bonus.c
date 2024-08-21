/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_border_map_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:55:04 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/21 00:13:49 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

char	**ft_allocate_new_map(int new_height, int new_width, t_game *game)
{
	char	**new_map;
	int		row;

	new_map = (char **)malloc((new_height + 0x1) * sizeof(char *));
	if (!new_map)
		ft_print_error(BORDERS_MAP_ERROR, game);
	row = 0x0;
	while (row < new_height)
	{
		new_map[row] = (char *)malloc((new_width + 1) * sizeof(char));
		if (!new_map[row])
			ft_clean_fail_malloc_split_map(game, new_map, row);
		row++;
	}
	new_map[row] = NULL;
	return (new_map);
}

void	ft_fill_map_row(char **new_map, int row, t_game *game, int new_width)
{
	int					column;
	int					border_width;
	int					new_height;
	float				noise_value;
	t_fill_char_state	state;

	ft_initialize_fill_chars(&state);
	border_width = game->map.border_width;
	new_height = (game->height + (2 * border_width));
	column = 0x0;
	while (column < new_width)
	{
		if (row < border_width || row >= new_height - border_width
			|| column < border_width || column >= new_width - border_width)
		{
			noise_value = ft_perlin_noise(((float)(row - border_width) / \
				game->height), ((float)(column - border_width) / game->width));
			new_map[row][column] = ft_determine_fill_char(noise_value, state);
		}
		else
			new_map[row][column] = \
				game->map.matrice[row - border_width][column - border_width];
		column++;
	}
	new_map[row][new_width] = '\0';
}

char	**ft_create_map_with_border(t_game *game)
{
	int		row;
	int		new_width;
	int		new_height;
	char	**new_map;

	new_width = game->width + 2 * game->map.border_width;
	new_height = game->height + 2 * game->map.border_width;
	new_map = ft_allocate_new_map(new_height, new_width, game);
	row = 0x0;
	while (row < new_height)
	{
		ft_fill_map_row(new_map, row, game, new_width);
		row++;
	}
	if (game->map.matrice)
		ft_clean_grid_map(game->map.matrice, game->height);
	game->height = new_height;
	game->width = new_width;
	game->map.size.x = game->width;
	game->map.size.y = game->height;
	return (new_map);
}
