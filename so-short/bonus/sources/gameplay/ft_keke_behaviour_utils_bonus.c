/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keke_behaviour_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:43:27 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 02:37:24 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_keke_move_up(t_game *game)
{
	int	row;
	int	col;

	row = 0x0;
	while (row < game->height)
	{
		col = 0x0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == KEKE_CHAR && row > 0x0)
				ft_move_keke_up(game, row, col);
			col++;
		}
		row++;
	}
}

void	ft_keke_move_down(t_game *game)
{
	int	row;
	int	col;

	row = game->height - 0x1;
	while (row >= 0x0)
	{
		col = 0x0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == KEKE_CHAR \
				&& row < game->height - 0x1)
				ft_move_keke_down(game, row, col);
			col++;
		}
		row--;
	}
}

void	ft_keke_move_left(t_game *game)
{
	int	row;
	int	col;

	row = 0x0;
	while (row < game->height)
	{
		col = 0x0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == KEKE_CHAR && col > 0x0)
				ft_move_keke_left(game, row, col);
			col++;
		}
		row++;
	}
}

void	ft_keke_move_right(t_game *game)
{
	int	row;
	int	col;

	row = 0x0;
	while (row < game->height)
	{
		col = game->width - 0x1;
		while (col >= 0x0)
		{
			if (game->map.grid[row][col] == KEKE_CHAR \
				&& col < game->width - 0x1)
				ft_move_keke_right(game, row, col);
			col--;
		}
		row++;
	}
}
