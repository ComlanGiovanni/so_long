/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:17 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 15:33:56 by gicomlan         ###   ########.fr       */
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
	else if (next_tile == LAVA_CHAR || next_tile == KEKE_CHAR)
		ft_player_get_hit(game);
	else if (next_tile == PAWN_CHAR)
		game->state = STATE_LOSE;
	else if (next_tile == EXIT_CHAR && game->map.info.nbr_key == game->player.storage)
		game->state = STATE_WIN;
}

// void	ft_handle_tile_action(t_game *game, char next_tile)
// {
// 	if (next_tile == LOVE_CHAR)
// 	{
// 		if (game->player.life < 6)
// 			ft_player_take_life(game);
// 		else
// 		{
// 			ft_baba_forbidden(game);
// 			return ;
// 		}
// 	}
// 	if (next_tile == KEY_CHAR)
// 		ft_player_take_coin(game);
// 	if (next_tile == LAVA_CHAR)
// 		ft_player_get_hit(game);
// 	if (next_tile == EXIT_CHAR
// 		&& game->map.info.nbr_key == game->player.storage)
// 		ft_win_game(game);
// }

/**
 * @brief
 *
 * 		those fct are use in ft_input_manager in input_bonus.c
 * 				just game design game feeling we change the
 * 			player curent sprite aka the only one use as primary
 * 		frame_0 et the loaded sprit move int load player sprite bonus
 * 		we is use only when the player more or try to move so it why
 * 			when change the frame when we press the key so signal to to
 * 		true gamer that is input is well register but not et step varaible
 * 		we change the direction map player info to the direction we press
 * 			for the print in the console and the screen
 * 		ft_put_all_sprites_to_line/ft_player_sprite_call need it too
 * 	 because we call that first fct everytime to print all the char of strmap
 *
 * @param game
 */

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
