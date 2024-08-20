/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_keke_assets_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:46:45 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 22:18:36 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_monster_sprites(t_game *game, t_point grid_position, \
		t_point sprite_position)
{
	if (game->map.grid[grid_position.y][grid_position.x] == MONSTER_CHAR)
	{
		if (game->monster.direction == 'd')
			ft_monster_down_sprite(game, sprite_position);
		else if (game->monster.direction == 'u')
			ft_monster_up_sprite(game, sprite_position);
		else if (game->monster.direction == 'l')
			ft_monster_left_sprite(game, sprite_position);
		else if (game->monster.direction == 'r')
			ft_monster_right_sprite(game, sprite_position);
	}
}

void	ft_monster_down_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->monster.down_anim.current, sprite_position);
}

void	ft_monster_up_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->monster.up_anim.current, sprite_position);
}

void	ft_monster_left_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->monster.left_anim.current, sprite_position);
}

void	ft_monster_right_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->monster.right_anim.current, sprite_position);
}
