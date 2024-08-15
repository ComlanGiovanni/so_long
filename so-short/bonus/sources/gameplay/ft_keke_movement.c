/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keke_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:43:47 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 02:42:16 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_move_keke(t_game *game)
{
	if (game->keke.direction == 'u')
		ft_keke_move_up(game);
	if (game->keke.direction == 'd')
		ft_keke_move_down(game);
	if (game->keke.direction == 'l')
		ft_keke_move_left(game);
	if (game->keke.direction == 'r')
		ft_keke_move_right(game);
}

void	ft_move_keke_up(t_game *game, int row, int col)
{
	if (game->map.grid[row - 1][col] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_keke_obstacle(game->map.grid[row - 1][col]))
	{
		if (game->map.grid[row - 1][col] == BOX_CHAR)
			system("aplay sounds/special-effects/box_destroyed.wav \
				> /dev/null 2>&1 &");
		game->keke.up_anim.current = game->keke.up_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row - 1][col] = KEKE_CHAR;
		game->keke.up_anim.current = game->keke.up_anim.frame_move_1;
	}
}

void	ft_move_keke_down(t_game *game, int row, int col)
{
	if (game->map.grid[row + 1][col] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_keke_obstacle(game->map.grid[row + 1][col]))
	{
		if (game->map.grid[row + 1][col] == BOX_CHAR)
			system("aplay sounds/special-effects/box_destroyed.wav \
				> /dev/null 2>&1 &");
		game->keke.down_anim.current = game->keke.down_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row + 1][col] = KEKE_CHAR;
		game->keke.down_anim.current = game->keke.down_anim.frame_move_1;
	}
}

void	ft_move_keke_left(t_game *game, int row, int col)
{
	if (game->map.grid[row][col - 1] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_keke_obstacle(game->map.grid[row][col - 1]))
	{
		if (game->map.grid[row][col - 1] == BOX_CHAR)
			system("aplay sounds/special-effects/box_destroyed.wav \
				 > /dev/null 2>&1 &");
		game->keke.left_anim.current = game->keke.left_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row][col - 1] = KEKE_CHAR;
		game->keke.left_anim.current = game->keke.left_anim.frame_move_1;
	}
}

void	ft_move_keke_right(t_game *game, int row, int col)
{
	if (game->map.grid[row][col + 1] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_keke_obstacle(game->map.grid[row][col + 1]))
	{
		if (game->map.grid[row][col + 1] == BOX_CHAR)
			system("aplay sounds/special-effects/box_destroyed.wav \
				> /dev/null 2>&1 &");
		game->keke.right_anim.current = game->keke.right_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row][col + 1] = KEKE_CHAR;
		game->keke.right_anim.current = game->keke.right_anim.frame_move_1;
	}
}
