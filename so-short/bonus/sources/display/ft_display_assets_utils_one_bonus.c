/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_utils_one_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:26:01 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:06:12 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_put_sprite(t_game *game, void *sprite, t_point position)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		sprite, position.x, position.y);
}
