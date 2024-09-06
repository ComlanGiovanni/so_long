/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_buttons_menu_state_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:47:42 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:21:22 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_buttons_is_hovered(t_game *game)
{
	game->menu.start_button.is_hovered = 0x0;
	game->menu.levels_button.is_hovered = 0x0;
	game->menu.quit_button.is_hovered = 0x0;
	game->menu.resume_button.is_hovered = 0x0;
	game->menu.main_menu_button.is_hovered = 0x0;
	game->menu.restart_button.is_hovered = 0x0;
}

void	ft_init_buttons_size(t_game *game)
{
	game->menu.start_button.width = 238;
	game->menu.start_button.height = 20;
	game->menu.quit_button.width = 238;
	game->menu.quit_button.height = 20;
	game->menu.restart_button.width = 238;
	game->menu.restart_button.height = 20;
	game->menu.main_menu_button.width = 238;
	game->menu.main_menu_button.height = 20;
	game->menu.resume_button.width = 238;
	game->menu.resume_button.height = 20;
	game->menu.levels_button.width = 238;
	game->menu.levels_button.height = 20;
}

void	ft_init_buttons_menu_state(t_button_info *button_states, t_game *game)
{
	button_states[0x0].button = &game->menu.start_button;
	button_states[0x0].action = ft_start_game;
	button_states[0x1].button = &game->menu.levels_button;
	button_states[0x1].action = ft_play_levels;
	button_states[0x2].button = &game->menu.quit_button;
	button_states[0x2].action = (void *)ft_exit_game;
}

void	ft_init_buttons_pause_state(t_button_info *button_states, t_game *game)
{
	button_states[0x0].button = &game->menu.resume_button;
	button_states[0x0].action = ft_resume_game;
	button_states[0x1].button = &game->menu.restart_button;
	button_states[0x1].action = ft_restart_game;
	button_states[0x2].button = &game->menu.main_menu_button;
	button_states[0x2].action = ft_return_to_main_menu;
	button_states[0x3].button = &game->menu.quit_button;
	button_states[0x3].action = (void *)ft_exit_game;
}

void	ft_init_buttons_win_lose_state(t_button_info *button_states, \
	t_game *game)
{
	button_states[0x0].button = &game->menu.restart_button;
	button_states[0x0].action = ft_restart_game;
	button_states[0x1].button = &game->menu.main_menu_button;
	button_states[0x1].action = ft_return_to_main_menu;
	button_states[0x2].button = &game->menu.quit_button;
	button_states[0x2].action = (void *)ft_exit_game;
}
