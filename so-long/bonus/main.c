/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/17 02:45:28 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int     ft_input_manager(int key_code, t_game *game)
{
	//add fleche and s d a d minisccule and else if
	/*
	 65362 u
	x: 65364 d
	x: 65361 l
	x: 65363 r

key_code 91 : 
key_code 84 : 
key_code 86 : 
key_code 88 : 

digonal move on 	DOWN_ARROW_KEY = 125,
	LEFT_ARROW_KEY = 123,
	RIGHT_ARROW_KEY = 125,
	*/
	if (key_code == 53)
		ft_exit_game(game);
	if (key_code == 13)
		ft_move_up(game);
    if (key_code == 1)
		ft_move_down(game);
	if (key_code == 0)
		ft_move_left(game);
	if (key_code == 2)
		ft_move_right(game);
/*
	if (key_code == ESC_KEY)
		ft_exit_game(game);
	if (key_code == W_KEY || key_code == UP_ARROW_KEY || key_code == UP_PAV_NUM_KEY)
		ft_move_up(game);
    if (key_code == S_KEY || key_code == DOWN_ARROW_KEY || key_code == DOWN_PAV_NUM_KEY)
		ft_move_down(game);
	if (key_code == A_KEY || key_code == LEFT_ARROW_KEY || key_code == LEFT_PAV_NUM_KEY)
		ft_move_left(game);
	if (key_code == D_KEY || key_code == RIGHT_ARROW_KEY || key_code == RIGHT_PAV_NUM_KEY)
		ft_move_right(game);
*/
    //else
        /*iddle animation*/
	ft_printf("---------------------\n");
	ft_printf("Key code : %d \n", key_code);
	ft_printf("Storage : %d \n", game->storage);
	ft_printf("Map coin : %d \n", game->coin);
	//ft_printf("Step : %d\n", game->step);
	ft_printf("---------------------\n");
	return (EXIT_SUCCESS);
}

void	ft_render(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	//mlx_put_image_to_window(game->mlx, game->win, game->sprite.wall, 64,  64);
	ft_put_sprites_by_line(game);
	//mlx_destroy_image(game->mlx, game->sprite.wall);
}


void	ft_wall_animation(t_sprites *sprite)
{

    static int	frame;
	if (sprite->wall_frames == 0)
		return ;
	if (frame == sprite->wall_frames)
	{
		sprite->wall = sprite->wall_0;
	}
	else if (frame >= sprite->wall_frames * 2)
	{
		sprite->wall = sprite->wall_1;
		frame = 0;
	}
	frame += 1;
}


void	ft_player_animation(t_sprites *sprite)
{
    static int	frame;
	if (sprite->player_frames == 0)
		return ;
	if (frame == sprite->player_frames)
	{
		sprite->player_up = sprite->player_up_frame_0;
		sprite->player_down = sprite->player_down_frame_0;
		sprite->player_left = sprite->player_left_frame_0;
		sprite->player_right = sprite->player_right_frame_0;
	}
	else if (frame >= sprite->player_frames * 2)
	{
		sprite->player_up = sprite->player_up_frame_1;
		sprite->player_down = sprite->player_down_frame_1;
		sprite->player_left = sprite->player_left_frame_1;
		sprite->player_right = sprite->player_right_frame_1;
		frame = 0;
	}
	frame += 1;
}


int	ft_update(t_game *game)
{
    //printf("ici\n");
	ft_wall_animation(&game->sprite);
	ft_player_animation(&game->sprite);
	ft_render(game);
	return (1);
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
		//mlx_key_hook(game->win, &ft_input_manager, game);
		mlx_hook(game->win, 2, 0, &ft_input_manager, game);
		mlx_hook(game->win, 17, 0, &ft_exit_game, game);//for exit button
		mlx_loop_hook(game->mlx, &ft_update, game);
		mlx_loop(game->mlx);
	}
	return(EXIT_SUCCESS);
}
 /*

 animate door if there is all coin in storage
 
 so make a variable in stuct 0 or 1 to see if we can activate animation

 convert coin.xpm -scale 64x64 coin.xpm
ImageMagick,

 $(GCC) $(SRC) $(INC) $(OBJ) 
 -Lmlx_linux -lmlx_Linux -L/usr/lib 
 -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
 
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
