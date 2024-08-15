/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_enemies_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:13:13 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:04:09 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_lava_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->lava.animation.current, \
		(t_point){position.x, position.y});
}

void	ft_pawn_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->pawn.animation.current, \
		(t_point){position.x, position.y});
}
