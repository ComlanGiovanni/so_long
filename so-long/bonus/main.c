/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/18 22:09:22 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/**
 * @brief 
 * 
 * 		Gamers can feel when developers are passionate about their games.
 * 				They can smell it like a dog smells fear.
 * 			Don't be afraid to hold onto your unique vision:
 * 		Just be aware that it may not turn out exactly how you envisioned.
 * 
 * 							-[Scott Rogers]-
 * 
 * @param argc 
 * @param argv 
 * @param envp 
 * @return int 
 */
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

void	ft_render(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	//mlx_put_image_to_window(game->mlx, game->win, game->sprite.wall, 64,  64);
	ft_put_sprites_by_line(game);
	//mlx_destroy_image(game->mlx, game->sprite.wall);
}

int	ft_update(t_game *game)
{
	ft_wall_animation(&game->wall.animation);
	ft_player_animation(&game->sprite);
	//ft_player_animation(&game->sprite);
	ft_lava_animation(&game->lava.animation);
	ft_key_animation(&game->key.animation);
	ft_render(game);
	return (EXIT_SUCCESS);
}

 /*

 in my bonus the map can be square

 //for bonus use mlx string pu with a special font ?

ROAD TO CLEAN THIS PROJECT

	* put commun fct in spefic file
	* have differente header if to much deine
		define.h or exmple
		define_communm.h define_bonus.h
	* make different struc for player aniation map etc
		see if good idea for both
	*
	* # define IMG_SIZE 64
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
	* total key
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
	* draw_text(t_game game) for score
			print with sprite 1 2 3 font
	* try to make modularity for move ?
	* ft_print_spite_error char * path
	* ft_split_path char * path
	*
	* make a simple step by step for 100
	* step by step 125 letter
	* reset key 
		destroy everything
			and call back previos fct after the initial init
	*
	* Struct to make a list of enemies
	* NNNNOOOOOORRRRRRMMMMMMMMMEEEEEEEE

	// wht if the move hi max int for printf ??

no more ft_strlen(game->map) in file

	NEXT LVL BIG BRAIN DONT DO IT NOW PLEASE BUT FOR YOURSEL 2PLAYER !!1

-g3 -fsanitize=addres

envi -i check necessaire ??
because work witout

animate door if there is all key in storage

so make a variable in stuct 0 or 1 to see if we can activate animation

ImageMagick
	convert key.xpm -scale 64x64 key.xpm

make file cross platform
	make linux
	make os

in define change input key code

#	@make --no-print-directory -C ft_printf
#	@make --no-print-directory -C mlx lib_so_long.a


# $(GCC) -o $(NAME) $(SRC) -L. $(LIB_NAME) -L. $(MLX_PATH)/$(MLX_NAME) $(FRAME_WORK)
# -lXext -lX11


 $(GCC) $(SRC) $(INC) $(OBJ) 
 -Lmlx_linux -lmlx_Linux -L/usr/lib 
 -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

random idea : save the file name in struc to display it in error msg

some level design map for bonus with lava aamd

header file for error, split file
get fault map empyt or oneline
mlx string put for bonus

		call ft_exit game windows
		clean win
		pintf the win message with a xmp gg wp aninmated pixel theme

		IDEAD : add timer counter because frame is evry seconde in upadte ???

//random idea : save the file name in struc to display it in error msg

Plus for readme
	player do animation move even if he can not go to the next case
	print the map in the console
	print map info in console

place pillar instead of wall inside the map only

*/
