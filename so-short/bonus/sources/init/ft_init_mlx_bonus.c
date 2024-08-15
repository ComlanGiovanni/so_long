/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:22:23 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 13:43:42 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_print_error(MLX_INIT_ERROR, game);
}

void	ft_create_window(t_game *game)
{
	ft_printf("Screen Height && Width [%d x %d]\n", game->screen.x, game->screen.y);
	game->window.width = ((game->width * IMG_SIZE) / 2);
	game->window.height = ((game->height * IMG_SIZE) / 2);
	ft_printf("Window Height && Width [%d x %d]\n", game->window.height, game->window.width);
	game->win = mlx_new_window(game->mlx, game->window.width,
			game->window.height, GAME_TITLE);
	if (game->win == NULL)
		ft_print_error(MLX_WINDOW_ERROR, game);
	game->key_collected = 0;
}
