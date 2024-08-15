/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_borders_tree_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:17:51 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:04:02 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_hedge_sprite(t_game *game, t_point position)
{
	ft_put_sprite(game, game->hedge.animation.current, \
		(t_point){position.x, position.y});
}
