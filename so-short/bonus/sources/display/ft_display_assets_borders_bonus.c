/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_borders_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:13:54 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:03:51 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_grass_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->grass.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_tree_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->tree.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_trees_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->trees.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_reed_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->reed.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_pillar_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->pillar.animation.current, \
		(t_point){position.x, position.y});
}
