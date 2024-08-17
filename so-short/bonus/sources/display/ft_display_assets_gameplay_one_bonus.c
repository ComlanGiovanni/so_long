/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_gameplay_one_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:19:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/17 01:19:37 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_love_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->love.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_ground_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->map.ground, (t_point){position.x, position.y});
}
//remove after and unload normal frame wall
void	ft_wall_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->wall.animation.current, \
		(t_point){position.x, position.y});
}
