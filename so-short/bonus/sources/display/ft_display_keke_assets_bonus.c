/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_monster_assets_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:46:45 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/18 08:52:08 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_monster_sprites(t_game *game, int width, int height,
		t_point sprite_position)
{
	if (game->map.grid[height][width] == MONSTER_CHAR)
	{
		if (game->monster.direction == 'd')
			ft_monster_down_sprite(game, sprite_position.x, sprite_position.y);
		else if (game->monster.direction == 'u')
			ft_monster_up_sprite(game, sprite_position.x, sprite_position.y);
		else if (game->monster.direction == 'l')
			ft_monster_left_sprite(game, sprite_position.x, sprite_position.y);
		else if (game->monster.direction == 'r')
			ft_monster_right_sprite(game, sprite_position.x, sprite_position.y);
	}
}

void	ft_monster_down_sprite(t_game *game, int draw_x, int draw_y)
{
	ft_put_sprite(game, game->monster.down_anim.current, \
		(t_point){draw_x, draw_y});
}

void	ft_monster_up_sprite(t_game *game, int draw_x, int draw_y)
{
	ft_put_sprite(game, game->monster.up_anim.current, \
		(t_point){draw_x, draw_y});
}

void	ft_monster_left_sprite(t_game *game, int draw_x, int draw_y)
{
	ft_put_sprite(game, game->monster.left_anim.current, \
		(t_point){draw_x, draw_y});
}

void	ft_monster_right_sprite(t_game *game, int draw_x, int draw_y)
{
	ft_put_sprite(game, game->monster.right_anim.current, \
		(t_point){draw_x, draw_y});
}
