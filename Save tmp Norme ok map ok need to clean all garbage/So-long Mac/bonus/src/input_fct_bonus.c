/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fct_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:42:25 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 16:49:47 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	ft_input_up(t_game *game)
{
	game->player.up_anim.frame_0 = game->player.up_anim.frame_move;
	game->player.direction = 'u';
	ft_move_up(game);
}

void	ft_input_down(t_game *game)
{
	game->player.down_anim.frame_0 = game->player.down_anim.frame_move;
	game->player.direction = 'd';
	ft_move_down(game);
}

void	ft_input_left(t_game *game)
{
	game->player.left_anim.frame_0 = game->player.left_anim.frame_move;
	game->player.direction = 'l';
	ft_move_left(game);
}

void	ft_input_right(t_game *game)
{
	game->player.right_anim.frame_0 = game->player.right_anim.frame_move;
	game->player.direction = 'r';
	ft_move_right(game);
}
