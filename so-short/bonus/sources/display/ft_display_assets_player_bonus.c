/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_player_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:46:45 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:04:20 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_player_sprite_call(t_game *game, int width, int height,
		t_point sprite_position)
{
	if (game->map.grid[height][width] == PLAYER_CHAR)
	{
		if (game->player.movement.direction == 'd')
			ft_player_down_sprite(game, sprite_position.x, sprite_position.y);
		else if (game->player.movement.direction == 'u')
			ft_player_up_sprite(game, sprite_position.x, sprite_position.y);
		else if (game->player.movement.direction == 'l')
			ft_player_left_sprite(game, sprite_position.x, sprite_position.y);
		else if (game->player.movement.direction == 'r')
			ft_player_right_sprite(game, sprite_position.x, sprite_position.y);
	}
}

void	ft_player_down_sprite(t_game *game, int draw_x, int draw_y)
{
	ft_put_sprite(game, game->player.down_anim.current, \
		(t_point){draw_x, draw_y});
}

void	ft_player_up_sprite(t_game *game, int draw_x, int draw_y)
{
	ft_put_sprite(game, game->player.up_anim.current, \
		(t_point){draw_x, draw_y});
}

void	ft_player_left_sprite(t_game *game, int draw_x, int draw_y)
{
	ft_put_sprite(game, game->player.left_anim.current, \
		(t_point){draw_x, draw_y});
}

void	ft_player_right_sprite(t_game *game, int draw_x, int draw_y)
{
	ft_put_sprite(game, game->player.right_anim.current, \
		(t_point){draw_x, draw_y});
}
