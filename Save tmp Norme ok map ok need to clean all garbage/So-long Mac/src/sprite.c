/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:53 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 23:33:10 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief 
 * 
 * @param mlx 
 * @return t_sprites 
 */
t_sprites	ft_init_sprites(void *mlx)
{
	t_sprites	sprite;
	int			width;
	int			height;

	sprite.player = mlx_xpm_file_to_image(mlx,
			"assets/xpm/Mandatory/player.xpm", &width, &height);
	if (sprite.player == NULL)
		ft_print_error(PLAYER_XPM_ERROR);
	sprite.ground = mlx_xpm_file_to_image(mlx,
			"assets/xpm/Mandatory/ground.xpm", &width, &height);
	if (sprite.ground == NULL)
		ft_print_error(GROUND_XPM_ERROR);
	sprite.wall = mlx_xpm_file_to_image(mlx,
			"assets/xpm/Mandatory/wall.xpm", &width, &height);
	if (sprite.wall == NULL)
		ft_print_error(WALL_XPM_ERROR);
	sprite.key = mlx_xpm_file_to_image(mlx,
			"assets/xpm/Mandatory/key.xpm", &width, &height);
	if (sprite.key == NULL)
		ft_print_error(KEY_XPM_ERROR);
	sprite.exit = mlx_xpm_file_to_image(mlx,
			"assets/xpm/Mandatory/exit.xpm", &width, &height);
	if (sprite.exit == NULL)
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
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.wall, width * 64, height * 64);
	else if (game->map[height * game->width + width] == COIN_CHAR)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.key, width * 64, height * 64);
	else if (game->map[height * game->width + width] == PLAYER_CHAR)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.player, width * 64, height * 64);
	else if (game->map[height * game->width + width] == EXIT_CHAR)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.exit, width * 64, height * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.ground, width * 64, height * 64);
}

/*
int temp;
int temp1;
int temp11;
int temp111;

Because using temp2, temp3 would be too mainstream.

char coal

float away; 
long long ago;

char mander; 
long timeAgo;	// In a galaxy far far away 
bool dozer; 
int erNalExam; 
 
short circuit; 
short onTime; 
double trouble; 
Exception up = new Exception("Something is wrong"); 
throw up; 


*/

void	ft_anal_yze_line(char	*line)
{
	if (line == NULL)
		ft_print_error(BITCHISEMPTY);
}