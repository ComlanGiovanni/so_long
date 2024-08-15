/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_wall_simple_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:08:34 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:14:26 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// typedef struct s_walls {
//     t_animation top_left;
//     t_animation top_right;
//     t_animation bottom_left;
//     t_animation bottom_right;
//     t_animation horizontal;
//     t_animation vertical;
// } t_walls;

// void ft_wall_sprite(t_game *game, t_point pos, int width, int height) {
//     void *sprite = NULL;
//     if (width == 0 && height == 0) {
//         sprite = game->wall.top_left.current;
//     } else if (width == game->map.size.x - 1 && height == 0) {
//         sprite = game->wall.top_right.current;
//     } else if (width == 0 && height == game->map.size.y - 1) {
//         sprite = game->wall.bottom_left.current;
//     } else if (width == game->map.size.x - 1 &&
//			height == game->map.size.y - 1) {
//         sprite = game->wall.bottom_right.current;
//     } else if (height == 0 || height == game->map.size.y - 1) {
//         sprite = game->wall.horizontal.current;
//     } else if (width == 0 || width == game->map.size.x - 1) {
//         sprite = game->wall.vertical.current;
//     }
//     if (sprite) {
//         mlx_put_image_to_window(game->mlx, game->win, sprite, pos.x, pos.y);
//     }
// }
