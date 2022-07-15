/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:53 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/15 01:53:36 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_sprites	ft_init_sprites(void *mlx)
{
	t_sprites	sprite;
	int			width;
	int			height;

    if ((sprite.player_left = mlx_xpm_file_to_image(mlx, "player_left.xpm", &width, &height)) == NULL)
		ft_print_error(PLAYER_L_XPM_ERROR);
	if ((sprite.player_right = mlx_xpm_file_to_image(mlx, "player_right.xpm", &width, &height)) == NULL)
		ft_print_error(PLAYER_R_XPM_ERROR);
	if ((sprite.player_down = mlx_xpm_file_to_image(mlx, "player_down.xpm", &width, &height)) == NULL)
		ft_print_error(PLAYER_D_XPM_ERROR);
	if ((sprite.player_up = mlx_xpm_file_to_image(mlx, "player_up.xpm", &width, &height)) == NULL)
		ft_print_error(PLAYER_U_XPM_ERROR);
	if ((sprite.ground = mlx_xpm_file_to_image(mlx, "ground.xpm", &width, &height)) == NULL)
		ft_print_error(GROUND_XPM_ERROR);
	if ((sprite.wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height)) == NULL)
		ft_print_error(WALL_XPM_ERROR);
	if ((sprite.coin = mlx_xpm_file_to_image(mlx, "key.xpm", &width, &height)) == NULL)
		ft_print_error(KEY_XPM_ERROR);
	if ((sprite.exit_1 = mlx_xpm_file_to_image(mlx, "exit_1.xpm", &width, &height)) == NULL)
		ft_print_error(EXIT_1_XPM_ERROR);
	if ((sprite.exit_2 = mlx_xpm_file_to_image(mlx, "exit_2.xpm", &width, &height)) == NULL)
		ft_print_error(EXIT_2_XPM_ERROR);
/*
	sprite.player = mlx_xpm_file_to_image(mlx, "player.xpm", &width, &height);
	sprite.ground = mlx_xpm_file_to_image(mlx, "ground.xpm", &width, &height);
	sprite.wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height);
	sprite.coin = mlx_xpm_file_to_image(mlx, "coin.xpm", &width, &height);
	sprite.exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &width, &height);
	sprite.house = mlx_xpm_file_to_image(mlx, "house.xpm", &width, &height);
*/
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
	//int wid ---> game->wid game->direction = 'r'
	if (game->map[height * game->width + width] == WALL_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.wall, width * 64, height * 64);
	else if (game->map[height * game->width + width] == COIN_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.coin, width * 64, height * 64);
	else if (game->map[height * game->width + width] == PLAYER_CHAR && game->direction == 'd')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.player_down, width * 64, height * 64);
	else if (game->map[height * game->width + width] == PLAYER_CHAR && game->direction == 'u')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.player_up, width * 64, height * 64);
	else if (game->map[height * game->width + width] == PLAYER_CHAR && game->direction == 'l')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.player_left, width * 64, height * 64);
	else if (game->map[height * game->width + width] == PLAYER_CHAR && game->direction == 'r')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.player_right, width * 64, height * 64);
	else if (game->map[height * game->width + width] == EXIT_CHAR && game->storage == game->coin)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.exit_2, width * 64, height * 64);
	else if (game->map[height * game->width + width] == EXIT_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.exit_1, width * 64, height * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.ground, width * 64, height * 64);
}
