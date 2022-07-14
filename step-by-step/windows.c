/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:34:57 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/14 11:52:40 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

# define GAME_TITLE	        "Simple window"

/*

void	*mlx_init()

void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title)

width -> largeur
height -> longeur

*/

int	main(void)
{
    void	  *mlx;
	void   	  *win;
3
	int		  height;
	int		  width;

    height = 720;
    width = 320;

	mlx = mlx_init();
    win = mlx_new_window(mlx, height, width, GAME_TITLE);
	mlx_loop(mlx);
}
