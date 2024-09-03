/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monster_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:43:47 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/03 22:34:20 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_move_monster(t_game *game)
{
	if (game->monster.direction == 'u')
		ft_monster_move_up(game);
	if (game->monster.direction == 'd')
		ft_monster_move_down(game);
	if (game->monster.direction == 'l')
		ft_monster_move_left(game);
	if (game->monster.direction == 'r')
		ft_monster_move_right(game);
}

void	ft_move_monster_up(t_game *game, int row, int col)
{
	if (game->map.grid[row - 0x1][col] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_monster_obstacle(game->map.grid[row - 0x1][col]))
	{
		if (game->map.grid[row - 0x1][col] == BOX_CHAR)
			system("paplay sounds/special-effects/box_destroyed.wav \
				> /dev/null 2>&1 &");
		game->monster.up_anim.current = game->monster.up_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row - 1][col] = MONSTER_CHAR;
		game->monster.up_anim.current = game->monster.up_anim.frame_move_1;
	}
}

void	ft_move_monster_down(t_game *game, int row, int col)
{
	if (game->map.grid[row + 0x1][col] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_monster_obstacle(game->map.grid[row + 0x1][col]))
	{
		if (game->map.grid[row + 0x1][col] == BOX_CHAR)
			system("paplay sounds/special-effects/box_destroyed.wav \
				> /dev/null 2>&1 &");
		game->monster.down_anim.current = game->monster.down_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row + 1][col] = MONSTER_CHAR;
		game->monster.down_anim.current = game->monster.down_anim.frame_move_1;
	}
}

void	ft_move_monster_left(t_game *game, int row, int col)
{
	if (game->map.grid[row][col - 0x1] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_monster_obstacle(game->map.grid[row][col - 1]))
	{
		if (game->map.grid[row][col - 0x1] == BOX_CHAR)
			system("paplay sounds/special-effects/box_destroyed.wav \
				 > /dev/null 2>&1 &");
		game->monster.left_anim.current = game->monster.left_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row][col - 0x1] = MONSTER_CHAR;
		game->monster.left_anim.current = game->monster.left_anim.frame_move_1;
	}
}

void	ft_move_monster_right(t_game *game, int row, int col)
{
	if (game->map.grid[row][col + 0x1] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_monster_obstacle(game->map.grid[row][col + 0x1]))
	{
		if (game->map.grid[row][col + 0x1] == BOX_CHAR)
			system("paplay sounds/special-effects/box_destroyed.wav \
				> /dev/null 2>&1 &");
		game->monster.right_anim.current = \
			game->monster.right_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row][col + 0x1] = MONSTER_CHAR;
		game->monster.right_anim.current = \
			game->monster.right_anim.frame_move_1;
	}
}
