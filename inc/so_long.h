/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:57:29 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/12 16:28:55 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//mac deine __apple_ and __linux 
//for copatibility

#include <stdlib.h> 
#include <unistd.h>

# define ERROR_MSG	        "Error\n"
# define WALL_CHAR          '1'
# define COLLECTIBLE_CHAR   'C'
# define EXIT_CHAR          'E'
# define PLAYER_CHAR        'P'
# define ESC		         53
# define W			         13
# define A			         0
# define S			         1
# define D			         2

typedef struct s_game
{
	void	*mlx;
	void	*win;
    int		width;
	int		height;
	int		step_count;
}				t_game;

typedef struct s_sprites {
	void	*player;
	void	*wall;
}				t_sprites;

int		main(int ac, char *av[]);

//../src/input.c

int     ft_input_manager();
void	ft_move_up();
void	ft_move_left();
void	ft_move_down();
void	ft_move_right();

void	ft_init_game();
int     ft_exit_game();
int		ft_win_game();
void	ft_print_error(char *error_msg);

int     ft_init_sprites(void *mlx);
void	ft_put_sprites_by_line(t_game *game);
void	ft_put_all_sprites_to_line(t_game *g, int width, int height);

#endif
