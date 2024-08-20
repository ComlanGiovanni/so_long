/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_wall_bit_mask_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:07:25 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 20:24:56 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

static int	ft_calculate_wall_bitmask(t_game *game, int x, int y)
{
	static int	bitmask;

	bitmask = 0x0;
	if ((y > 0x0) && game->map.grid[y - 0x1][x] == WALL_CHAR)
		bitmask |= 0x1 << 0x0;
	if (y < game->map.size.y - 1 && game->map.grid[y + 0x1][x] == WALL_CHAR)
		bitmask |= 0x1 << 0x1;
	if ((x > 0x0) && game->map.grid[y][x - 0x1] == WALL_CHAR)
		bitmask |= 0x1 << 0x2;
	if (x < game->map.size.x - 0x1 && game->map.grid[y][x + 0x1] == WALL_CHAR)
		bitmask |= 0x1 << 0x3;
	return (bitmask);
}

void	ft_draw_wall_bitmask_sprite(t_game *game, t_point grid_pos,
		t_point camera_pos)
{
	int		bitmask;
	void	*sprite;
	void	*wall_sprites[0x10];

	ft_init_wall_bit_masking(game, wall_sprites);
	bitmask = ft_calculate_wall_bitmask(game, grid_pos.y, grid_pos.x);
	sprite = wall_sprites[bitmask];
	ft_put_sprite(game, sprite, (t_point){camera_pos.x, camera_pos.y});//this is fucking dump why you do that
}
