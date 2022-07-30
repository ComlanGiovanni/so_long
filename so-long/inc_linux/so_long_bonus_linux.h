/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_linux.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:57:29 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/31 01:01:09 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_LINUX_H
# define SO_LONG_BONUS_LINUX_H

# include "../mlx_linux/mlx.h"
# include "../lib/small_lib/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "so_long_define_bonus_linux.h"

typedef enum e_key_code_linux {
	LINUX_CLOSE_ICON = 17,
	LINUX_ESC_KEY = 65307,
	LINUX_KEY_PRESS = 2,
	LINUX_KEY_RELEASE = 3,
	LINUX_W_KEY = 119,
	LINUX_A_KEY = 97,
	LINUX_S_KEY = 115,
	LINUX_D_KEY = 100,
	LINUX_UP_ARROW_KEY = 65362,
	LINUX_DOWN_ARROW_KEY = 65364,
	LINUX_LEFT_ARROW_KEY = 65361,
	LINUX_RIGHT_ARROW_KEY = 65363,
	LINUX_UP_PAV_NUM_KEY = 65431,
	LINUX_DOWN_PAV_NUM_KEY = 65433,
	LINUX_LEFT_PAV_NUM_KEY = 65430,
	LINUX_RIGHT_PAV_NUM_KEY = 65432
}	t_key_code_linux;

// lol read le scp-10
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
	void	*current;
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
	void	*current;
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
	void	*current;
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
	char			*str_step;
	char			*str_storage;
	long long int	width;
	long long int	height;
	long long int	empty_line;
}		t_game;

//../src/bonus/main.c

void	ft_moving_lava(t_game *game);
void	ft_render(t_game *game);
int		ft_update(t_game *game);
void	ft_print_info_on_window(t_game *game);
void	ft_init_player_info(t_game *game);

//../src/bonus/animation_bonus.c

void	ft_wall_animation(t_animation *animation);
void	ft_lava_animation(t_animation *animation);
void	ft_key_animation(t_animation *animation);
void	ft_door_animation(t_door *door);
void	ft_love_animation(t_animation *animation);

//../src/bonus/check_map_format.c   

int		get_map_height(char *map_name, t_game *game);
void	check_ber_format(char *map_name, int height, t_game *game);
void	ft_init_map_info(t_game *game, char *line);
void	ft_check_rectangular(t_game *game);

//../src/bonus/free_all.c

void	ft_free_all(t_game *game);
void	ft_free_player(t_game *game);
void	ft_free_player_move(t_game *game);
void	ft_free_map_love_lava(t_game *game);
void	ft_free_key_wall_door(t_game *game);

//../src/bonus/input_bonus.c

int		ft_manag_input(int key, t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

//../src/bonus/input_fct_bonus.c  

void	ft_input_up(t_game *game);
void	ft_input_down(t_game *game);
void	ft_input_left(t_game *game);
void	ft_input_right(t_game *game);

//../src/bonus/lava_movement.c

void	ft_move_lava(t_game *game);
void	ft_lava_move_up(t_game *game);
void	ft_lava_move_down(t_game *game);
void	ft_lava_move_left(t_game *game);
void	ft_lava_move_right(t_game *game);

//../src/bonus/life_management.c

void	ft_display_life_on_windows(t_game *game);
void	ft_random_lava_move(t_game *game);
void	ft_map_fit_screen(t_game *game);
void	ft_load_player_current(t_game *game);
void	ft_print_error_empty_and_free(char *error_msg, t_game *game);

//../src/bonus/load_door_sprite_bonus.c

void	ft_load_door_closed_sprites(t_game *game);
void	ft_load_door_open_sprites(t_game *game);

//../src/bonus/load_sprite_bonus.c

void	ft_load_lava_sprites(t_game *game);
void	ft_load_key_sprites(t_game *game);
void	ft_load_wall_sprites(t_game *game);
void	ft_load_ground_sprites(t_game *game);
void	ft_load_love_sprites(t_game *game);

//../src/bonus/load_player_sprite_bonus.c 

void	ft_player_animation(t_player *player);
void	ft_load_player_up_sprites(t_game *game);
void	ft_load_player_down_sprites(t_game *game);
void	ft_load_player_left_sprites(t_game *game);
void	ft_load_player_right_sprites(t_game *game);

//../src/bonus/map_bonus.c

void	ft_read_map(t_game *game, char *map_name);
void	ft_check_map(t_game *game);
void	ft_check_sealed(t_game *game);
void	ft_check_playability(t_game *game);
void	ft_get_info_map(t_game *game);

//../src/bonus/map_sprite_bonus.c

void	ft_key_sprite(t_game *game, int width, int height);
void	ft_lava_sprite(t_game *game, int width, int height);
void	ft_love_sprite(t_game *game, int width, int height);
void	ft_exit_sprite(t_game *game, int width, int height);
void	ft_ground_sprite(t_game *game, int width, int height);

//../src/bonus/other_tools_bonus.c 

void	ft_print_map_better_format(t_game *game);;
void	ft_print_game_info(t_game *game, int key_code);
void	ft_print_facing(t_game *game);
void	ft_direction_by_pos_after_launch(t_game *game);
int		ft_lose_game(t_game *game);

//../src/bonus/player_sprite_direction_bonus.c

void	ft_player_sprite_call(t_game *game, int width, int height);
void	ft_down_sprite(t_game *game, int width, int height);
void	ft_up_sprite(t_game *game, int width, int height);
void	ft_left_sprite(t_game *game, int width, int height);
void	ft_right_sprite(t_game *game, int width, int height);

//../src/bonus/so_long_bonus.c

void	ft_init_game(t_game *game, char *map_name);
int		ft_exit_game(t_game *game);
int		ft_win_game(t_game *game);
void	ft_print_error(char *error_msg, t_game *game);
void	ft_check_valid_char(t_game *game);

//../src/bonus/sprite_bonus.c

void	ft_load_sprites(t_game *game);
void	ft_put_sprites_by_line(t_game *game);
void	ft_put_all_sprites_to_line(t_game *game, int width, int height);
void	ft_wall_sprite(t_game *game, int width, int height);

//../src/bonus/tools_bonus.c

char	*ft_custom_strdup(char *s1);
int		ft_custom_strlcpy(char *dst, char *src, int dst_size);
char	*ft_custom_strjoin(char *s1, char *s2);
void	ft_check_env(char **env);
int		ft_check_extension(char *map_name, char *extension);

#endif
