/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_borders_two_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:16:23 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:04:06 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_water_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->water.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_crab_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->crab.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_foliage_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->foliage.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_bog_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->bog.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_snail_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->snail.animation.current, \
		(t_point){position.x, position.y});
}
