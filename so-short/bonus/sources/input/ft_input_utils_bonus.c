/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:17 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/28 13:23:09 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_handle_tile_action(t_game *game, char next_tile)
{
	if (next_tile == LOVE_CHAR)
	{
		if (game->player.life < 6)
			ft_player_take_life(game);
		else
		{
			ft_baba_forbidden(game);
			return ;
		}
	}
	else if (next_tile == KEY_CHAR)
		ft_player_take_coin(game);
	else if (next_tile == LAVA_CHAR || next_tile == MONSTER_CHAR)
		ft_player_get_hit(game);
	else if (next_tile == EXIT_CHAR \
		&& game->map.info.nbr_key == game->player.storage)
	{
		ft_win_game(game);
		game->state = STATE_WIN;
	}
}

void	ft_input_up(t_game *game)
{
	game->player.up_anim.current = game->player.up_anim.frame_move;
	game->player.movement.direction = 'u';
	game->player.movement.moved = TRUE;
	ft_move_up(game);
}

void	ft_input_down(t_game *game)
{
	game->player.down_anim.current = game->player.down_anim.frame_move;
	game->player.movement.direction = 'd';
	game->player.movement.moved = TRUE;
	ft_move_down(game);
}

void	ft_input_left(t_game *game)
{
	game->player.left_anim.current = game->player.left_anim.frame_move;
	game->player.movement.direction = 'l';
	game->player.movement.moved = TRUE;
	ft_move_left(game);
}

void	ft_input_right(t_game *game)
{
	game->player.right_anim.current = game->player.right_anim.frame_move;
	game->player.movement.direction = 'r';
	game->player.movement.moved = TRUE;
	ft_move_right(game);
}
