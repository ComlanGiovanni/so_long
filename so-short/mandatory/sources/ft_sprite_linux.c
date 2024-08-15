/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_linux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:00:05 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/13 12:56:53 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_mandatory.h"

/**
 * @brief
 *
 * 		we make sure that all sprite loaded dont fail (NULL)
 *
 * 				we use mlx_xpm_file_to_image();
 * 		to insert all the asset in a t_sprites sprite inside te t_game stuct
 * 	we need a pointer to width and height the path/file of the xpm assets
 * 			and also the game->mlx that we init -> mlx_init();
 *
 * @param mlx
 * @return t_sprites
 */
t_sprites	ft_init_sprites(void *mlx, t_game *game)
{
	t_sprites	sprite;
	int			width;
	int			height;

	sprite.player = mlx_xpm_file_to_image(mlx,
			"assets/xpm/mandatory/player.xpm", &width, &height);
	if (sprite.player == NULL)
		ft_print_error(PLAYER_XPM_ERROR, game);
	sprite.ground = mlx_xpm_file_to_image(mlx,
			"assets/xpm/mandatory/ground.xpm", &width, &height);
	if (sprite.ground == NULL)
		ft_print_error(GROUND_XPM_ERROR, game);
	sprite.wall = mlx_xpm_file_to_image(mlx,
			"assets/xpm/mandatory/wall.xpm", &width, &height);
	if (sprite.wall == NULL)
		ft_print_error(WALL_XPM_ERROR, game);
	sprite.key = mlx_xpm_file_to_image(mlx,
			"assets/xpm/mandatory/key.xpm", &width, &height);
	if (sprite.key == NULL)
		ft_print_error(KEY_XPM_ERROR, game);
	sprite.exit = mlx_xpm_file_to_image(mlx,
			"assets/xpm/mandatory/exit.xpm", &width, &height);
	if (sprite.exit == NULL)
		ft_print_error(EXIT_XPM_ERROR, game);
	return (sprite);
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
	int		width;
	int		height;

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
 *
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
 *
 * @param game
 * @param width
 * @param height
 */
void	ft_put_all_sprites_to_line(t_game *game, int width, int height)
{
	if (game->map[height * game->width + width] == WALL_CHAR)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.wall, width * 64, height * 64);
	else if (game->map[height * game->width + width] == COIN_CHAR)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.key, width * 64, height * 64);
	else if (game->map[height * game->width + width] == PLAYER_CHAR)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.player, width * 64, height * 64);
	else if (game->map[height * game->width + width] == EXIT_CHAR)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.exit, width * 64, height * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.ground, width * 64, height * 64);
}
