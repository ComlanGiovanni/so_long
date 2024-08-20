/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_border_four_assets_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:00:28 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:41:11 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_hedge_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"hedge/hedge_frame_0.xpm",
		PATH_ASSET"hedge/hedge_frame_1.xpm",
		PATH_ASSET"hedge/hedge_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hedge.animation), \
		game, paths, paths);
}
