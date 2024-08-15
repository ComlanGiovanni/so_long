/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:46:14 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 00:17:27 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

/**
 * @brief
 *
 * 				This fct  call all the fct that load all
 * 					the sprite we need for the game aka
 * 		key lava wall ground player direct sprite door open and close
 *
 *  //ft_load_grass_sprites(game)
 * @param mlx
 * @return t_sprites
 */
void	ft_put_sprites_by_line(t_game *game)
{
	int		width;
	int		height;
	int		win_width;
	int		win_height;
	t_point	sprite_pos;

	height = 0;
	win_width = ((game->width * IMG_SIZE) / 2);
	win_height = ((game->height * IMG_SIZE) / 2);
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			sprite_pos.x = ((width * IMG_SIZE) - game->camera.current.x);
			sprite_pos.y = ((height * IMG_SIZE) - game->camera.current.y);
			if ((sprite_pos.x + IMG_SIZE) >= 0 && (sprite_pos.x <= win_width)
				&& (sprite_pos.y + IMG_SIZE) >= 0
				&& (sprite_pos.y <= win_height))
				ft_put_all_sprites_to_line(game, width, height, sprite_pos);
			width++;
		}
		height++;
	}
}

/**
 * @brief
 * 			1111
 *  		1CC1
 * 			1PE1
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
 * lag switch lol
 *ft_printf("Tile -> %c Width -> %d Height -> %d
 * sprite_pos.x -> %d sprite_pos.y -> %d\n", tile, width,
 * height, sprite_pos.x, sprite_pos.y);
 *
 * @param game
 * @param width
 * @param height
 */
void	ft_put_all_sprites_to_line(t_game *game, int width, int height,
		t_point sprite_pos)
{
	char	tile;

	tile = game->map.grid[height][width];
	if (tile == WALL_CHAR)
		ft_wall_sprite(game, sprite_pos);
	else if (tile == VOID_CHAR)
		ft_ground_sprite(game, sprite_pos);
	else if (ft_is_key_love_box_sprites(tile))
		ft_handle_key_love_box_sprites(game, tile, sprite_pos);
	else if (ft_is_exit_portals_sprites(tile))
		ft_handle_exit_portals_sprites(game, tile, sprite_pos);
	else if (ft_is_borders_sprites(tile))
		ft_handle_borders_sprites(game, tile, sprite_pos);
	else if (ft_is_other_borders_sprites(tile))
		ft_handle_other_borders_sprites(game, tile, sprite_pos);
	else if (ft_is_enemies_sprites(tile))
		ft_handle_enemies_sprites(game, tile, sprite_pos);
	else if (tile == KEKE_CHAR)
		ft_keke_sprites(game, width, height, sprite_pos);
	else
		ft_player_sprite_call(game, width, height, sprite_pos);
}

void	ft_handle_borders_sprites(t_game *game, char tile, t_point sprite_pos)
{
	if (tile == GRASS_CHAR)
		ft_grass_sprite(game, sprite_pos);
	else if (tile == TREE_CHAR)
		ft_tree_sprite(game, sprite_pos);
	else if (tile == TREES_CHAR)
		ft_trees_sprite(game, sprite_pos);
	else if (tile == REED_CHAR)
		ft_reed_sprite(game, sprite_pos);
	else if (tile == HUSKS_CHAR)
		ft_husks_sprite(game, sprite_pos);
	else if (tile == FUNGUS_CHAR)
		ft_fungus_sprite(game, sprite_pos);
	else if (tile == FUNGI_CHAR)
		ft_fungi_sprite(game, sprite_pos);
	else if (tile == FLOWER_CHAR)
		ft_flower_sprite(game, sprite_pos);
	else if (tile == ALGAE_CHAR)
		ft_algae_sprite(game, sprite_pos);
	else if (tile == WATER_CHAR)
		ft_water_sprite(game, sprite_pos);
}

void	ft_handle_other_borders_sprites(t_game *game, char tile,
		t_point sprite_pos)
{
	if (tile == CRAB_CHAR)
		ft_crab_sprite(game, sprite_pos);
	else if (tile == FOLIAGE_CHAR)
		ft_foliage_sprite(game, sprite_pos);
	else if (tile == BOG_CHAR)
		ft_bog_sprite(game, sprite_pos);
	else if (tile == SNAIL_CHAR)
		ft_snail_sprite(game, sprite_pos);
	else if (tile == PILLAR_CHAR)
		ft_pillar_sprite(game, sprite_pos);
	else if (tile == HEDGE_CHAR)
		ft_hedge_sprite(game, sprite_pos);
}

void	ft_handle_key_love_box_sprites(t_game *game, char tile,
		t_point sprite_pos)
{
	if (tile == KEY_CHAR)
		ft_key_sprite(game, sprite_pos);
	else if (tile == LOVE_CHAR)
		ft_love_sprite(game, sprite_pos);
	else if (tile == BOX_CHAR)
		ft_box_sprite(game, sprite_pos);
}
