/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:57:29 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 22:25:53 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define EXIT_ERROR			"].ber should have at east one exit -> E\n"
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
# define BITCHISEMPTY 	"Remove that empty line please :(\n"

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

// lol read scp-10
//http://fondationscp.wikidot.com/scp-010

typedef enum e_map_char
{
	LAVA_CHAR = 'L',
	EXIT_CHAR = 'E',
	LOVE_CHAR = 'S',
	KEY_CHAR ='C',
	PLAYER_CHAR = 'P',
	WALL_CHAR = '1',
	VOID_CHAR = '0',
}	t_map_char;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_animation
{
	int		frames;
	void	*frame_0;
	void	*frame_1;
	void	*frame_2;
}		t_animation;
typedef struct s_lava
{
	t_animation	animation;
	char		move;
}		t_lava;

typedef struct s_key
{
	t_animation	animation;
}		t_key;

typedef struct s_wall
{
	t_animation	animation;
}		t_wall;

typedef struct s_anim_door
{
	void	*frame_0;
	void	*frame_1;
	void	*frame_2;
}		t_anim_door;

typedef struct s_door
{
	int			frames;
	t_anim_door	closed;
	t_anim_door	open;
}		t_door;

typedef struct s_love
{
	t_animation	animation;
	void		*icon;
}		t_love;
typedef struct s_anim_player
{
	void	*frame_0;
	void	*frame_1;
	void	*frame_2;
	void	*frame_move;
}		t_anim_player;

typedef struct s_player
{
	t_anim_player	up_anim;
	t_anim_player	down_anim;
	t_anim_player	left_anim;
	t_anim_player	right_anim;
	int				frames;
	long long int	life;
	long long int	storage;
	long long int	step;
	char			direction;
}		t_player;

typedef struct s_map
{
	char			*map_str;
	void			*ground;
	long long int	len;
	long long int	nbr_key;
	long long int	nbr_exit;
	long long int	nbr_player;
	long long int	nbr_lava;
	long long int	nbr_love;
	long long int	nbr_wall;
	long long int	nbr_void;
}		t_map;

typedef struct s_game
{
	t_player		player;
	t_love			love;
	t_map			map;
	t_lava			lava;
	t_lava			key;
	t_wall			wall;
	t_door			door;
	void			*mlx;
	void			*win;
	long long int	width;
	long long int	height;
}		t_game;

//../src/main.c

void	ft_render(t_game *game);
int		ft_update(t_game *game);
void	ft_print_info_on_window(t_game *game);
void	ft_init_player_info(t_game *game);

//../src/animation_bonus.c

void	ft_wall_animation(t_animation *animation);
void	ft_lava_animation(t_animation *animation);
void	ft_key_animation(t_animation *animation);
void	ft_door_animation(t_door *door);
void	ft_love_animation(t_animation *animation);

//../src/input_bonus.c

int		ft_input_manager(int key, t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

//../src/input_fct_bonus.c  

void	ft_input_up(t_game *game);
void	ft_input_down(t_game *game);
void	ft_input_left(t_game *game);
void	ft_input_right(t_game *game);

//../src/life_management.c

void	ft_display_life_on_windows(t_game *game);
void	ft_anal_yze_line(char	*line);

//../src/load_door_sprite_bonus.c

void	ft_load_door_closed_sprites(t_game *game);
void	ft_load_door_open_sprites(t_game *game);

//../src/load_sprite_bonus.c

void	ft_load_lava_sprites(t_game *game);
void	ft_load_key_sprites(t_game *game);
void	ft_load_wall_sprites(t_game *game);
void	ft_load_ground_sprites(t_game *game);
void	ft_load_love_sprites(t_game *game);

//../src/load_player_sprite_bonus.c 

void	ft_player_animation(t_player *player);
void	ft_load_player_up_sprites(t_game *game);
void	ft_load_player_down_sprites(t_game *game);
void	ft_load_player_left_sprites(t_game *game);
void	ft_load_player_right_sprites(t_game *game);

//../src/map_bonus.c

void	ft_read_map(t_game *game, char *map_name);
void	ft_check_map(t_game *game);
void	ft_check_sealed(t_game *game);
//void	ft_check_rectangular(t_game *game);
void	ft_check_playability(t_game *game);
void	ft_get_info_map(t_game *game);

//../src/map_sprite_bonus.c

void	ft_key_sprite(t_game *game, int width, int height);
void	ft_lava_sprite(t_game *game, int width, int height);
void	ft_love_sprite(t_game *game, int width, int height);
void	ft_exit_sprite(t_game *game, int width, int height);
void	ft_ground_sprite(t_game *game, int width, int height);

//../src/other_tools_bonus.c 

void	ft_print_map_better_format(t_game *game);;
void	ft_print_game_info(t_game *game, int key_code);
void	ft_print_facing(t_game *game);
void	ft_direction_by_pos_after_launch(t_game *game);
int		ft_lose_game(t_game *game);

//../src/player_sprite_direction_bonus.c

void	ft_player_sprite_call(t_game *game, int width, int height);
void	ft_down_sprite(t_game *game, int width, int height);
void	ft_up_sprite(t_game *game, int width, int height);
void	ft_left_sprite(t_game *game, int width, int height);
void	ft_right_sprite(t_game *game, int width, int height);

//../src/so_long_bonus.c

void	ft_init_game(t_game *game, char *map_name);
int		ft_exit_game(t_game *game);
int		ft_win_game(t_game *game);
void	ft_print_error(char *error_msg);
void	ft_check_valid_char(t_game *game);

//../src/sprite_bonus.c

void	ft_load_sprites(t_game *game);
void	ft_put_sprites_by_line(t_game *game);
void	ft_put_all_sprites_to_line(t_game *game, int width, int height);
void	ft_wall_sprite(t_game *game, int width, int height);

//../src/tools_bonus.c

char	*ft_custom_strdup(char *s1);
int		ft_custom_strlcpy(char *dst, char *src, int dst_size);
char	*ft_custom_strjoin(char *s1, char *s2);
void	ft_check_env(char **env);
int		ft_check_extension(char *map_name, char *extension);

#endif
