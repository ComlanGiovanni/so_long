/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_macros_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:25:57 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 16:59:57 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_MACROS_BONUS_H
# define FT_SO_LONG_MACROS_BONUS_H

# define BER_EXTENSION			".ber"
# define FANTASTIC		 		4//0x
# define COMPASS		 		8//0x
# define DIGIT_COUNT		 	10
# define ALPHABET_COUNT		 	26
# define IMG_SIZE 				64
# define ICON_SIZE 				32
# define BORDERS_WIDTH 			10//put 20 to test
# define PERMUTATION_SIZE 		256
# define DISPLAY				"DISPLAY"
# define STEP_INDICATOR			"STEP"
# define FPS_INDICATOR			"FPS"
# define KEYS_INDICATOR			"KEYS"
# define UP_DIRECTION			"Up"
# define DOW_DIRECTION			"Down"
# define LEFT_DIRECTION			"Left"
# define RIGHT_DIRECTION		"Right"
# define DOWN_RIGHT_DIRECTION	"down-right"
# define DOWN_LEFT_DIRECTION	"down-left"
# define UP_LEFT_DIRECTION		"up-left"
# define UP_RIGHT_DIRECTION		"up-right"
# define PATH_ASSET				"assets/xpm/bonus/"
# define ERROR_MSG				"Error\n"
# define KEY_FOUND				"Key found ->"
# define KEY_AVAILABLE			"Key available -> "
# define GAME_TITLE				"./so_long"
# define USAGE_MSG				"./so_long [pass to map][map name].ber\n"
# define NO_ENV_ERROR			"No variable environment available\n"
# define NO_DISP_ERROR			"DISPLAY not found in env\n"
# define MALLOC_GAME_ERROR		"Malloc t_game fail to\n"
# define BAD_CHAR_MAP_ERROR		"Should contain char : '1' 'P' 'C' 'E' '0' 'L' 'N' 'Z' 'B' 'K' 'S' 'W'\n"
# define BAD_CHAR_MAP_BONUS		"There must be either exactly one N portal and one Z portal, or no portals at all"
# define WALL_ERROR	        	".ber should be surrounded by walls\n"
# define FORM_ERROR	        	".ber should be in rectangular form !\n"
# define COIN_ERROR				".ber should have at least one collectible -> C\n"
# define PLAYER_ERROR			".ber should have one starting point -> P\n"
# define EXIT_ERROR				".ber should have only one exit -> E\n"
# define KEKE_ERROR				".ber should have only one keke -> K\n"
# define EXTENSION_ERROR		"Map extension should be a .ber\n"
# define FAIL_OPEN_ERROR		"[Map_name].ber fail to open\n"
# define MLX_INIT_ERROR			"mlx_init() fail\n"
# define MLX_WINDOW_ERROR		"mlx_new_window() fail\n"
# define PLAYER_U_0_ERROR		"player_up_frame_0.xpm fail to load\n"
# define PLAYER_U_1_ERROR		"player_up_frame_0.xpm fail to load\n"
# define PLAYER_U_2_ERROR		"player_up_frame_0.xpm fail to load\n"
# define PLAYER_U_M_ERROR		"player_up_frame_move.xpm fail to load\n"
# define GROUND_XPM_ERROR		"ground.xpm fail to load\n"
# define PLAYER_D_0_ERROR		"player_down_frame_0.xpm fail to load\n"
# define PLAYER_D_1_ERROR		"player_down_frame_1.xpm fail to load\n"
# define PLAYER_D_2_ERROR		"player_down_frame_2.xpm fail to load\n"
# define PLAYER_D_M_ERROR		"player_down_frame_move.xpm fail to load\n"
# define GRASS_0_XPM_ERROR		"grass_frame_0.xpm fail to load\n"
# define GRASS_1_XPM_ERROR		"grass_frame_1.xpm fail to load\n"
# define GRASS_2_XPM_ERROR		"grass_frame_2.xpm fail to load\n"
# define WALL_0_XPM_ERROR		"wall_frame_0.xpm fail to load\n"
# define WALL_1_XPM_ERROR		"wall_frame_1.xpm fail to load\n"
# define WALL_2_XPM_ERROR		"wall_frame_2.xpm fail to load\n"
# define PLAYER_L_0_ERROR		"player_left_frame_0.xpm fail to load\n"
# define PLAYER_L_1_ERROR		"player_left_frame_1.xpm fail to load\n"
# define PLAYER_L_2_ERROR		"player_left_frame_2.xpm fail to load\n"
# define PLAYER_L_M_ERROR		"player_left_frame_move.xpm fail to load\n"
# define KEY_0_XPM_ERROR		"key_frame_0.xpm to load\n"
# define KEY_1_XPM_ERROR		"key_frame_1.xpm to load\n"
# define KEY_2_XPM_ERROR		"key_frame_2.xpm to load\n"
# define PLAYER_R_0_ERROR		"player_right_frame_0.xpm fail to load\n"
# define PLAYER_R_1_ERROR		"player_right_frame_1.xpm fail to load\n"
# define PLAYER_R_2_ERROR		"player_right_frame_2.xpm fail to load\n"
# define PLAYER_R_M_ERROR		"player_right_frame_move.xpm fail to load\n"
# define LAVA_0_XPM_ERROR		"lava_frame_0.xpm fail to load\n"
# define LAVA_1_XPM_ERROR		"lava_frame_1.xpm fail to load\n"
# define LAVA_2_XPM_ERROR		"lava_frame_2.xpm fail to load\n"
# define DOOR_C_0_XPM_ERROR		"door_closed_frame_0.xpm fail to load\n"
# define DOOR_C_1_XPM_ERROR		"door_closed_frame_1.xpm fail to load\n"
# define DOOR_C_2_XPM_ERROR		"door_closed_frame_2.xpm fail to load\n"
# define DOOR_O_0_XPM_ERROR		"door_open_frame_0.xpm fail to load\n"
# define DOOR_O_1_XPM_ERROR		"door_open_frame_1.xpm fail to load\n"
# define DOOR_O_2_XPM_ERROR		"door_open_frame_2.xpm fail to load\n"
# define LOVE_0_XPM_ERROR		"love_frame_0.xpm fail to load\n"
# define LOVE_1_XPM_ERROR		"love_frame_1.xpm fail to load\n"
# define LOVE_2_XPM_ERROR		"love_frame_2.xpm fail to load\n"
# define LOVE_ICON_ERROR		"love_small_icon.xpm fail to load\n"
# define EMPTY_LINE 			"Remove that empty line at the top or middle or bottom\n"
# define MAP_TOO_BIG			"Reduce map size, map too big for the screen\n"
# define SPLIT_MAP_ERROR		"Malloc grid for path finding fail\n"
# define BORDERS_MAP_ERROR		"Malloc grid with border fail\n"
# define PATH_MAP_ERROR			"No Valid Path Found in map\n"
# define PATH_MAP_GOOD			"A Valid path found in map\n"
# define COIN_MAP_ERROR			"Not All coin are collectible in map\n"
# define COIN_MAP_GOOD			"All coin are collectible in map\n"
# define NO_POSITION_FOUND		"P or E position not found in map\n"
# define NEW_GRID_MSG			"\nNew grid with border for camera\n\n"
# define A_STAR_LIST_FAIL		"Memory allocation failed for A* lists\n"
# define NODE_INIT_FAIL			"Init start node for path finding failed\n"
# define NEIGHBOR_INIT_FAIL		"init neighbor node fail malloc\n"
# define HOW_IS_POSSIBLE		"Too much pawn found ! Magic is happening\n"
# define PAWNS_MALLOC_FAIL		"Pawn array movement malloc failed\n"
# define NO_PAWNS_FOUND			"Not enough pawns found\n"
# define PAWNS_POS_FAIL			"Pawn position fail to get\n"
# define PAWNS_ROW_NULL			"Pawn row grid[y] == NULL\n"

#endif // !FT_SO_LONG_MACROS_BONUS_H
