/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_behaviour_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:21:59 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:29:58 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

/**
 * @brief
 *
 * 		This fct its only here to give more life at the game,
 * 		instead of spawning everytime look to up down or left
 * 		we simply generate a randonn nbr with random -> time.h
 * 		srand if for more random generaton so 0 1 2 3 represent
 * 		up down left right assign is belong to you
 *
 * 	diriger la position en fonciton de la position de player
 * par rapport a l'exit ?
 *
 *	bas haut gauche droite
 *
 * @param game
 */
void	ft_dir_player_by_pos_exit_after_launch(t_game *game)
{
	if (game->map.start.y > game->map.end.y)
		game->player.movement.direction = 'u';
	else if (game->map.start.y < game->map.end.y)
		game->player.movement.direction = 'd';
	else if (game->map.start.x > game->map.end.x)
		game->player.movement.direction = 'l';
	else if (game->map.start.x < game->map.end.x)
		game->player.movement.direction = 'r';
}

void	ft_move_box(t_game *game, t_point new_pos, int dir_y, int dir_x)
{
	char	next_tile;

	next_tile = game->map.grid[new_pos.y + dir_y][new_pos.x + dir_x];
	if (next_tile == LAVA_CHAR)
	{
		game->map.grid[new_pos.y][new_pos.x] = VOID_CHAR;
		game->map.grid[new_pos.y + dir_y][new_pos.x + dir_x] = VOID_CHAR;
		system("paplay sounds/special-effects/box_destroyed.wav \
			> /dev/null 2>&1 &");
	}
	if (next_tile == VOID_CHAR && (next_tile != LOVE_CHAR
			&& next_tile != EXIT_CHAR && next_tile != KEY_CHAR))
	{
		game->map.grid[new_pos.y + dir_y][new_pos.x + dir_x] = BOX_CHAR;
		game->map.grid[new_pos.y][new_pos.x] = VOID_CHAR;
		system("paplay sounds/special-effects/box_move.wav \
			> /dev/null 2>&1 &");
	}
}

void	ft_teleport_player(t_game *game, int y, int x)
{
	t_point	destination;

	if (game->map.grid[y][x] == 'N')
		destination = game->map.portal_1_pos;
	else if (game->map.grid[y][x] == 'Z')
		destination = game->map.portal_2_pos;
	else
		return ;
	if (destination.y != -1 && destination.x != -1)
	{
		game->map.grid[y][x] = VOID_CHAR;
		system("paplay sounds/special-effects/teleportation.wav \
			> /dev/null 2>&1 &");
		game->map.grid[destination.y][destination.x] = PLAYER_CHAR;
		game->player.movement.current_position.y = destination.y;
		game->player.movement.current_position.x = destination.x;
	}
}
