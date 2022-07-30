/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/31 01:28:25 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_mac/so_long_bonus_mac.h"

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
 * 				> norminette bonus_* inc_* src_* lib main_*
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
		ft_check_env(envp);
		game = malloc(sizeof(t_game));
		if (game == NULL)
			ft_print_error(MALLOC_GAME_ERROR);
		if (!ft_check_extension(argv[1], BER_EXTENSION))
			ft_print_error(EXTENSION_ERROR);
		ft_init_game(game, argv[1]);
		mlx_mouse_hide(game->win);
		mlx_hook(game->win, MAC_KEY_PRESS, FALSE, &ft_input_manager, game);
		mlx_hook(game->win, MAC_CLOSE_ICON, FALSE, &ft_exit_game, game);
		mlx_loop_hook(game->mlx, &ft_update, game);
		mlx_loop(game->mlx);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * clean the game and print back the sprite to
 * create animation feeling because all the frame 0
 * is change by the seconde and the third every time
 * 
 * @param game 
 */
void	ft_render(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	ft_put_sprites_by_line(game);
	ft_print_info_on_window(game);
}

/**
 * @brief 
 * 
 * this fct is call every time int loop by mlx_loop_hook
 * and trigger the animation of wall player lava love key door
 * and then render the new sprite for each elem by cleaning the win
 * and printing again line by line all the sprite and also print a 
 * hud type for player info in the windows
 * 
 * put just before for lava moving all the time ft_random_lava_move(game);
 * my bad i dix it look in the comment to change the game dynamic
 * 
 * @param game 
 * @return int 
 */
int	ft_update(t_game *game)
{
	ft_wall_animation(&game->wall.animation);
	ft_player_animation(&game->player);
	ft_lava_animation(&game->lava.animation);
	ft_love_animation(&game->love.animation);
	ft_key_animation(&game->key.animation);
	ft_door_animation(&game->door);
	ft_random_lava_move(game);
	ft_render(game);
	return (EXIT_SUCCESS);
}

/**
 * @brief
 * 
 * 		This fct set all the player stat in game.player[]
 * 				1 life because 1 is enough
 * 			0 for storage step  and the frames is 9
 * 				after several test 9 feel good
 * 		we also generate randomly a direction of the first
 * 			int of the player to give player more life
 * 		we use srand rand of 4 digit (up down left right)
 * 						u d l r
 * 
 * @param game 
 */
void	ft_init_player_info(t_game *game)
{
	game->player.life = TRUE;
	game->player.storage = FALSE;
	game->player.frames = 9;
	game->player.step = FALSE;
	game->player.storage = FALSE;
	ft_direction_by_pos_after_launch(game);
}

/**
 * @brief
 * 
 * 	we display a itoa o step storage on the win and free it the end
 * 	we print all info in color define in the define header
 * 	we can make a fct for the print of up down life right but iam lazy
 * 	so in fct of the char in game->player.direction we print the
 * 	full word in color
 * 	
 * 
 * @param game 
 */
void	ft_print_info_on_window(t_game *game)
{
	char	*str_step;
	char	*str_storage;

	str_step = ft_itoa(game->player.step);
	str_storage = ft_itoa(game->player.storage);
	ft_display_life_on_windows(game);
	mlx_string_put(game->mlx, game->win, 5, 42, YELLOW, "Step-> ");
	mlx_string_put(game->mlx, game->win, 69, 42, RED, str_step);
	mlx_string_put(game->mlx, game->win, 5, 52, RED, "Storage-> ");
	mlx_string_put(game->mlx, game->win, 69, 52, RED, str_storage);
	mlx_string_put(game->mlx, game->win, 5, 62, AQUA, "Facing-> ");
	if (game->player.storage == game->map.nbr_key)
		mlx_string_put(game->mlx, game->win, 69, 52, GREEN, str_storage);
	if (game->player.direction == 'u')
		mlx_string_put(game->mlx, game->win, 69, 62, LIME, "Up");
	if (game->player.direction == 'd')
		mlx_string_put(game->mlx, game->win, 69, 62, YELLOW, "Down");
	if (game->player.direction == 'l')
		mlx_string_put(game->mlx, game->win, 69, 62, PINK, "Left");
	if (game->player.direction == 'r')
		mlx_string_put(game->mlx, game->win, 69, 62, TURQUOISE, "Right");
	free(str_step);
	free(str_storage);
}

/*

			PERSONAL COMMENT IDEAD RANDOM STUFF

						/\     \
                      /  \     \
                     /    \_____\
                    _\    / ____/_
                   /\ \  / /\     \
                  /  \ \/_/  \     \
                 /    \__/    \_____\
                _\    /  \    / ____/_
               /\ \  /    \  / /\     \
              /  \ \/_____/\/_/  \     \
             /    \_____\    /    \_____\
            _\    /     /    \    / ____/_
           /\ \  /     /      \  / /\     \
          /  \ \/_____/        \/_/  \     \
         /    \_____\            /    \_____\
        _\    /     /            \    / ____/_
       /\ \  /     /              \  / /\     \
      /  \ \/_____/                \/_/  \     \
     /    \_____\                    /    \_____\
    _\    /     /_  ______  ______  _\____/ ____/_
   /\ \  /     /  \/\     \/\     \/\     \/\     \
  /  \ \/_____/    \ \     \ \     \ \     \ \     \
 /    \_____\ \_____\ \_____\ \_____\ \_____\ \_____\
 \    /     / /     / /     / /     / /     / /     /
  \  /     / /     / /     / /     / /     / /     /
   \/_____/\/_____/\/_____/\/_____/\/_____/\/_____/

		[Dont work harder work smarter]
			[TODO IF NOT TOO LAZY]
		
*		rename all file name with prefix ft_
*		for bonus use mlx string pu with a 
		special font or sprite like life
*		put commun fct in spefic file to share 
			btw bonus and mandatory
*	read all the project to found repetition
			and make 5 in 1 ex : 
  		try to make modularity for move ?
*		share define or define file for mandatory
*	better file organisation and include order
* 		add start and end windows
* 			status iddle or mouving
* 		ft_print_spite_error char path
* 			ft_split_path char * path
* 		reset button r to reload the game
* 			try to limit int overflow long long
			or life storage limit
* 			versus mode 1v1
* 		make file cross platform
				make linux make os
	
* 		make a simple step by step for 100
* 			make a simple step by step for bonus

			[WHAT I HAVE FOUND]
	
			ImageMagick
		convert key.xpm -scale 64x64 key.xpm
//mlx_key_hook(game->win, &ft_input_manager, game);

#	@make --no-print-directory -C ft_printf
#	@make --no-print-directory -C mlx lib_so_long.a

-L$./mlx-linux/ -lmlx -lXext -lX11
 -L$./MLX_MAC/ -lmlx -framework OpenGL -framework AppKit

FLAGS += -I$(MLXDIR)

OS := $(shell uname)

 ifeq ($(OS),Darwin)
	MLXDIR = $(MACDIR)
	MLXFLAGS = $(MACFLAGS)
else ifeq ($(OS),Linux)
	MLXDIR = $(LINUXDIR)
	MLXFLAGS = $(LINUXFLAGS)
else
$(error Incompatable OS Detected)
endif


# 		$(GCC) -o $(NAME) $(SRC) -L. 
$(LIB_NAME) -L. $(MLX_PATH)/$(MLX_NAME) $(FRAME_WORK)
# 		-lXext -lX11

 		$(GCC) $(SRC) $(INC) $(OBJ) 
 			-Lmlx_linux -lmlx_Linux -L/usr/lib 
 		-Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

		 [DEFENSE]
		-g3 -fsanitize=addres
		envi -i check necessaire ??

			[IDEA]

		 	konamie code
	konami code for invisibility on everyting

	moving ennemie (maybe tracing)
	* Theme song
		* song when take item
			* song when die
* try to nake a difference btw normal iddel instant and delay iddle
*	random idea : save the file name in struc
	 to display it in error msg
IDEAD : add timer counter because frame is every seconde in upadte ???

//random idea : save the file name in struc to display it in error msg

place pillar instead of wall inside the map only

add versus mode only 2 player
Jai envie dajouter un timer, un vs mode un stysteme
 de path founding pour les ennemies

*/

/*   
			IDEA
			
    on parcour la  map
    si inc une valeur pur trouver la position de p
    si on trouve l position on arrete et on sort de la boucle
    on a pas bessoin de verifier que p existe dans la map on 
    le fait deja dan check playabibliity
    
    du coup si la pos de p est sup a a la moitier de la longeur
    de la map on regarde a gquche don l
        sinon r
        et si on est au mileu top on regarde vers le baa
        milieu bas on regarde vers le haut

        0                           0
            r       d           l
            
                               
            r        u          l 

        0                           0

    Just realiszed that i could like the face only if there is nothing in face
    managee case where he can not move
        like defaut looking or looking by the pos in map
        
*/

/*
				IDEAD
		DIAGONAL MOVE IF 7 9 1 3 is pressed
	fct who combine move (up + left) by the  vailableness up up or let etc


    else
        iddle animation counter 5 sec

*/

/*
	not a problem but for future futur me with more skill
	there is a astetic problem of the print diirectly on the
	windows, cool if you can make a more cool way to see it i 
	dont realy know

		idea font or sprite for step
		or info like ft_print_game_info)
		on screen
		with a map tracking only if there 
		is a camera zoom
*/

/*
			int temp;
			int temp1;
			int temp11;
			int temp111;
	Because using temp2, temp3 would be too mainstream.
			char coal
			float away; 
			long long ago;
			char mander; 
	long timeAgo;	// In a galaxy far far away 
			bool dozer; 
			int erNalExam; 
			short circuit; 
			short onTime; 
			double trouble; 
Exception up = new Exception("Something is wrong"); 
			throw up; 
*/
