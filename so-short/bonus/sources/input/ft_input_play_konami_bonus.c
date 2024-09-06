/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_play_konami_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:20:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 19:07:17 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//display_message on scree ->> KONAMI BODE ACTIVTED OR JUST KONAMI CODE
// or 42 life get etc
void	ft_trigger_konami_effect(t_game *game)
{
	ft_printf("Konami Code Activated! %s\n", game->map.map_name);
	game->player.life = 42;
}

void	ft_check_konami_code(t_game *game, int key_code)
{
	static const int	konami_code[0xa] = {
		LINUX_UP_ARROW_KEY, LINUX_UP_ARROW_KEY,
		LINUX_DOWN_ARROW_KEY, LINUX_DOWN_ARROW_KEY,
		LINUX_LEFT_ARROW_KEY, LINUX_RIGHT_ARROW_KEY,
		LINUX_LEFT_ARROW_KEY, LINUX_RIGHT_ARROW_KEY,
		LINUX_A_KEY, LINUX_B_KEY};
	static int			index = 0x0;

	if (key_code == konami_code[index])
	{
		index++;
		if (index == 0xa)
		{
			ft_trigger_konami_effect(game);
			index = 0x0;
		}
	}
	else
		index = 0x0;
}
