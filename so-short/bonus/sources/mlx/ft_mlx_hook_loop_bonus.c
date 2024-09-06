/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook_loop_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:09:22 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 16:18:49 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

	//ft_printf("cou%dcou\n", mouse_button_key_code);
	// if (mouse_button_key_code == LINUX_MOUSE_LEFT_CLICK_KEY)
	// {
	// 	game->mouse.button_name = MOUSE_LEFT_CLICK;
	// 	if (game->state == STATE_MENU)
	// 	{
	// 		if (game->menu.start_button.is_hovered)
	// 		{
	// 			game->state = STATE_PLAYING;
	// 			ft_play_random_theme();
	// 		}
	// 		else if (game->menu.levels_button.is_hovered)
	// 		{
	// 			ft_printf("Levels button clicked\n");
	// 		}
	// 		else if (game->menu.quit_button.is_hovered)
	// 			ft_exit_game(game);
	// 	}
	// }
int	ft_mouse_manager(int mouse_button_key_code, int x, int y, t_game *game)
{
	if (mouse_button_key_code == LINUX_MOUSE_MIDDLE_CLICK_KEY)
		game->mouse.button_name = MOUSE_MIDDLE_CLICK;
	else if (mouse_button_key_code == LINUX_MOUSE_RIGHT_CLICK_KEY)
		game->mouse.button_name = MOUSE_RIGHT_CLICK;
	else if (mouse_button_key_code == LINUX_MOUSE_LEFT_CLICK_KEY)
		game->mouse.button_name = MOUSE_LEFT_CLICK;
	else if (mouse_button_key_code == LINUX_MOUSE_SCROLL_UP_KEY)
		game->mouse.button_name = MOUSE_SCROLL_UP;
	else if (mouse_button_key_code == LINUX_MOUSE_SCROLL_DOWN_KEY)
		game->mouse.button_name = MOUSE_SCROLL_DOWN;
	else
		game->mouse.button_name = MOUSE_UNKNOW_CLICK;
	game->mouse.mouse_position.x = x;
	game->mouse.mouse_position.y = y;
	game->mouse.mouse_button_key_code = mouse_button_key_code;
	return (0x0);
}

void	ft_mlx_hook_loop(t_game *game)
{
	mlx_do_key_autorepeaton(game->mlx);
	mlx_hook(game->win, LINUX_KEY_PRESS, TRUE, &ft_input_manager, game);
	mlx_mouse_hook(game->win, ft_mouse_manager, game);
	mlx_hook(game->win, LINUX_CLOSE_ICON, TRUE, &ft_exit_game, game);
	mlx_loop_hook(game->mlx, &ft_update, game);
	mlx_loop(game->mlx);
}
