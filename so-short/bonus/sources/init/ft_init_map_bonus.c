/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:59:15 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 16:52:32 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_setup_map(t_game *game)
{
	ft_printf(GRID_SIZE_PRINT"\t[%d %d]\n", \
		game->map.size.x, game->map.size.y);
	ft_print_initial_positions(game);
	ft_update_map_matrice(game);
	ft_print_display_grid(game->map.matrice);
	game->map.grid = ft_create_map_with_border(game);
	game->map.original = ft_copy_grid(game->map.grid, \
		game->map.size.y, game->map.size.x);
	if (!game->map.original)
		ft_print_error(COPY_MAP_FAIL, game);
	ft_printf(NEW_GRID_MSG);
	ft_print_display_grid(game->map.grid);
	ft_update_map_positions(game);
	ft_printf(GRID_SIZE_PRINT"\t[%d %d]\n", \
		game->map.size.x, game->map.size.y);
	ft_display_position(game->map.start, game->map.end,
		game->map.portal_1_pos, game->map.portal_2_pos);
	ft_update_player_position(game);
	ft_init_pawns_array(game);
}

char	**ft_copy_grid(char **src, int height, int width)
{
	char	**dst;
	int		index;

	index = 0x0;
	dst = (char **)malloc(sizeof(char *) * height);
	if (!dst)
		return (NULL);
	while (index < height)
	{
		dst[index] = (char *)malloc(sizeof(char) * (width + 0x1));
		if (!dst[index])
		{
			while (--index >= 0x0)
				free(dst[index]);
			free(dst);
			return (NULL);
		}
		ft_strlcpy(dst[index], src[index], width + 0x1);
		index++;
	}
	return (dst);
}

void	ft_play_random_theme(void)
{
	static int	random;

	srand((unsigned int)time(NULL));
	random = rand() % 0x4;
	if (random == 0x0)
		system("paplay sounds/theme/baba_is_you_on_the_island.wav \
			> /dev/null 2>&1 &");
	if (random == 1)
		system("paplay sounds/theme/baba_is_you_theme.wav \
			> /dev/null 2>&1 &");
	if (random == 2)
		system("paplay sounds/theme/baba_is_you_water_is_sink_the_lake.wav \
			> /dev/null 2>&1 &");
	if (random == 3)
		system("paplay \
			sounds/theme/baba_is_you_crystal_is_still_crystal_cave.wav \
			> /dev/null 2>&1 &");
}
