/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_gameplay_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:11:34 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:04:12 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_key_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->key.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_exit_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->door.closed.current, \
		(t_point){position.x, position.y});
}

void	ft_box_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->box.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_portal_z_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->portal.z.current, \
		(t_point){position.x, position.y});
}

void	ft_portal_n_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->portal.n.current, \
		(t_point){position.x, position.y});
}