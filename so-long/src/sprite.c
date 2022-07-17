/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:53 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/16 23:32:22 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_sprites	ft_init_sprites(void *mlx)
{
	t_sprites	sprite;
	int			width;
	int			height;

	// fct for missing file for better read
	//ft print error spite 
	//verify header error name
	if ((sprite.player = mlx_xpm_file_to_image(mlx, "player.xpm", &width, &height)) == NULL)
		ft_print_error(PLAYER_XPM_ERROR);
	if ((sprite.ground = mlx_xpm_file_to_image(mlx, "ground.xpm", &width, &height)) == NULL)
		ft_print_error(GROUND_XPM_ERROR);
	if ((sprite.wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height)) == NULL)
		ft_print_error(WALL_XPM_ERROR);
	if ((sprite.key = mlx_xpm_file_to_image(mlx, "key.xpm", &width, &height)) == NULL)
		ft_print_error(KEY_XPM_ERROR);
	if ((sprite.exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &width, &height)) == NULL)
		ft_print_error(EXIT_XPM_ERROR);
	
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
	if (game->map[height * game->width + width] == WALL_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.wall, width * 64, height * 64);
	else if (game->map[height * game->width + width] == COIN_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.key, width * 64, height * 64);
	else if (game->map[height * game->width + width] == PLAYER_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.player, width * 64, height * 64);
	else if (game->map[height * game->width + width] == EXIT_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.exit, width * 64, height * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.ground, width * 64, height * 64);
}
