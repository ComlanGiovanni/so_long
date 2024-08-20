/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_founding_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:24:37 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:32:24 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_check_map_finishable(t_game *game)
{
	game->flood_fill.coins = 0x0;
	game->flood_fill.exit_found = FALSE;
	game->map.matrice = ft_split_map(game);
	game->map.start = ft_find_pos_char(game->map.matrice, \
		game->map.size, PLAYER_CHAR);
	game->map.end = ft_find_pos_char(game->map.matrice, \
		game->map.size, EXIT_CHAR);
	if ((game->map.start.x == -1 && game->map.start.y == -1)
		|| (game->map.end.x == -1 && game->map.end.y == -1))
		ft_free_and_print(game->map.matrice, game, NO_POSITION_FOUND);
	ft_flood_fill(game->map.matrice, game, game->map.start);
	if (!game->flood_fill.exit_found)
		ft_free_and_print(game->map.matrice, game, PATH_MAP_ERROR);
	if (game->flood_fill.coins != game->map.info.nbr_key)
	{
		ft_printf("%s %d\n%s %d\n\n", KEY_FOUND, game->flood_fill.coins,
			KEY_AVAILABLE, game->map.info.nbr_key);
		ft_free_and_print(game->map.matrice, game, COIN_MAP_ERROR);
	}
	ft_printf(MAP_NAME_IS"%s\n\n", game->map.map_name);
	ft_printf("%s", PATH_MAP_GOOD);
	ft_printf("%s", COIN_MAP_GOOD);
}

void	ft_flood_fill(char **tab, t_game *game, t_point start)
{
	if (start.y < 0 || start.y >= game->height || start.x < 0
		|| start.x >= game->width || tab[start.y][start.x] == WALL_CHAR
		|| tab[start.y][start.x] == VISITED_CHAR)
		return ;
	if (tab[start.y][start.x] == KEY_CHAR)
	{
		tab[start.y][start.x] = VOID_CHAR;
		game->flood_fill.coins++;
	}
	if (tab[start.y][start.x] == EXIT_CHAR)
		return ;
	if (game->flood_fill.coins == game->map.info.nbr_key)
		game->flood_fill.exit_found = TRUE;
	tab[start.y][start.x] = VISITED_CHAR;
	ft_print_fill_grid(tab);
	ft_flood_fill(tab, game, (t_point){start.x - 1, start.y});
	ft_flood_fill(tab, game, (t_point){start.x + 1, start.y});
	ft_flood_fill(tab, game, (t_point){start.x, start.y - 1});
	ft_flood_fill(tab, game, (t_point){start.x, start.y + 1});
}
