/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_buttons_assets_one_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:17:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:24:09 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_restart_buttons_sprites(t_game *game)
{
	ft_load_sprite_frame(&(game->menu.restart_button.img_normal), game, \
		PATH_ASSET"menu/restart/restart.xpm",
		PATH_ASSET"menu/restart/restart.xpm");
	ft_load_sprite_frame(&(game->menu.restart_button.img_hover), game, \
		PATH_ASSET"menu/restart/restart_hover.xpm",
		PATH_ASSET"menu/restart/restart_hover.xpm");
	ft_load_sprite_frame(&(game->menu.restart_button.img_clicked), game, \
		PATH_ASSET"menu/restart/restart_clicked.xpm",
		PATH_ASSET"menu/restart/restart_clicked.xpm");
}

void	ft_load_return_main_menu_buttons_sprites(t_game *game)
{
	ft_load_sprite_frame(&(game->menu.main_menu_button.img_normal), game, \
		PATH_ASSET"menu/main/return_to_main_menu.xpm",
		PATH_ASSET"menu/main/return_to_main_menu.xpm");
	ft_load_sprite_frame(&(game->menu.main_menu_button.img_hover), game, \
		PATH_ASSET"menu/main/return_to_main_menu_hover.xpm",
		PATH_ASSET"menu/main/return_to_main_menu_hover.xpm");
	ft_load_sprite_frame(&(game->menu.main_menu_button.img_clicked), game, \
		PATH_ASSET"menu/main/return_to_main_menu_clicked.xpm",
		PATH_ASSET"menu/main/return_to_main_menu_clicked.xpm");
}
