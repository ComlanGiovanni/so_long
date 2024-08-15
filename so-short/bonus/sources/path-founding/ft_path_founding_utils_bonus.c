/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_founding_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:43:51 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 13:44:59 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

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
	while (game->map.map_str[idx] != '\0')
	{
		column = 0;
		grid[row] = (char *)malloc(sizeof(char) * (game->width + 1));
		if (!grid[row])
			ft_clean_fail_malloc_split_map(game, grid, row);
		while (column < game->width)
			grid[row][column++] = game->map.map_str[idx++];
		grid[row][column] = '\0';
		row++;
	}
	grid[row] = NULL;
	return (grid);
}

t_point	ft_find_pos_char(char **tab, t_point size, char c)
{
	int	x;
	int	y;

	if (!tab || size.x <= 0 || size.y <= 0)
		return ((t_point){-1, -1});
	y = 0;
	while (y < size.y)
	{
		if (tab[y] == NULL)
			return ((t_point){-1, -1});
		x = 0;
		while (x < size.x)
		{
			if (tab[y][x] == '\0')
				break ;
			if (tab[y][x] == c)
				return ((t_point){x, y});
			x++;
		}
		y++;
	}
	return ((t_point){-1, -1});
}
