/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_borders_one_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:15:29 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:03:57 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_husks_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->husks.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_fungus_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->fungus.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_fungi_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->fungi.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_flower_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->flower.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_algae_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->algae.animation.current, \
		(t_point){position.x, position.y});
}
