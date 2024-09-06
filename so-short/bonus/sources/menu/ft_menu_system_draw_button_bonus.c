/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_system_draw_button_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:36:02 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 21:09:10 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_draw_button(t_game *game, t_button *button)
{
	if (button->is_hovered)
		mlx_put_image_to_window(game->mlx, game->win, button->img_hover, \
			button->position.x, button->position.y);
	else
		mlx_put_image_to_window(game->mlx, game->win, button->img_normal, \
			button->position.x, button->position.y);
}

void	ft_draw_main_menu(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->menu.game_welcome, ((game->window.width / 0x2) - 290), 0x5);
	game->menu.quit_button.position.x = ((game->window.width / 0x2) - 131);
	ft_draw_button(game, &game->menu.start_button);
	ft_draw_button(game, &game->menu.levels_button);
	ft_draw_button(game, &game->menu.quit_button);
}

void	ft_draw_pause_menu(t_game *game)
{
	game->menu.quit_button.position.x = ((game->window.width / 0x2) - 171);
	ft_draw_button(game, &game->menu.resume_button);
	ft_draw_button(game, &game->menu.restart_button);
	ft_draw_button(game, &game->menu.main_menu_button);
	ft_draw_button(game, &game->menu.quit_button);
}

void	ft_draw_win_menu(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->menu.game_win, ((game->window.width / 0x2) - 300), 50);
	game->menu.quit_button.position.x = ((game->window.width / 0x2) - 171);
	ft_draw_button(game, &game->menu.restart_button);
	ft_draw_button(game, &game->menu.main_menu_button);
	ft_draw_button(game, &game->menu.quit_button);
}

void	ft_draw_game_over_menu(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->menu.game_over, ((game->window.width / 0x2) - 298), 50);
	game->menu.quit_button.position.x = ((game->window.width / 0x2) - 171);
	ft_draw_button(game, &game->menu.restart_button);
	ft_draw_button(game, &game->menu.main_menu_button);
	ft_draw_button(game, &game->menu.quit_button);
}
