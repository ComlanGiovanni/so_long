/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monster_behaviour_utils_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:43:27 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:46:24 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_monster_move_up(t_game *game)
{
	int	row;
	int	col;

	row = 0x0;
	while (row < game->height)
	{
		col = 0x0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == MONSTER_CHAR && row > 0x0)
				ft_move_monster_up(game, row, col);
			col++;
		}
		row++;
	}
}

void	ft_monster_move_down(t_game *game)
{
	int	row;
	int	col;

	row = game->height - 0x1;
	while (row >= 0x0)
	{
		col = 0x0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == MONSTER_CHAR \
				&& row < game->height - 0x1)
				ft_move_monster_down(game, row, col);
			col++;
		}
		row--;
	}
}

void	ft_monster_move_left(t_game *game)
{
	int	row;
	int	col;

	row = 0x0;
	while (row < game->height)
	{
		col = 0x0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == MONSTER_CHAR && col > 0x0)
				ft_move_monster_left(game, row, col);
			col++;
		}
		row++;
	}
}

void	ft_monster_move_right(t_game *game)
{
	int	row;
	int	col;

	row = 0x0;
	while (row < game->height)
	{
		col = game->width - 0x1;
		while (col >= 0x0)
		{
			if (game->map.grid[row][col] == MONSTER_CHAR \
				&& col < game->width - 0x1)
				ft_move_monster_right(game, row, col);
			col--;
		}
		row++;
	}
}
