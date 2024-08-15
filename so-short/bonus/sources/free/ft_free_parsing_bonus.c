/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parsing_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:47:41 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 13:14:15 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

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
		if (grid[index])
			free(grid[index]);
		index++;
	}
	if (grid)
		free(grid);
}
