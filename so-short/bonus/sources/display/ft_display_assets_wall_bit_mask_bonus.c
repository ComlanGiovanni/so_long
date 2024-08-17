/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_wall_bit_mask_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:07:25 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/17 02:30:44 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

static int ft_calculate_wall_bitmask(t_game *game, int x, int y)
{
	 int bitmask = 0;

    if (y > 0 && game->map.grid[y - 1][x] == WALL_CHAR) // North
        bitmask |= 1 << 0;
    if (y < game->map.size.y - 1 && game->map.grid[y + 1][x] == WALL_CHAR) // South
        bitmask |= 1 << 1;
    if (x > 0 && game->map.grid[y][x - 1] == WALL_CHAR) // West
        bitmask |= 1 << 2;
    if (x < game->map.size.x - 1 && game->map.grid[y][x + 1] == WALL_CHAR) // East
        bitmask |= 1 << 3;

    return bitmask;
    // int bitmask = 0;

    // Debugging: Print indices and dimensions
    // printf("Calculating bitmask for x: %d, y: %d\n", x, y);
    // printf("Grid dimensions: width: %d, height: %d\n", game->map.size.x, game->map.size.y);
	// printf(game->map.grid[])
    // Check north
    // if (y > 0)
	// {
    //     printf("North value: %c\n", game->map.grid[y - 1][x]);
    //     if (game->map.grid[y - 1][x] == WALL_CHAR)
    //         bitmask |= 1 << 0;
    // }

    // // Check south
    // if (y < game->map.size.y - 1) {
    //     printf("South value: %c\n", game->map.grid[y + 1][x]);
    //     if (game->map.grid[y + 1][x] == WALL_CHAR)
    //         bitmask |= 1 << 1;
    // }

    // // Check west
    // if (x > 0) {
    //     printf("West value: %c\n", game->map.grid[y][x - 1]);
    //     if (game->map.grid[y][x - 1] == WALL_CHAR)
    //         bitmask |= 1 << 2;
    // }

    // // Check east
    // if (x < game->map.size.x - 1) {
    //     printf("East value: %c\n", game->map.grid[y][x + 1]);
    //     if (game->map.grid[y][x + 1] == WALL_CHAR)
    //         bitmask |= 1 << 3;
    // }
	// ft_printf("%d", bitmask);
    // return (0);
}


void ft_draw_wall_bitmask_sprite(t_game *game, t_point grid_pos, t_point camera_pos)
{
	int		bitmask;
	void	*sprite;
	void	*wall_sprites[16];

	ft_init_wall_bit_masking(game, wall_sprites);
	bitmask = ft_calculate_wall_bitmask(game, grid_pos.y, grid_pos.x);
	sprite = wall_sprites[bitmask];
	ft_put_sprite(game, sprite, (t_point){camera_pos.x, camera_pos.y});//this is fucking dump why you do that
	//check when you do it a remplace by the value.
	//mlx_put_image_to_window(game->mlx, game->win, game->wall.wall_sprites[bitmask], pos.x, pos.y);
}

// J'aimerais convertir mes fichier png en xpm avec la fonction
// convert , a la taille 64
// exemple convert image_frame_0.xpm --scale 64x64 image_frame_0.xpm
// pour rescale un xpm par example,
// voici la configuration de mon dossier


// ├── WAAAAAAAAAALLLLLLLLLLLLL-00-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-00-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-00-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-01-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-01-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-01-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-02-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-02-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-02-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-03-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-03-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-03-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-04-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-04-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-04-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-05-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-05-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-05-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-06-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-06-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-06-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-07-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-07-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-07-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-08-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-08-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-08-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-09-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-09-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-09-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-10-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-10-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-10-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-11-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-11-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-11-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-12-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-12-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-12-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-13-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-13-01.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-13-02.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-14-00.png
// ├── WAAAAAAAAAALLLLLLLLLLLLL-14-01.png
// └── WAAAAAAAAAALLLLLLLLLLLLL-14-02.png

// WAAAAAAAAAALLLLLLLLLLLLL-00-00.png donneras par example wall_north_frame_1.xpm

// pour chaque [wall].[00].[00].png le premier nombre [00] correspond au nom apres wall_[nom]_frame_[framenumber].xpm

// 00: no_neighbors_four_direction
// 01: east
// 02: north
// 03: north_plus_east
// 04: west
// 05: west_plus_east
// 06: north_west
// 07: north_plus_west_plus_east
// 08: south
// 09: south_plus_east
// 10: north_plus_south
// 11: north_plus_south_plus_east
// 12: south_plus_west
// 13: south_plus_west_plus_east
// 14: north_plus_south_plus_west_plus_east
// 15: north_plus_south_plus_west

// pour chaque [wall].[00].[00].png le deuxieme nombre [00] correspond au nombre de frame 0 1 2

// 0 (0000): No neighboring walls
// 1 (0001): North
// 2 (0010): South
// 3 (0011): North, South
// 4 (0100): West
// 5 (0101): North, West
// 6 (0110): South, West
// 7 (0111): North, South, West
// 8 (1000): East
// 9 (1001): North, East
// 10 (1010): South, East
// 11 (1011): North, South, East
// 12 (1100): West, East
// 13 (1101): North, West, East
// 14 (1110): South, West, East
// 15 (1111): North, South, West, East

// 1st bit (0001): North
// 2nd bit (0010): South
// 3rd bit (0100): West
// 4th bit (1000): East

// // Define Bitmask Values: Assign a bitmask value to
// // each possible surrounding tile configuration.
// // For example, if a wall tile has neighboring wall tiles
// // to the north, south, east, and west, it might have a
// // bitmask value of 1111 in binary, which corresponds to 15 in decimal.
