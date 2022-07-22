/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:53 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/22 03:34:21 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

/*
				IDEA
			ft_print_spite_error char * path
		This fct will print Error $variable fail to load header define
	The variable will be splitted from the path header define
	
			ft_split_path char * path
	this fct will parse the path and put iin double table
path to the xm file and will return the str int the tab

	Need : ft_split free after using

	pros : less define form specific xpm file
*/

/**
 * @brief 
 * 
 * @param mlx 
 * @return t_sprites 
 */
void	ft_load_sprites(t_game *game)
{
	ft_load_key_sprites(game);
	ft_load_lava_sprites(game);
	ft_load_love_sprites(game);
	ft_load_wall_sprites(game);
	ft_load_ground_sprites(game);
	ft_load_player_up_sprites(game);
	ft_load_player_down_sprites(game);
	ft_load_player_left_sprites(game);
	ft_load_player_right_sprites(game);
	ft_load_door_closed_sprites(game);
	ft_load_door_open_sprites(game);
}

// put all int frame in a fct ft_init_frames_int
// fct for missing file for better read
//verify header error name EXIT_1_XPM_ERROR

void	ft_put_sprites_by_line(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			ft_put_all_sprites_to_line(game, width, height);
			width++;
		}
		height++;
	}
}

/*
this shit will be too long when norme

make a put for
map info
for player
for the door

//int wid ---> game->wid game->direction = 'r'

/make fct or player 

oh but the slit was anoying
*/

void	ft_put_all_sprites_to_line(t_game *game, int width, int height)
{
	if (game->map.map_str[height * game->width + width] == WALL_CHAR)
		ft_wall_sprite(game, width, height);
	else if (game->map.map_str[height * game->width + width] == KEY_CHAR)
		ft_key_sprite(game, width, height);
	else if (game->map.map_str[height * game->width + width] == LAVA_CHAR)
		ft_lava_sprite(game, width, height);
	else if (game->map.map_str[height * game->width + width] == LOVE_CHAR)
		ft_love_sprite(game, width, height);
	else if (game->map.map_str[height * game->width + width] == EXIT_CHAR
		&& game->player.storage == game->map.nbr_key)
		mlx_put_image_to_window(game->mlx, game->win,
			game->door.open.frame_0, width * IMG_SIZE, height * IMG_SIZE);
	else if (game->map.map_str[height * game->width + width] == EXIT_CHAR)
		ft_exit_sprite(game, width, height);
	else if (game->map.map_str[height * game->width + width] == VOID_CHAR)
		ft_ground_sprite(game, width, height);
	else
		ft_player_sprite_call(game, width, height);
}

// not great but you will stay here lol

void	ft_wall_sprite(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->wall.animation.frame_0, width * IMG_SIZE, height * IMG_SIZE);
}
