/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/18 00:21:09 by gcomlan          ###   ########.fr       */
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

int	main(int argc, char *argv[], char **envp)
{
	t_game	*game;

	if (argc != 2)
        ft_print_error(USAGE_MSG);
	else
	{
		//secure malloc and define x event
		ft_check_env(envp);
		if ((game = malloc(sizeof(t_game))) == NULL)
			ft_print_error(MALLOC_GAME_ERROR);
		if (!ft_check_extension(argv[1], BER_EXTENSION))
			ft_print_error(EXTENSION_ERROR);
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

ROAD TO CLEAN THIS PROJECT

	* put commun fct in spefic file
	* have differente header if to much deine
		define.h or exmple
		define_communm.h define_bonus.h
	* make different struc for player aniation map etc
		see if good idea for both
	*
	*
	* better file organisation
	* add comment in every fct
	* add L end game animated ennemie death for player
	* add mouving ennemie - 1 for lie
	* check free
	* add start and end windows only for bonus
	* add life for player
	* print map in good format
	* print life
	* step
	* storage
	* reamaning coim
	* total coin
	* direction facing
	* status iddle or mouving
	* add iddle sprint only change color
	* nbr of ennemie
	* animate key
	* animate door
	* fct for evry call of aimated sprit
		wall 
		key
		player etc
	*  fct for to load too
	*
	* try to make modularity for move ?
	* ft_print_spite_error char * path
	* ft_split_path char * path
	*
	* make a simple step by step for 100
	* step by step 125 letter
	*
	* NNNNOOOOOORRRRRRMMMMMMMMMEEEEEEEE


-g3 -fsanitize=addres

envi -i check necessaire ??
because work witout

animate door if there is all coin in storage

so make a variable in stuct 0 or 1 to see if we can activate animation

ImageMagick
	convert coin.xpm -scale 64x64 coin.xpm

make file cross platform
	make linux
	make os

in define change input key code

 $(GCC) $(SRC) $(INC) $(OBJ) 
 -Lmlx_linux -lmlx_Linux -L/usr/lib 
 -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

random idea : save the file name in struc to display it in error msg

mlx string put for bonus

*/
