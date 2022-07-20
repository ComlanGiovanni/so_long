/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_door_sprite_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:47:12 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 14:00:47 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

//try define for path

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

/*
if ((game->door.closed.frame_1 = mlx_xpm_file_to_image(game->mlx,
"assets/xpm/Bonus/door/closed/door_closed_frame_1.xpm", &width, &height))
 == NULL)
		ft_print_error("door_closed_frame_1.xpm");//print better one create
		 varaible
if ((game->door.closed.frame_2 = mlx_xpm_file_to_image(game->mlx,
"assets/xpm/Bonus/door/closed/door_closed_frame_2.xpm", &width, &height))
 == NULL)
		ft_print_error("door_closed_frame_2.xpm");
*/
//game->door.frames = 8;

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
