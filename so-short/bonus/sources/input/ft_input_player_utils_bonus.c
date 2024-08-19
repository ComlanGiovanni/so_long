/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_player_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:52:59 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/19 21:10:22 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	if (y > 0x0)
		ft_move_player(game, x, (y - 0x1));
}

void	ft_move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	if (y < (game->height - 0x1))
		ft_move_player(game, x, (y + 0x1));
}

void	ft_move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	if (x > 0x0)
		ft_move_player(game, (x - 0x1), y);
}

void	ft_move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	if (x < (game->width - 0x1))
		ft_move_player(game, (x + 0x1), y);
}
