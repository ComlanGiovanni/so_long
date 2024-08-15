/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_wall_bit_mask_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:07:25 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 23:07:44 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// typedef struct s_game {

//     void *wall_sprites[16]; // Array of wall sprites based on bitmask
// } t_game;

// int calculate_wall_bitmask(t_game *game, int x, int y) {
//     int bitmask = 0;

//     // Check north
//     if (y > 0 && game->grid[y - 1][x] == WALL_CHAR)
//         bitmask |= 1 << 0;
//     // Check south
//     if (y < GRID_HEIGHT - 1 && game->grid[y + 1][x] == WALL_CHAR)
//         bitmask |= 1 << 1;
//     // Check west
//     if (x > 0 && game->grid[y][x - 1] == WALL_CHAR)
//         bitmask |= 1 << 2;
//     // Check east
//     if (x < GRID_WIDTH - 1 && game->grid[y][x + 1] == WALL_CHAR)
//         bitmask |= 1 << 3;

//     return bitmask;
// }

// void ft_draw_wall_sprite(t_game *game, int x, int y, t_point pos) {
//     int bitmask = calculate_wall_bitmask(game, x, y);
//     void *sprite = game->wall_sprites[bitmask];
//     mlx_put_image_to_window(game->mlx, game->win, sprite, pos.x, pos.y);
// }

// 0: No neighbors
// 1: North
// 2: South
// 3: North + South
// 4: West
// 5: North + West
// 6: South + West
// 7: North + South + West
// 8: East
// 9: North + East
// 10: South + East
// 11: North + South + East
// 12: West + East
// 13: North + West + East
// 14: South + West + East
// 15: All sides (North + South + West + East)

// Define Bitmask Values: Assign a bitmask value to
// each possible surrounding tile configuration.
// For example, if a wall tile has neighboring wall tiles
// to the north, south, east, and west, it might have a
// bitmask value of 1111 in binary, which corresponds to 15 in decimal.
