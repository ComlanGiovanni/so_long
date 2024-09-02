/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:59:15 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/24 21:55:38 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (n >= sizeof(unsigned long))
	{
		*(unsigned long *)dest_cpy = *(const unsigned long *)src_cpy;
		dest_cpy += sizeof(unsigned long);
		src_cpy += sizeof(unsigned long);
		n -= sizeof(unsigned long);
	}
	while (n > 0)
	{
		*dest_cpy++ = *src_cpy++;
		n--;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	if (src_len + 1 < size)
		ft_memcpy(dst, src, src_len + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = 0;
	}
	return (src_len);
}

char **ft_copy_grid(char **src, int height, int width)
{
    char **dst;
    int i;

    dst = (char **)malloc(sizeof(char *) * height);
    if (!dst)
        return NULL;

    for (i = 0; i < height; i++)
    {
        dst[i] = (char *)malloc(sizeof(char) * (width + 1));
        if (!dst[i])
        {
            while (--i >= 0)
                free(dst[i]);
            free(dst);
            return NULL;
        }
        ft_strlcpy(dst[i], src[i], width + 1);
    }

    return dst;
}
//ft_free_grid(game->map.original, game->map.size.y);
// game->map.info.nbr_grass = (game->map.size.x * game->map.size.y)
// 	- game->map.len;
void	ft_setup_map(t_game *game)
{
	ft_printf(GRID_SIZE_PRINT"\t[%d %d]\n", \
		game->map.size.x, game->map.size.y);
	ft_print_initial_positions(game);
	ft_update_map_matrice(game);
	ft_print_display_grid(game->map.matrice);
	game->map.grid = ft_create_map_with_border(game);
	game->map.original = ft_copy_grid(game->map.grid, game->map.size.y, game->map.size.x);
	if (!game->map.original)
		ft_print_error("Original game did not copy", game);//macro
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

void	ft_play_random_theme(void)
{
	static int	random;

	srand((unsigned int)time(NULL));
	random = rand() % 0x4;
	if (random == 0x0)
		system("aplay sounds/theme/baba_is_you_on_the_island.wav \
			> /dev/null 2>&1 &");
	if (random == 1)
		system("aplay sounds/theme/baba_is_you_theme.wav \
			> /dev/null 2>&1 &");
	if (random == 2)
		system("aplay sounds/theme/baba_is_you_water_is_sink_the_lake.wav \
			> /dev/null 2>&1 &");
	if (random == 3)
		system("aplay \
			sounds/theme/baba_is_you_crystal_is_still_crystal_cave.wav \
			> /dev/null 2>&1 &");
}
