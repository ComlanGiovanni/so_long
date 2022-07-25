/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lava_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:51:50 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/22 15:05:32 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_mac/so_long_bonus_mac.h"

/**
 * @brief 
 * 
 * 						Comment for the whole file
 * 
 * 			so now that the direction of the lava is set 
 * 				in ft_random_lava_move we can now
 * 					check to direction to go aka the fct to call,
 * 					there its the same logic as
 * 			the management of the player input, 
 * 						we loop in all the map and if we found a
 * 					lava we apply this rule, if there is not wall exit key lava key
 * 				love or player char aka everything 
 * 						except void we can move by change the previous
 * 					char L(asset because we are alway printing 
 * 				asset by the map str) by void and the next
 * 					by the lava char, then if we face a player char 
 * 			he lose life and the lava disappear to
 * 						because 0 aka void ground 
 * 
 * 
 * @param game 
 */

void	ft_move_lava(t_game *game)
{
	if (game->lava.move == 'u')
		ft_lava_move_up(game);
	if (game->lava.move == 'd')
		ft_lava_move_down(game);
	if (game->lava.move == 'l')
		ft_lava_move_left(game);
	if (game->lava.move == 'r')
		ft_lava_move_right(game);
}

void	ft_lava_move_up(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx++ < game->map.len)
	{
		if (game->map.map_str[idx] == LAVA_CHAR)
		{
			if (game->map.map_str[idx - game->width] == PLAYER_CHAR)
			{
				game->player.life--;
				game->map.map_str[idx] = VOID_CHAR;
			}
			if (game->map.map_str[idx - game->width] != WALL_CHAR
				&& game->map.map_str[idx - game->width] != EXIT_CHAR
				&& game->map.map_str[idx - game->width] != KEY_CHAR
				&& game->map.map_str[idx - game->width] != LAVA_CHAR
				&& game->map.map_str[idx - game->width] != KEY_CHAR
				&& game->map.map_str[idx - game->width] != LOVE_CHAR
				&& game->map.map_str[idx - game->width] != PLAYER_CHAR)
			{
				game->map.map_str[idx] = VOID_CHAR;
				game->map.map_str[idx - game->width] = LAVA_CHAR;
			}
		}
	}
}

void	ft_lava_move_down(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx++ < game->map.len)
	{
		if (game->map.map_str[idx] == LAVA_CHAR)
		{
			if (game->map.map_str[idx + game->width] == PLAYER_CHAR)
			{
				game->player.life--;
				game->map.map_str[idx] = VOID_CHAR;
			}
			if (game->map.map_str[idx + game->width] != WALL_CHAR
				&& game->map.map_str[idx + game->width] != EXIT_CHAR
				&& game->map.map_str[idx + game->width] != KEY_CHAR
				&& game->map.map_str[idx + game->width] != LAVA_CHAR
				&& game->map.map_str[idx + game->width] != KEY_CHAR
				&& game->map.map_str[idx + game->width] != LOVE_CHAR
				&& game->map.map_str[idx + game->width] != PLAYER_CHAR)
			{
				game->map.map_str[idx] = VOID_CHAR;
				game->map.map_str[idx + game->width] = LAVA_CHAR;
			}
		}
	}
}

void	ft_lava_move_left(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx++ < game->map.len)
	{
		if (game->map.map_str[idx] == LAVA_CHAR)
		{
			if (game->map.map_str[idx - TRUE] == PLAYER_CHAR)
			{
				game->player.life--;
				game->map.map_str[idx] = VOID_CHAR;
			}
			if (game->map.map_str[idx - TRUE] != WALL_CHAR
				&& game->map.map_str[idx - TRUE] != EXIT_CHAR
				&& game->map.map_str[idx - TRUE] != KEY_CHAR
				&& game->map.map_str[idx - TRUE] != LAVA_CHAR
				&& game->map.map_str[idx - TRUE] != KEY_CHAR
				&& game->map.map_str[idx - TRUE] != LOVE_CHAR
				&& game->map.map_str[idx - TRUE] != PLAYER_CHAR)
			{
				game->map.map_str[idx] = VOID_CHAR;
				game->map.map_str[idx - TRUE] = LAVA_CHAR;
			}
		}
	}
}

void	ft_lava_move_right(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx++ < game->map.len)
	{
		if (game->map.map_str[idx] == LAVA_CHAR)
		{
			if (game->map.map_str[idx + TRUE] == PLAYER_CHAR)
			{
				game->player.life--;
				game->map.map_str[idx] = VOID_CHAR;
			}
			if (game->map.map_str[idx + TRUE] != WALL_CHAR
				&& game->map.map_str[idx + TRUE] != EXIT_CHAR
				&& game->map.map_str[idx + TRUE] != KEY_CHAR
				&& game->map.map_str[idx + TRUE] != LAVA_CHAR
				&& game->map.map_str[idx + TRUE] != KEY_CHAR
				&& game->map.map_str[idx + TRUE] != LOVE_CHAR
				&& game->map.map_str[idx + TRUE] != PLAYER_CHAR)
			{
				game->map.map_str[idx] = VOID_CHAR;
				game->map.map_str[idx + TRUE] = LAVA_CHAR;
			}
		}
	}
}
