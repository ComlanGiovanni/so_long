/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:28:58 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/14 23:40:38 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

#include <stdlib.h>

# define GAME_TITLE	        "Simple window"
# define HELLO_WORLD	    "HELLO WORLD"
# define BLUE 0x0000FF
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define BROWN 0x993300
# define WHITE 0xFFFFFF

/*
void *mlx_xpm_file_to_image(t_xvar *xvar,char *filename, int *width, int *height)
  return (mlx_int_xpm_f_image(xvar,width,height,XpmReadFileToImage,filename));
    return a t_img		*im2;

    we can put it in    void *xpm_img;

if ((xpm_img = mlx_xpm_file_to_image(mlx, "cursor.xpm", &wid, &hei)) == NULL)
	return (EXIT_FAILURE);
        we need to check if the xpm success exit if not to prevent segfault

int	mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img, int x,int y)
    take the void *img we create
mlx_put_image_to_window(mlx, win, xpm_img, 100, 100);

1 - dont know yet if int *width, int *height is usefull in mlx_xpm_file_to_image

*/

int	main(void)
{
    void	  *mlx;
	void   	  *win;
	int		  width;
	int		  height;
    void      *xpm_img;
    int		  wid;
	int		  hei;
    int       maybe_title;

    maybe_title = 20;
    width = 720;
    height = 720;

    //wid = 10;
    //hei = 10;

    if ((mlx = mlx_init()) == NULL)
        return (EXIT_FAILURE);

    if ((win = mlx_new_window(mlx, height, width, GAME_TITLE)) == NULL)
        return (EXIT_FAILURE);

    if ((xpm_img = mlx_xpm_file_to_image(mlx, "cursor.xpm", &wid, &hei)) == NULL)
		return (EXIT_FAILURE);

    mlx_put_image_to_window(mlx, win, xpm_img, 100, 100);

	mlx_loop(mlx);
}
