/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_system_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:10:12 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:50:12 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// Implémentez ici la logique pour réinitialiser
//le jeu pour le menu principal
// Par exemple : libérer les ressources du niveau actuel,
//réinitialiser les scores, etc.

// Function to get the current menu state based on the game state
void	ft_get_menu_state(t_game *game, t_menu_state *current_state)
{
	if (game->state == STATE_MENU)
	{
		current_state->num_buttons = 0x3;
		current_state->button_actions[0x0] = ft_start_game;
		current_state->button_actions[0x1] = ft_play_levels;
		current_state->button_actions[0x2] = (void *)ft_exit_game;
	}
	else if (game->state == STATE_PAUSED)
	{
		current_state->num_buttons = 0x4;
		current_state->button_actions[0x0] = ft_resume_game;
		current_state->button_actions[0x1] = ft_restart_game;
		current_state->button_actions[0x2] = ft_return_to_main_menu;
		current_state->button_actions[0x3] = (void *)ft_exit_game;
	}
	else if (game->state == STATE_WIN || game->state == STATE_LOSE)
	{
		current_state->num_buttons = 0x3;
		current_state->button_actions[0x0] = ft_restart_game;
		current_state->button_actions[0x1] = ft_return_to_main_menu;
		current_state->button_actions[0x2] = (void *)ft_exit_game;
	}
	else
		current_state->num_buttons = 0x0;
}

void	ft_update_selected_button(t_game *game, int key_code, \
	int number_of_buttons)
{
	if (key_code == LINUX_UP_ARROW_KEY || key_code == LINUX_W_KEY)
	{
		game->menu.selected_button--;
		if (game->menu.selected_button < 0x0)
			game->menu.selected_button = number_of_buttons - 0x1;
	}
	else if (key_code == LINUX_DOWN_ARROW_KEY || key_code == LINUX_S_KEY)
	{
		game->menu.selected_button++;
		if (game->menu.selected_button >= number_of_buttons)
			game->menu.selected_button = 0x0;
	}
}

void	ft_menu_input_manager(t_game *game, int key_code)
{
	t_menu_state	current_state;

	ft_get_menu_state(game, &current_state);
	if (current_state.num_buttons == 0x0)
		return ;
	if (game->state == STATE_PAUSED && key_code == LINUX_LETTER_P)
	{
		ft_toggle_pause(game);
		return ;
	}
	ft_update_selected_button(game, key_code, current_state.num_buttons);
	if (key_code == LINUX_ENTER_KEY)
	{
		if (game->menu.selected_button >= 0x0 \
			&& (game->menu.selected_button < current_state.num_buttons))
			current_state.button_actions[game->menu.selected_button](game);
	}
}
