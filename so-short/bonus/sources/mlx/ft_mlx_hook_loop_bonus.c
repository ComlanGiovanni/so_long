/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook_loop_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:09:22 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 14:13:18 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	ft_mouse_manager(int button, int x, int y, t_game *game)
{
	char	*button_name;
	if (button == 1){//enum_for_mouse_input
		button_name = "Left Click";//maccro
	}
	else if (button == 2)
	{
		button_name = "Right Click";//maccro
		ft_exit_game(game);
	}
	else if (button == 3)
		button_name = "Middle Click";//maccro
	else if (button == 4)
		button_name = "Scroll Up";//maccro
	else if (button == 5)
		button_name = "Scroll Down";//maccro
	else
		button_name = "Unknown Click";//maccro
	//system("clear");
	ft_printf("\n[%d]=", x);//t_mouse position if need
	ft_printf("=[%d]", y);//t_mouse position if need
	ft_printf("%s", button_name);
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
