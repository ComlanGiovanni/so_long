/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_finishable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:30:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 15:11:40 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_mandatory.h"

void	ft_get_number_collectible(t_game *game)
{
	int	idx;

	idx = FALSE;
	game->nbr_love = FALSE;
	while (idx++ < game->map_len)
	{
		if (game->map[idx] == COIN_CHAR)
			game->nbr_love++;
	}
}

t_point	ft_find_pos_char(char **tab, t_point size, char c)
{
	int	x;
	int	y;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (tab[y][x] == c)
				return ((t_point){x, y});
			x++;
		}
		y++;
	}
	return ((t_point){-1, -1});
}

void	ft_flood_fill(char **tab, t_game *game, t_point start)
{
	if (start.y < 0 || start.y >= game->height || start.x < 0
		|| start.x >= game->width || tab[start.y][start.x] == WALL_CHAR
		|| tab[start.y][start.x] == VISITED_CHAR)
		return ;
	if (tab[start.y][start.x] == COIN_CHAR)
	{
		tab[start.y][start.x] = VOID_CHAR;
		game->flood_fill.coins++;
	}
	if (tab[start.y][start.x] == EXIT_CHAR)
		return ;
	if (game->flood_fill.coins == game->key)
		game->flood_fill.exit_found = TRUE;
	tab[start.y][start.x] = VISITED_CHAR;
	ft_flood_fill(tab, game, (t_point){start.x - 1, start.y});
	ft_flood_fill(tab, game, (t_point){start.x + 1, start.y});
	ft_flood_fill(tab, game, (t_point){start.x, start.y - 1});
	ft_flood_fill(tab, game, (t_point){start.x, start.y + 1});
}
