/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_door_sprite_bonus_mac.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:47:12 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/25 17:08:05 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_mac/so_long_bonus_mac.h"

/**
 * @brief 
 * 
 * 		Check after load to prevent segfault of all the loaded sprite
 * 				set of the frame of the animation in the struct
 *			print the good erro message
 * 				Here door sprite close and open sprite
 * 
 * 		we can see here that we only load one sprite for the closed dooor
 * 	because by mistake i forget to load all the sprite for the door and then
 * 	realized that is better if we animate the door in green when all collectible
 * 	if collect by the player or good felling like feed back to the player
 * 
 * 
 * @param game 
 */
void	ft_load_door_closed_sprites(t_game *game)
{
	int	width;
	int	height;

	game->door.frames = 32;
	game->door.closed.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/door/closed/door_closed_frame_0.xpm",
			&width, &height);
	if (game->door.closed.frame_0 == NULL)
		ft_print_error(DOOR_C_0_XPM_ERROR);
}

void	ft_load_door_open_sprites(t_game *game)
{
	int	width;
	int	height;

	game->door.open.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/door/open/door_open_frame_0.xpm",
			&width, &height);
	if (game->door.open.frame_0 == NULL)
		ft_print_error(DOOR_O_0_XPM_ERROR);
	game->door.open.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/door/open/door_open_frame_1.xpm",
			&width, &height);
	if (game->door.open.frame_1 == NULL)
		ft_print_error(DOOR_O_1_XPM_ERROR);
	game->door.open.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/door/open/door_open_frame_2.xpm",
			&width, &height);
	if (game->door.open.frame_2 == NULL)
		ft_print_error(DOOR_O_2_XPM_ERROR);
}
