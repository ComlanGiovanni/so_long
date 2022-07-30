/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus_linux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:53 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/31 00:57:21 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

//					IDEA
//				ft_print_spite_error char * path
//			This fct will print Error $variable fail to load header define
//		The variable will be splitted from the path header define
//				ft_split_path char * path
//		this fct will parse the path and put iin double table
//			path to the xm file and will return the str int the tab
//				Need : ft_split free after using
//				pros : less define form specific xpm file

/**
 * @brief 
 * 
 * 				This fct  call all the fct that load all
 * 					the sprite we need for the game aka
 * 		key lava wall ground player direct sprite door open and close
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
	ft_load_player_current(game);
	ft_load_door_closed_sprites(game);
	ft_load_door_open_sprites(game);
}

/**
 * @brief
 * 
 * 		0-   1111
 *  	1-   1CC1
 * 		2-   1PE1
 *      3-   1111
 * 
 * 		we print all the sprite line by line by th height and width
 * 				get in ft_read_map and ft_init_map_info we send those
 * 	to ft_put_all_sprites_to_line to use mlx_put_image_to_window
 * 			for every elm in the map t_game map needed or map str and
 * 					width height
 * 
 * @param game 
 */
void	ft_put_sprites_by_line(t_game *game)
{
	int	width;
	int	height;

	height = FALSE;
	while (height < game->height)
	{
		width = FALSE;
		while (width < game->width)
		{
			ft_put_all_sprites_to_line(game, width, height);
			width++;
		}
		height++;
	}
}

/**
 * @brief 
 * 		   1111
 *  	   1CC1
 * 		   1PE1
 *         1111
 * 
 *  We print all the xpm load in ft_init_sprites if we found 
 * 		char (WALL-COIN-PLAYER-EXIT-GROUND)  0 1 P E C with this fct :
 * 							Lava love char
 * int	mlx_put_image_to_window(void *mlx_ptr,	{game->mlx}
 * 								void *win_ptr,  {game->ptr}
 * 								void *img_ptr,	{game->sprite}->.{you_assets}
 *							int x, int y); position width height
 *
 * x && y are multiply by 64 because int init_game in main
 * 			we set the windows like :
 *   win ->(game->mlx, game->width * 64, game->height * 64, GAME_TITLE);
 * 
 * every time for every char we check all idx to see witch one to print
 * so 0 1 2 3 4 would be check for  0 1 P E C to get printed because
 * the player can move and the coin can be remove so we need to check all
 * the time to get the illusion of update and good feed back on the windows
 * 
 * 	game->map[height * game->width + width]	idx -> [0 1 2 3] * (4) + [0 1 2 3]
 * 
 * we slit in small fct or 42 norm in all those ft_{01PECLL}_sprite we just
 * 						mlx_put_image_to_window
 * 
 * @param game 
 * @param width 
 * @param height 
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
			game->door.open.current, width * IMG_SIZE, height * IMG_SIZE);
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
		game->wall.animation.current, width * IMG_SIZE, height * IMG_SIZE);
}
