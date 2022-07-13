/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:57:29 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/13 15:55:18 by gcomlan          ###   ########.fr       */
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

# include "../minilibx/mlx.h"
# include "../lib/small_lib/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"

# define ERROR_MSG	        "Error\n"
# define GAME_TITLE	        "./so_long"
# define USAGE_MSG	        "./so_long [pass to map][map name].ber\n"
# define WALL_ERROR	        "[Map_name].ber should be surrounded by walls : 1 see [maps]/classic.ber\n"
# define FORM_ERROR	        "[Map_name].ber should be in rectangular form !\n"
# define COIN_ERROR			"[Map_name].ber should have at least one collectible -> C\n"
# define PLAYER_ERROR		"[Map_name].ber should have one starting point -> P\n"
# define EXIT_ERROR			"[Map_name].ber should have at east one exit -> E\n"
# define KEY_PRESS			2
# define KEY_RELEASE		3
# define KEY_EXIT		    17
# define WALL_CHAR          '1'
# define PLAYER_CHAR        'P'
# define COIN_CHAR   		'C'
# define EXIT_CHAR          'E'
# define VOID_CHAR          '0'
# define ESC		         53
# define W			         13
# define A			         0
# define S			         1
# define D			         2

typedef struct s_sprites {
	void	*player;
	void	*ground;
	void	*wall;
	void	*coin;
	void	*exit;
}		t_sprites;

typedef struct s_game
{
    t_sprites sprite;
	void	  *mlx;
	void   	  *win;
    char      *map;
    int		  width;
	int		  height;
	int		  step;
	int		  coin;
	int		  storage;
	int		  exit;
	int		  player;
}		t_game;

//int		main(int ac, char *av[]);

//../src/input.c

int     ft_input_manager(t_game *game, int key);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

//../src/map.c

void	ft_read_map(t_game *game, char *filename);
void	ft_check_map(t_game *game);
void	ft_check_sealed(t_game *game);
void	ft_check_rectangular(t_game *game);
void	ft_check_playability(t_game *game);

//../src/so_long.c

void	ft_init_game(t_game *game, char *map_name);
int		ft_exit_game(t_game *game);
int		ft_win_game(t_game *game);
void	ft_print_error(char *error_msg);

//../src/sprite.c

t_sprites	ft_init_sprites(void *mlx);
void		ft_put_sprites_by_line(t_game *game);
void		ft_put_all_sprites_to_line(t_game *game, int width, int height);

//../src/tools.c

char	*ft_custom_strdup(char *s1);
int		ft_custom_strlcpy(char *dst, char *src, int dst_size);
char	*ft_custom_strjoin(char *s1, char *s2);

#endif
