/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_system_mouse_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:35:28 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:22:19 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// Main function to check mouse hover and handle button clicks
void	ft_check_mouse_hover(t_game *game)
{
	t_button_info	button_states[0x4];
	int				num_buttons;
	int				index;

	ft_get_button_states(game, button_states, &num_buttons);
	if (num_buttons == 0x0)
		return ;
	index = 0x0;
	while (index < num_buttons)
	{
		if (ft_is_mouse_over_button(button_states[index].button, \
			game->mouse.mouse_position.x, game->mouse.mouse_position.y))
		{
			game->menu.selected_button = index;
			if (ft_strcmp(game->mouse.button_name, MOUSE_LEFT_CLICK) == 0x0)
			{
				game->mouse.button_name = "";
				ft_handle_button_click(game, index, button_states);
			}
			break ;
		}
		index++;
	}
}

//t_point ?
int	ft_is_mouse_over_button(t_button *button, int x, int y)
{
	return ((x >= button->position.x) \
		&& (x <= (button->position.x + button->width))
		&& (y >= button->position.y) \
		&& (y <= (button->position.y + button->height)));
}

void	ft_get_button_states(t_game *game, t_button_info *button_states, \
	int *number_of_button)
{
	if (game->state == STATE_MENU)
	{
		ft_init_buttons_menu_state(button_states, game);
		*number_of_button = 0x3;
	}
	else if (game->state == STATE_PAUSED)
	{
		ft_init_buttons_pause_state(button_states, game);
		*number_of_button = 0x4;
	}
	else if (game->state == STATE_WIN || game->state == STATE_LOSE)
	{
		ft_init_buttons_win_lose_state(button_states, game);
		*number_of_button = 0x3;
	}
	else
		*number_of_button = 0x0;
}

// Function to handle button click
void	ft_handle_button_click(t_game *game, int button_index, \
	t_button_info *button_states)
{
	if ((button_index >= 0x0) && (button_index < 0x4))
		button_states[button_index].action(game);
}
