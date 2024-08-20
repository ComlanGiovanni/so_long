/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_player_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:46:45 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 22:15:01 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_player_sprite(t_game *game, t_point grid_position,
		t_point sprite_position)
{
	if (game->map.grid[grid_position.y][grid_position.x] == PLAYER_CHAR)
	{
		if (game->player.movement.direction == 'd')
			ft_player_down_sprite(game, sprite_position);
		else if (game->player.movement.direction == 'u')
			ft_player_up_sprite(game, sprite_position);
		else if (game->player.movement.direction == 'l')
			ft_player_left_sprite(game, sprite_position);
		else if (game->player.movement.direction == 'r')
			ft_player_right_sprite(game, sprite_position);
	}
}

void	ft_player_down_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->player.down_anim.current, sprite_position);
}

void	ft_player_up_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->player.up_anim.current, sprite_position);
}

void	ft_player_left_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->player.left_anim.current, sprite_position);
}

void	ft_player_right_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->player.right_anim.current, sprite_position);
}
