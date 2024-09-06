/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_macros_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:25:57 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 16:42:04 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_MACROS_BONUS_H
# define FT_SO_LONG_MACROS_BONUS_H

# include "ft_so_long_macros_frames_bonus.h"
# include "ft_so_long_macros_direction_bonus.h"

# define BER_EXTENSION			".ber"
# define FANTASTIC		 		0x4
# define COMPASS		 		0x8
# define PLAYER_MAX_LIFE	 	0x6
# define DIGIT_COUNT		 	10
# define ALPHABET_COUNT		 	26
# define IMG_SIZE 				64
# define ICON_SIZE 				32
# define BORDERS_WIDTH 			10
# define PERMUTATION_SIZE 		256
# define BIT_MASK_POSSIBILITY	0x10
# define DISPLAY				"DISPLAY"
# define STEP_INDICATOR			"STEP"
# define FPS_INDICATOR			"FPS"
# define KEYS_INDICATOR			"KEYS"
# define MOUSE_LEFT_CLICK		"Left Click"
# define MOUSE_RIGHT_CLICK		"Right Click"
# define MOUSE_MIDDLE_CLICK		"Middle Click"
# define MOUSE_SCROLL_UP		"Scroll Up"
# define MOUSE_SCROLL_DOWN		"Scroll Down"
# define MOUSE_UNKNOW_CLICK		"Unknown Click"
# define PATH_ASSET				"assets/xpm/bonus/"
# define ERROR_MSG				"Error\n"
# define KEY_FOUND				"Key found ->"
# define KEY_AVAILABLE			"Key available -> "
# define MAP_NAME_IS			"Map is -> "
# define GRID_SIZE_PRINT		"\nGrid Width && Height -->> "
# define SCREEN_SIZE_PRINT		"Screen Height && Width "
# define WINDOW_SIZE_PRINT		"Window Height && Width "
# define GAME_TITLE				"baba is long"
# define USAGE_MSG				"./so_long [pass to map][map name].ber\n"
# define NO_ENV_ERROR			"No variable environment available\n"
# define NO_DISP_ERROR			"DISPLAY not found in env\n"
# define MALLOC_GAME_ERROR		"Malloc t_game fail to\n"
# define WALL_ERROR				".ber should be surrounded by walls\n"
# define FORM_ERROR				".ber should be in rectangular form !\n"
# define PLAYER_ERROR			".ber should have one starting point -> P\n"
# define EXIT_ERROR				".ber should have only one exit -> E\n"
# define MONSTER_ERROR			".ber should have only one monster -> K\n"
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
# define SPLIT_MAP_ERROR		"Malloc grid for path finding fail\n"
# define BORDERS_MAP_ERROR		"Malloc grid with border fail\n"
# define PATH_MAP_ERROR			"No Valid Path Found in map\n"
# define PATH_MAP_GOOD			"A Valid path found in map\n"
# define COIN_MAP_GOOD			"All coin are collectible in map\n"
# define NO_PAWNS_FOUND			"Not enough pawns found\n"
# define PAWNS_POS_FAIL			"Pawn position fail to get\n"
# define PAWNS_ROW_NULL			"Pawn row grid[y] == NULL\n"
# define NEIGHBOR_INIT_FAIL		"init neighbor node fail malloc\n"
# define NO_POSITION_FOUND		"P or E position not found in map\n"
# define PAWNS_MALLOC_FAIL		"Pawn array movement malloc failed\n"
# define COIN_MAP_ERROR			"Not All coin are collectible in map\n"
# define NEW_GRID_MSG			"\nNew grid with border for camera\n\n"
# define A_STAR_LIST_FAIL		"Memory allocation failed for A* lists\n"
# define NODE_INIT_FAIL			"Init start node for path finding failed\n"
# define COPY_MAP_FAIL			"Original game did not copy\n"
# define HOW_IS_POSSIBLE		"Too much pawn found ! Magic is happening\n"
# define MAP_TOO_BIG			"Reduce map size, map too big for the screen\n"
# define BAD_CHAR_MAP_ERROR		"Should contain char : '1' 'P' 'C' 'E' '0' 'L' \
								'N' 'Z' 'B' 'K' 'S' 'W'\n"
# define BAD_CHAR_MAP_BONUS		"There must be either exactly one N portal and \
								one Z portal, or no portals at all"
# define EMPTY_LINE 			"Remove that empty line at the \
								top or middle or bottom\n"
# define COIN_ERROR				".ber should have at least one \
								collectible -> C\n"

#endif // !FT_SO_LONG_MACROS_BONUS_H
