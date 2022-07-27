/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mac.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:57:29 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/27 16:02:11 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MAC_H
# define SO_LONG_MAC_H

# include "../mlx_mac/mlx.h"
# include "../lib/small_lib/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"

# define BER_EXTENSION	    ".ber"
# define ERROR_MSG	        "Error\n"
# define GAME_TITLE	        "./so_long"
# define USAGE_MSG	        "./so_long [pass to map][map name].ber\n"
# define NO_ENV_ERROR       "No variable environment available\n"
# define NO_DISP_ERROR      "DISPLAY not found in env\n"
# define MALLOC_GAME_ERROR	"Malloc t_game fail to\n"
# define BAD_CHAR_MAP_ERROR	"Map Should contain char : '1' 'P' 'C' 'E' '0'\n"
# define WALL_ERROR	        ".ber should be surrounded by walls : 1\n"
# define FORM_ERROR	        ".ber should be in rectangular form !\n"
# define COIN_ERROR			".ber should have at least one collectible -> C\n"
# define PLAYER_ERROR		".ber should have one starting point -> P\n"
# define EXIT_ERROR			".ber should have at east one exit -> E\n"
# define EXTENSION_ERROR	"Map extension should be a .ber\n"
# define FAIL_OPEN_ERROR	".ber fail to open\n"
# define MLX_INIT_ERROR		"mlx_init() fail\n"
# define MLX_WINDOW_ERROR	"mlx_new_window() fail\n"
# define PLAYER_XPM_ERROR	"player.xpm fail to load\n"
# define GROUND_XPM_ERROR	"ground.xpm fail to load\n"
# define WALL_XPM_ERROR		"wall.xpm fail to load\n"
# define KEY_XPM_ERROR		"key.xpm fail to load\n"
# define EXIT_XPM_ERROR		"exit.xpm fail to load\n"
# define WIN_MSG			"Thanks for playing, you win with steps : "
# define EMPTY_LINE 		"Remove that empty line at the top or middle\n"

typedef enum e_key_code {
	CLOSE_ICON = 17,
	ESC_KEY = 53,
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	UP_ARROW_KEY = 126,
	DOWN_ARROW_KEY = 125,
	LEFT_ARROW_KEY = 123,
	RIGHT_ARROW_KEY = 124,
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2
}	t_key_code;

typedef enum e_map_char
{
	WALL_CHAR = '1',
	PLAYER_CHAR = 'P',
	COIN_CHAR ='C',
	EXIT_CHAR = 'E',
	VOID_CHAR = '0'
}	t_map_char;

// true false enum for loop if etc
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

// sprite struct
typedef struct s_sprites {
	void	*player;
	void	*ground;
	void	*wall;
	void	*key;
	void	*exit;
}		t_sprites;

// game struct
typedef struct s_game
{
	t_sprites		sprite;
	long long int	step;
	void			*mlx;
	void			*win;
	char			*map;
	long long int	map_len;
	long long int	width;
	long long int	height;
	long long int	key;
	long long int	storage;
	long long int	exit;
	long long int	player;
}		t_game;

//main.c

//../src/check_map_format.c   

int			get_map_height(char *map_name);
void		check_ber_format(char *map_name, int height);
void		ft_init_map_info(t_game *game, char *line);

//../src/input.c
int			ft_input_manager(int key, t_game *game);
void		ft_move_up(t_game *game);
void		ft_move_down(t_game *game);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);

//../src/map.c

void		ft_read_map(t_game *game, char *map_name);
void		ft_check_map(t_game *game);
void		ft_check_sealed(t_game *game);
void		ft_check_rectangular(t_game *game);
void		ft_check_playability(t_game *game);

//../src/so_long.c

void		ft_init_game(t_game *game, char *map_name);
int			ft_exit_game(t_game *game);
int			ft_win_game(t_game *game);
void		ft_print_error(char *error_msg);
void		ft_check_valid_char(t_game *game);

//../src/sprite.c

t_sprites	ft_init_sprites(void *mlx);
void		ft_put_sprites_by_line(t_game *game);
void		ft_put_all_sprites_to_line(t_game *game, int width, int height);

//../src/tools.c

char		*ft_custom_strdup(char *s1);
int			ft_custom_strlcpy(char *dst, char *src, int dst_size);
char		*ft_custom_strjoin(char *s1, char *s2);
void		ft_check_env(char **env);
int			ft_check_extension(char *map_name, char *extension);

#endif
