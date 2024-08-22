/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_map_finishable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:24:37 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 15:12:02 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_mandatory.h"

void	ft_check_map_finishable(t_game *game)
{
	char	**map;

	game->flood_fill.coins = 0;
	game->flood_fill.exit_found = FALSE;
	map = ft_split_map(game);
	ft_print_display_grid(map);
	game->size.x = game->width;
	game->size.y = game->height;
	game->start = ft_find_pos_char(map, game->size, 'P');
	game->end = ft_find_pos_char(map, game->size, 'E');
	if ((game->start.x == -1 && game->start.y == -1)
		|| (game->end.x == -1 && game->end.y == -1))
		ft_free_and_print(map, game, NO_POSITION_FOUND);
	ft_flood_fill(map, game, game->start);
	if (!game->flood_fill.exit_found)
		ft_free_and_print(map, game, PATH_MAP_ERROR);
	if (game->flood_fill.coins != game->key)
	{
		ft_printf("%s %d\n%s %d\n", KEY_FOUND, \
			game->flood_fill.coins, KEY_AVAILABLE, game->key);
		ft_free_and_print(map, game, COIN_MAP_ERROR);
	}
	ft_printf("%s", PATH_MAP_GOOD);
	ft_printf("%s", COIN_MAP_GOOD);
	ft_clean_grid_map(map, game->height);
}

void	ft_free_and_print(char **map, t_game *game, char *str)
{
	ft_clean_grid_map(map, game->height);
	ft_print_error(str, game);
}

char	**ft_split_map(t_game *game)
{
	int		idx;
	int		row;
	int		column;
	char	**grid;

	idx = 0;
	row = 0;
	grid = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!grid)
		ft_print_error(SPLIT_MAP_ERROR, game);
	while (game->map[idx] != '\0')
	{
		column = 0;
		grid[row] = (char *)malloc(sizeof(char) * (game->width + 1));
		if (!grid[row])
			ft_clean_fail_malloc_split_map(game, grid, row);
		while (column < game->width)
			grid[row][column++] = game->map[idx++];
		grid[row][column] = '\0';
		row++;
	}
	grid[row] = NULL;
	return (grid);
}

void	ft_clean_fail_malloc_split_map(t_game *game, char **grid, int row)
{
	ft_clean_grid_map(grid, row);
	ft_print_error(SPLIT_MAP_ERROR, game);
}

void	ft_clean_grid_map(char **grid, int row)
{
	int	index;

	index = 0;
	while (index < row)
	{
		free(grid[index]);
		index++;
	}
	free(grid);
}
