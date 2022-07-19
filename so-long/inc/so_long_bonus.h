/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:57:29 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/19 02:32:12 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//mac deine __apple_ and __linux
//# if defined (__APPLE__)
//#  define PTR_NULL "0x0"
//# elif __linux__
//#  define PTR_NULL "(nil)"
//# endif
//for copatibility

# include "../mlx/mlx.h"
# include "../lib/small_lib/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"

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

# define BER_EXTENSION	    ".ber"
# define IMG_SIZE 			(64)
# define ERROR_MSG	        "Error\n"
# define GAME_TITLE	        "./so_long"
# define USAGE_MSG	        "./so_long [pass to map][map name].ber\n"
# define NO_ENV_ERROR       "No variable environment available\n"
# define NO_DISP_ERROR      "DISPLAY not found in env\n"
# define MALLOC_GAME_ERROR	"Malloc t_game fail to\n"
# define BAD_CHAR_MAP_ERROR	"Map Should only contain those char : '1' 'P' 'C' 'E' '0' 'L'\n"
# define WALL_ERROR	        "[Map_name].ber should be surrounded by walls : 1 see [maps]/classic.ber\n"
# define FORM_ERROR	        "[Map_name].ber should be in rectangular form !\n"
# define COIN_ERROR			"[Map_name].ber should have at least one collectible -> C\n"
# define PLAYER_ERROR		"[Map_name].ber should have one starting point -> P\n"
# define EXIT_ERROR			"[Map_name].ber should have at east one exit -> E\n"
# define EXTENSION_ERROR	"Map extension should be a .ber\n"
# define FAIL_OPEN_ERROR	"[Map_name].ber fail to open\n"
# define MLX_INIT_ERROR		"mlx_init() fail\n"
# define MLX_WINDOW_ERROR	"mlx_new_window() fail\n"
# define PLAYER_U_XPM_ERROR	"player_up.xpm fail to load\n"
# define PLAYER_D_XPM_ERROR	"player_down.xpm fail to load\n"
# define PLAYER_L_XPM_ERROR "player_left.xpm fail to load\n"
# define PLAYER_R_XPM_ERROR	"player_right.xpm fail to load\n"
# define GROUND_XPM_ERROR	"ground.xpm fail to load\n"
# define WALL_XPM_ERROR		"wall.xpm fail to load\n"
# define WALL_0_XPM_ERROR	"wall_1.xpm fail to load\n"
# define WALL_1_XPM_ERROR	"wall_2.xpm fail to load\n"
# define KEY_XPM_ERROR		"key.xpm fail to load\n"
# define EXIT_1_XPM_ERROR	"exit_1.xpm fail to load\n"
# define EXIT_2_XPM_ERROR	"exit_2.xpm fail to load\n"
# define WIN_MSG			"Thanks for playing, you win with steps : "
# define LOSE_MSG			"You loooossseee with steps : "

/*
enum enum e_key_code_linux {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	UP_ARROW_KEY = 65362,
	DOWN_ARROW_KEY = 65364,
	LEFT_ARROW_KEY = 65361,
	RIGHT_ARROW_KEY = 65363,
	ESC_KEY = 65307,
	UP_PAV_NUM_KEY = 65464,
	DOWN_PAV_NUM_KEY = 65458,
	LEFT_PAV_NUM_KEY = 65460,
	RIGHT_PAV_NUM_KEY = 65462,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
}t_key_code_linux;
*/

typedef enum e_key_code_mac {
	MAC_CLOSE_ICON = 17,
	MAC_ESC_KEY = 53,
	MAC_KEY_PRESS = 2,
	MAC_KEY_RELEASE = 3,
	MAC_W_KEY = 13,
	MAC_A_KEY = 0,
	MAC_S_KEY = 1,
	MAC_D_KEY = 2,
	MAC_UP_ARROW_KEY = 126,
	MAC_DOWN_ARROW_KEY = 125,
	MAC_LEFT_ARROW_KEY = 123,
	MAC_RIGHT_ARROW_KEY = 124,
	MAC_UP_PAV_NUM_KEY = 91,
	MAC_DOWN_PAV_NUM_KEY = 84,
	MAC_LEFT_PAV_NUM_KEY = 86,
	MAC_RIGHT_PAV_NUM_KEY = 88
}	t_key_code_mac;

typedef enum e_map_char
{
	WALL_CHAR = '1',
	PLAYER_CHAR = 'P',
	KEY_CHAR ='C',
	EXIT_CHAR = 'E',
	VOID_CHAR = '0',
	LAVA_CHAR = 'L'
}	t_map_char;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;


typedef struct s_sprites {
	void	*player;
	void	*player_up;
	void	*player_up_frame_0;
	void	*player_up_frame_1;
	void	*player_up_frame_move;
	void	*player_down;
	void	*player_down_frame_0;
	void	*player_down_frame_1;
	void	*player_down_frame_move;
	void	*player_left;
	void	*player_left_frame_0;
	void	*player_left_frame_1;
	void	*player_left_frame_move;
	void	*player_right;
	void	*player_right_frame_0;
	void	*player_right_frame_1;
	void	*player_right_frame_move;
	void	*ground;
	int		player_frames;
	void	*exit_1;
	void	*exit_2;
}		t_sprites;

typedef struct s_animation
{
	int		frames;
	void	*frame_0;
	void	*frame_1;
	void	*frame_2;
}		t_animation;
typedef struct s_lava
{
	t_animation		  animation;
}		t_lava;

typedef struct s_key
{
	t_animation		  animation;
}		t_key;

typedef struct s_wall
{
	t_animation		  animation;
}		t_wall;

typedef struct s_game
{
    t_sprites 			  sprite;
	t_lava				  lava;
	t_lava				  key;
	t_wall				  wall;
	void	 		   	  *mlx;
	void   				  *win;
    char     			  *map;
	long long int		  step;
	long long int		  map_len;
    long long int		  width;
	long long int		  height;
	long long int		  nbr_key;
	long long int		  storage;
	long long int	   	  exit;
	long long int	      player;
	long long int	      lava_nbr;
	char	  			  direction;
}		t_game;

//../src/main.c

void	ft_render(t_game *game);
int		ft_update(t_game *game);
void	ft_print_info_on_window(t_game *game);

//../src/animation_bonus.c

void	ft_wall_animation(t_animation *animation);
void	ft_player_animation(t_sprites *sprite);
void	ft_lava_animation(t_animation *animation);
void	ft_key_animation(t_animation *animation);

//../src/input_bonus.c

int     ft_input_manager(int key, t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

//../src/load_sprite_bonus.c

void	ft_load_lava_sprite(t_game *game);
void	ft_load_key_sprite(t_game *game);
void	ft_load_wall_sprite(t_game *game);
//void	ft_load_player_up_sprite(t_game *game);
//void	ft_load_player_down_sprite(t_game *game);

//../src/map_bonus.c

void	ft_read_map(t_game *game, char *map_name);
void	ft_check_map(t_game *game);
void	ft_check_sealed(t_game *game);
//void	ft_check_rectangular(t_game *game);
void	ft_check_playability(t_game *game);

//../src/other_tools_bonus.c 

void    ft_print_map_better_format(t_game *game);;
void    ft_print_game_info(t_game *game, int key_code);
void    ft_print_facing(t_game *game);
void    ft_direction_by_pos_after_launch(t_game *game);
int		ft_lose_game(t_game *game);

//../src/so_long_bonus.c

void	ft_init_game(t_game *game, char *map_name);
int		ft_exit_game(t_game *game);
int		ft_win_game(t_game *game);
void	ft_print_error(char *error_msg);
void	ft_check_valid_char(t_game *game);

//../src/sprite_bonus.c

t_sprites	ft_init_sprites(void *mlx);
void		ft_put_sprites_by_line(t_game *game);
void		ft_put_all_sprites_to_line(t_game *game, int width, int height);

//../src/tools_bonus.c

char	*ft_custom_strdup(char *s1);
int		ft_custom_strlcpy(char *dst, char *src, int dst_size);
char	*ft_custom_strjoin(char *s1, char *s2);
void	ft_check_env(char **env);
int		ft_check_extension(char *map_name, char *extension);

#endif
