/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_utils_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:05:43 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 20:14:22 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_display_sprites_addr(t_game *game)
{
	ft_printf("\nAll image width and height are [%d x %d]\n\n", \
	IMG_SIZE, IMG_SIZE);
	ft_printf(PATH_ASSET"lava/lava_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf(PATH_ASSET"lava/lava_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_1);
	ft_printf(PATH_ASSET"lava/lava_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_2);
	ft_printf(PATH_ASSET"door/closed/door_closed_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("All sprite letter");
}

void	ft_print_game_info(t_game *game)
{
	system("clear");
	ft_print_display_grid(game->map.grid);
	ft_printf("Player position: (%d, %d)\n",
		game->player.movement.current_position.x,
		game->player.movement.current_position.y);
}
