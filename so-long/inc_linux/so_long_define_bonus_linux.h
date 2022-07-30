/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_define_bonus_linux.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:27:10 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/30 23:23:45 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFINE_BONUS_LINUX_H
# define SO_LONG_DEFINE_BONUS_LINUX_H

//COLOR

# define BLUE 0x0000FF
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define BROWN 0x993300
# define WHITE 0xFFFFFF
# define INDIGO 0xFF4B0082
# define AQUA 0x00FFFF
# define NAVY 0x00005F
# define PINK 0xFF1493
# define LIME 0x00ff00
# define TURQUOISE 0x30D5C8

//ERROR MESSAGE

# define BER_EXTENSION	    ".ber"
# define IMG_SIZE 			(64)
# define ICON_SIZE 			(10)
# define ERROR_MSG	        "Error\n"
# define GAME_TITLE	        "./so_long"
# define USAGE_MSG	        "./so_long [pass to map][map name].ber\n"
# define NO_ENV_ERROR       "No variable environment available\n"
# define NO_DISP_ERROR      "DISPLAY not found in env\n"
# define MALLOC_GAME_ERROR	"Malloc t_game fail to\n"
# define BAD_CHAR_MAP_ERROR	"Map Should contain char : '1' 'P' 'C' 'E' '0' 'L'\n"
# define WALL_ERROR	        ".ber should be surrounded by walls\n"
# define FORM_ERROR	        ".ber should be in rectangular form !\n"
# define COIN_ERROR			".ber should have at least one collectible -> C\n"
# define PLAYER_ERROR		".ber should have one starting point -> P\n"
# define EXIT_ERROR			".ber should have at east one exit -> E\n"
# define EXTENSION_ERROR	"Map extension should be a .ber\n"
# define FAIL_OPEN_ERROR	"[Map_name].ber fail to open\n"
# define MLX_INIT_ERROR		"mlx_init() fail\n"
# define MLX_WINDOW_ERROR	"mlx_new_window() fail\n"
# define PLAYER_U_0_ERROR	"player_up_frame_0.xpm fail to load\n"
# define PLAYER_U_1_ERROR	"player_up_frame_0.xpm fail to load\n"
# define PLAYER_U_2_ERROR	"player_up_frame_0.xpm fail to load\n"
# define PLAYER_U_M_ERROR	"player_up_frame_move.xpm fail to load\n"
# define GROUND_XPM_ERROR	"ground.xpm fail to load\n"
# define PLAYER_D_0_ERROR	"player_down_frame_0.xpm fail to load\n"
# define PLAYER_D_1_ERROR	"player_down_frame_1.xpm fail to load\n"
# define PLAYER_D_2_ERROR	"player_down_frame_2.xpm fail to load\n"
# define PLAYER_D_M_ERROR	"player_down_frame_move.xpm fail to load\n"
# define WALL_0_XPM_ERROR	"wall_frame_0.xpm fail to load\n"
# define WALL_1_XPM_ERROR	"wall_frame_1.xpm fail to load\n"
# define WALL_2_XPM_ERROR	"wall_frame_2.xpm fail to load\n"
# define PLAYER_L_0_ERROR	"player_left_frame_0.xpm fail to load\n"
# define PLAYER_L_1_ERROR	"player_left_frame_1.xpm fail to load\n"
# define PLAYER_L_2_ERROR	"player_left_frame_2.xpm fail to load\n"
# define PLAYER_L_M_ERROR	"player_left_frame_move.xpm fail to load\n"
# define KEY_0_XPM_ERROR	"key_frame_0.xpm to load\n"
# define KEY_1_XPM_ERROR	"key_frame_1.xpm to load\n"
# define KEY_2_XPM_ERROR	"key_frame_2.xpm to load\n"
# define PLAYER_R_0_ERROR	"player_right_frame_0.xpm fail to load\n"
# define PLAYER_R_1_ERROR	"player_right_frame_1.xpm fail to load\n"
# define PLAYER_R_2_ERROR	"player_right_frame_2.xpm fail to load\n"
# define PLAYER_R_M_ERROR	"player_right_frame_move.xpm fail to load\n"
# define LAVA_0_XPM_ERROR	"lava_frame_0.xpm fail to load\n"
# define LAVA_1_XPM_ERROR	"lava_frame_1.xpm fail to load\n"
# define LAVA_2_XPM_ERROR	"lava_frame_2.xpm fail to load\n"
# define DOOR_C_0_XPM_ERROR	"door_closed_frame_0.xpm fail to load\n"
# define DOOR_O_0_XPM_ERROR	"door_open_frame_0.xpm fail to load\n"
# define DOOR_O_1_XPM_ERROR	"door_open_frame_1.xpm fail to load\n"
# define DOOR_O_2_XPM_ERROR	"door_open_frame_2.xpm fail to load\n"
# define LOVE_0_XPM_ERROR	"love_frame_0.xpm fail to load\n"
# define LOVE_1_XPM_ERROR	"love_frame_1.xpm fail to load\n"
# define LOVE_2_XPM_ERROR	"love_frame_2.xpm fail to load\n"
# define LOVE_ICON_ERROR	"love_small_icon.xpm fail to load\n"
# define WIN_MSG			"Thanks for playing, you WIN with steps : "
# define LOSE_MSG			"You LOSE with steps : "
# define EMPTY_LINE 		"Remove that empty line at the top or middle\n"
# define MAP_TOO_BIG    	"Reduce map size, map too big for the screen\n"

#endif
