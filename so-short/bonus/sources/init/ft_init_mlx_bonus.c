/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:22:23 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/03 15:20:56 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_print_error(MLX_INIT_ERROR, game);
}

void	ft_init_mouse(t_game *game)
{
	game->mouse.button_name = "";
	game->mouse.mouse_position.x = 0x0;
	game->mouse.mouse_position.y = 0x0;
	game->mouse.mouse_button_key_code = -1;
}

void	ft_create_window(t_game *game)
{
	ft_printf(SCREEN_SIZE_PRINT"[%d x %d]\n", \
		game->screen.y, game->screen.x);
	game->window.width = ((game->width * IMG_SIZE) / 0x2);
	game->window.height = ((game->height * IMG_SIZE) / 0x2);
	ft_printf(WINDOW_SIZE_PRINT"[%d x %d]\n", \
	game->window.height, game->window.width);
	game->win = mlx_new_window(game->mlx, game->window.width,
			game->window.height, GAME_TITLE);
	if (game->win == NULL)
		ft_print_error(MLX_WINDOW_ERROR, game);
	game->key_collected = 0x0;
	ft_init_mouse(game);
	game->state = STATE_MENU;
}
