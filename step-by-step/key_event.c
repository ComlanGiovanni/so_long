/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:03:11 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/18 20:29:59 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

#include <stdlib.h>
#include <stdio.h>

# define GAME_TITLE	        "key pressed"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define BLUE 0x0000FF
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define TURQ 0x33CCFF
# define BROWN 0x993300
# define WHITE 0xFFFFFF

typedef struct s_param{
	int		x;
	int		y;
}				t_param;

void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int				key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", param->x, param->y);
	return (0);
}

int			main(void)
{
	void		*mlx;
	void		*win;
	t_param		param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, GAME_TITLE);
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(mlx);
}
