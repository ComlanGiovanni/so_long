/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:41:41 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 14:40:50 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"
#include <time.h>

void	ft_print_map_better_format(t_game *game)
{
	int	idx;
	int	reset;

	idx = 0;
	reset = 1;
	while (idx < game->map.len)
	{
		if (game->map.map_str[idx])
			ft_printf("%c", game->map.map_str[idx]);
		if (reset == game->width)
		{
			ft_printf("\n");
			reset = 0;
		}
		idx++;
		reset++;
	}
}

/*
print nombre exit
print nbr player

	ft_printf("* Remaining Lava : %d\n",
		(game->map.nbr_lava - game->player.life) + 1);
    
    ft_printf("* Remaining  love in map : %d     \n",
		(game->map.nbr_love - game->player.life) + 1);

    fo status fct who print moving if a key is press
    if nop iddle lol add a struct varraible status
*/

void	ft_print_game_info(t_game *game, int key_code)
{
	ft_printf("----------------------------------\n");
	ft_printf("**********************************\n");
	ft_printf("* key pressed : %d                \n", key_code);
	ft_printf("---------MAP INIT INFO------------\n");
	ft_printf("* Number of void : %d             \n", game->map.nbr_void);
	ft_printf("* Number of Wall : %d             \n", game->map.nbr_wall);
	ft_printf("* Number of Lava : %d             \n", game->map.nbr_lava);
	ft_printf("* Number of Love : %d        \n", game->map.nbr_love);
	ft_printf("* Number of Key : %d              \n", game->map.nbr_key);
	ft_printf("---------PLAYER INFO--------------\n");
	ft_printf("* Player Step    : %d             \n", game->player.step);
	ft_printf("* Player Storage : %d             \n", game->player.storage);
	ft_printf("* Player Life : %d                \n", game->player.life);
	ft_print_facing(game);
	ft_printf("---------REMANING--------------\n");
	ft_printf("* Remaining key : %d\n",
		(game->map.nbr_key - game->player.storage));
	ft_printf("* Status : idle or Moving in DLC \n");
	ft_printf("------ALL REMANING IN DLC--------\n");
	ft_printf("*********************************\n");
	ft_printf("---------------------------------\n");
}

void	ft_print_facing(t_game *game)
{
	if (game->player.direction == 'u')
		ft_printf("* Player Facing : up                     \n");
	if (game->player.direction == 'd')
		ft_printf("* Player Facing : down                   \n");
	if (game->player.direction == 'l')
		ft_printf("* Player Facing : left                   \n");
	if (game->player.direction == 'r')
		ft_printf("* Player Facing : right                  \n");
}

void	ft_direction_by_pos_after_launch(t_game *game)
{
	int	random;

	srand(time(0));
	random = rand() % 4;
	if (random == 0)
		game->player.direction = 'u';
	if (random == 1)
		game->player.direction = 'd';
	if (random == 2)
		game->player.direction = 'l';
	if (random == 3)
		game->player.direction = 'r';
}
/*   
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

int	ft_lose_game(t_game *game)
{
	ft_printf(LOSE_MSG "%d ", game->player.step);
	ft_printf("Storage : %d, ", game->player.storage);
	ft_printf("Life : %d\n", game->player.life);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_FAILURE);
}
