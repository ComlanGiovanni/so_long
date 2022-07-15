/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/15 02:32:33 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int     ft_input_manager(int key, t_game *game)
{
	//add fleche and s d a d minisccule and else if
	/*
	 65362 u
x: 65364 d
x: 65361 l
x: 65363 r
	*/
	if (key == ESC_KEY)
		ft_exit_game(game);
	if (key == W_KEY || key == UP_ARROW_KEY || key == UP_PAV_NUM_KEY)
		ft_move_up(game);
    if (key == S_KEY || key == DOWN_ARROW_KEY || key == DOWN_PAV_NUM_KEY)
		ft_move_down(game);
	if (key == A_KEY || key == LEFT_ARROW_KEY || key == LEFT_PAV_NUM_KEY)
		ft_move_left(game);
	if (key == D_KEY || key == RIGHT_ARROW_KEY || key == RIGHT_PAV_NUM_KEY)
		ft_move_right(game);

    //else
        /*iddle animation*/
	ft_printf("---------------------\n");
	ft_printf("Key code : %d \n", key);
	ft_printf("Storage : %d \n", game->storage);
	ft_printf("Map coin : %d \n", game->coin);
	ft_printf("Step : %d\n", game->step);
	ft_printf("---------------------\n");
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
        ft_print_error(USAGE_MSG);
	else
	{
		//secure malloc and define x event
		game = malloc(sizeof(t_game));
		ft_init_game(game, argv[1]);
		mlx_key_hook(game->win, &ft_input_manager, game);
		//mlx_hook(game->win, 2, 0, &ft_input_manager, game);
		mlx_hook(game->win, 17, 0, &ft_exit_game, game);//for exit button
		mlx_loop(game->mlx);
	}
	return(EXIT_SUCCESS);
}
 /*

 convert coin.xpm -scale 64x64 coin.xpm
ImageMagick,
 
int	ft_check_env(char **env)
{
	int	idx;

	if (!*env)
		return (EXIT_FAILURE);
	idx = 0;
	while (env[idx])
	{
		if (!ft_strncmp("DISPLAY", env[idx], ft_strlen(env[idx])))
			return (EXIT_SUCCESS);
		idx++;
	}
	return (EXIT_FAILURE);
}
*/

/*

prevent segfault when map is not found null or something

mlx loop to call all the time
mlx string put for bonus

lib custom

strlen
strdup
strjoin
gnl
printf
ft_itoa
ft_strcmp
ft_putchar_fd
ft_putstr

h for help menum ??

ENV check ??
	if (ft_check_env(env))
		return (0);
*/