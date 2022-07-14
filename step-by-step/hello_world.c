/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:53:40 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/14 23:14:03 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so-long/mlx/mlx.h"

# define GAME_TITLE	        "Simple window"
# define HELLO_WORLD	    "HELLO WORLD"
# define BLUE 0x0000FF
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define TURQ 0x33CCFF
# define BROWN 0x993300
# define WHITE 0xFFFFFF

/*

void	*mlx_init()
    return a t_xvar	*xvar; so we need a void *mlx;

void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y, char *title)
    int size_x  ->  largeur
    int size_y  ->  longeur

int		mlx_loop(t_xvar *xvar) take void *mlx;
    
width -> largeur
height -> longeur

dont know why the text is not center when i / 2 the w and h
maybe because of the pixel of the title ? so i substract 20 pixel ??
*/

int	main(void)
{
    void	  *mlx;
	void   	  *win;

	int		  height;
	int		  width;
    int       maybe_title;

    height = 1080;
    width = 320;
    maybe_title = 20;

	mlx = mlx_init();
    win = mlx_new_window(mlx, height, width, GAME_TITLE);
    mlx_string_put(mlx, win, (height / 2) - maybe_title, (width / 2), RED, HELLO_WORLD);

	mlx_loop(mlx);
}
