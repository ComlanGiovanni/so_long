/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bit_masking_frames.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:16:42 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/19 19:16:55 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_wall_bit_masking_frames(t_game *game)
{
	game->wall.east.frames = WALLS_FRAMES;
	game->wall.east.frames = WALLS_FRAMES;
	game->wall.south.frames = WALLS_FRAMES;
	game->wall.no_neighbors_four_direction.frames = WALLS_FRAMES;
	game->wall.south_plus_east.frames = WALLS_FRAMES;
	game->wall.north.frames = WALLS_FRAMES;
	game->wall.south_plus_west.frames = WALLS_FRAMES;
	game->wall.north_plus_east.frames = WALLS_FRAMES;
	game->wall.south_plus_west_plus_east.frames = WALLS_FRAMES;
	game->wall.north_plus_south.frames = WALLS_FRAMES;
	game->wall.north_plus_south_plus_east.frames = WALLS_FRAMES;
	game->wall.north_plus_south_plus_west.frames = WALLS_FRAMES;
	game->wall.north_plus_south_plus_west_plus_east.frames = WALLS_FRAMES;
	game->wall.west.frames = WALLS_FRAMES;
	game->wall.north_plus_west_plus_east.frames = WALLS_FRAMES;
	game->wall.west_plus_east.frames = WALLS_FRAMES;
	game->wall.north_west.frames = WALLS_FRAMES;
}

void	ft_init_wall_bit_masking(t_game *game, void **wall_sprites)
{
	const t_animation	*walls[] = {
		&game->wall.no_neighbors_four_direction,
		&game->wall.north, &game->wall.south,
		&game->wall.north_plus_south,
		&game->wall.west,
		&game->wall.north_west,
		&game->wall.south_plus_west,
		&game->wall.north_plus_south_plus_west,
		&game->wall.east,
		&game->wall.north_plus_east,
		&game->wall.south_plus_east,
		&game->wall.north_plus_south_plus_east,
		&game->wall.west_plus_east,
		&game->wall.north_plus_west_plus_east,
		&game->wall.south_plus_west_plus_east,
		&game->wall.north_plus_south_plus_west_plus_east
	};
	int					index;

	index = 0x0;
	while (index < BIT_MASK_POSSIBILITY)
	{
		wall_sprites[index] = walls[index]->current;
		index++;
	}
}
