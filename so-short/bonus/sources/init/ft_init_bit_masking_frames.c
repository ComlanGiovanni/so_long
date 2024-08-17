/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bit_masking_frames.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:16:42 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/17 01:54:55 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_so_long_bonus.h"

void	ft_init_wall_bit_masking_frames(t_game *game)
{
	game->wall.east.frames = 64;
	game->wall.east.frames = 64;
	game->wall.south.frames = 64;
	game->wall.no_neighbors_four_direction.frames = 64;
	game->wall.south_plus_east.frames = 64;
	game->wall.north.frames = 64;
	game->wall.south_plus_west.frames = 64;
	game->wall.north_plus_east.frames = 64;
	game->wall.south_plus_west_plus_east.frames = 64;
	game->wall.north_plus_south.frames = 64;
	game->wall.north_plus_south_plus_east.frames = 64;
	game->wall.north_plus_south_plus_west.frames = 64;
	game->wall.north_plus_south_plus_west_plus_east.frames = 64;
	game->wall.west.frames = 64;
	game->wall.north_plus_west_plus_east.frames = 64;
	game->wall.west_plus_east.frames = 64;
	game->wall.north_west.frames = 64;
	game->wall.animation.frames = 64;
}

void	ft_init_wall_bit_masking(t_game *game, void **wall_sprites)
{
	const t_animation	*walls[] = {
		&game->wall.no_neighbors_four_direction, // 0 (0000): No neighboring walls
		&game->wall.north, // 1 (0001): North
		&game->wall.south, // 2 (0010): South
		&game->wall.north_plus_south, // 3 (0011): North, South
		&game->wall.west, // 4 (0100): West
		&game->wall.north_west, // 5 (0101): North, West
		&game->wall.south_plus_west, // 6 (0110): South, West
		&game->wall.north_plus_south_plus_west, // 7 (0111): North, South, West
		&game->wall.east, // 8 (1000): East
		&game->wall.north_plus_east, // 9 (1001): North, East
		&game->wall.south_plus_east, // 10 (1010): South, East
		&game->wall.north_plus_south_plus_east, // 11 (1011): North, South, East
		&game->wall.west_plus_east, // 12 (1100): West, East
		&game->wall.north_plus_west_plus_east, // 13 (1101): North, West, East
		&game->wall.south_plus_west_plus_east, // 14 (1110): South, West, East
		&game->wall.north_plus_south_plus_west_plus_east // 15 (1111): North, South, West, East
	};
	int index = 0;

	while (index < 16)
	{
		wall_sprites[index] = walls[index]->current;
		index++;
	}
}
