/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:53 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/13 00:45:58 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_sprites	ft_init_sprites(void *mlx)
{
	t_sprites	sprite;
	int		width;
	int		height;

	sprite.player = mlx_xpm_file_to_image(mlx, "./img/xpm/player.xpm", &width, &height);
	sprite.ground = mlx_xpm_file_to_image(mlx, "./img/xpm/ground.xpm", &width, &height);
	sprite.wall = mlx_xpm_file_to_image(mlx, "./img/xpm/wall.xpm", &width, &height);
	sprite.coin = mlx_xpm_file_to_image(mlx, "./img/xpm/coin.xpm", &width, &height);
	sprite.exit = mlx_xpm_file_to_image(mlx, "./img/xpm/exit.xpm", &width, &height);
	return (sprite);
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

void	ft_put_all_sprites_to_line(t_game *game, int width, int height)
{
    //add fleche
	if (game->map[height * game->width + width] == WALL_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.wall, width * 64, height * 64);
	else if (game->map[height * game->width + width] == COLLECTIBLE_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.coin, width * 64, height * 64);
	else if (game->map[height * game->width + width] == PLAYER_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.player, width * 64, height * 64);
	else if (game->map[height * game->width + width] == EXIT_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.exit, width * 64, height * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.ground, width * 64, height * 64);
}
