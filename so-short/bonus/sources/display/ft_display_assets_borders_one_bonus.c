/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_borders_one_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:15:29 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 22:08:08 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_husks_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->husks.animation.current, sprite_position);
}

void	ft_fungus_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->fungus.animation.current, sprite_position);
}

void	ft_fungi_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->fungi.animation.current, sprite_position);
}

void	ft_flower_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->flower.animation.current, sprite_position);
}

void	ft_algae_sprite(t_game *game, t_point sprite_position)
{
	ft_put_sprite(game, game->algae.animation.current, sprite_position);
}
