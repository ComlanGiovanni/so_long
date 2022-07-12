/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:53 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/12 16:28:58 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_init_sprites(void *mlx)
{
	t_sprites	sprite;
	int		width;
	int		height;

	sprite.wall = mlx_xpm_file_to_image(mlx, "./img/xpm/wall.xpm", &width, &height);
	sprite.player = mlx_xpm_file_to_image(mlx, "./img/xpm/player.xpm", &width, &height);

	return (EXIT_SUCCESS);
}

void	ft_put_sprites_by_line(t_game *game)
{
	int		width;
	int		height;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			ft_put_all_sprites_to_line(game, width, height);
			width++;
		}
		height++;
	}
}

void	ft_put_all_sprites_to_line(t_game *g, int width, int height)
{
	if (== WALL_CHAR)
		mlx_put_image_to_window();
	else if (== COLLECTIBLE_CHAR)
		mlx_put_image_to_window();
	else if ( == PLAYER_CHAR)
		mlx_put_image_to_window();
	else if (== EXIT_CHAR)
		mlx_put_image_to_window();
	else
		mlx_put_image_to_window();
}

