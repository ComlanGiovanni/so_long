/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_gameplay_one_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:19:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 22:09:51 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_love_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->love.animation.current, sprite_position);
}

void	ft_ground_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->map.ground, sprite_position);
}
