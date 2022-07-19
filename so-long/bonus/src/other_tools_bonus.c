/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:41:41 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/19 15:00:23 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"
#include<time.h>

void    ft_print_map_better_format(t_game *game)
{
    int idx;
    int reset;

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
*/

void    ft_print_game_info(t_game *game, int key_code)
{
    ft_printf("----------------------------------\n");
    ft_printf("**********************************\n");
	ft_printf("* key pressed : %d               \n", key_code);
	ft_printf("* Life : NONE                     \n");
	ft_printf("* Remaining key : %d             \n", (game->map.nbr_key - game->storage));
	ft_printf("* Status : i or m NONE            \n");
	ft_printf("* Number of void : %d             \n", game->map.nbr_void);
	ft_printf("* Number of Wall : %d             \n", game->map.nbr_wall);
	ft_printf("* Number of Lava : %d             \n", game->map.nbr_lava);
	ft_printf("* Number of Ennemie : NONE        \n");
	ft_printf("* Storage : %d                    \n", game->storage);
	ft_printf("* Map key : %d                   \n", game->map.nbr_key);
	ft_printf("* Step counter : %d               \n", game->step);
    ft_print_facing(game);
    ft_printf("**********************************\n");
	ft_printf("----------------------------------\n");
}

void    ft_print_facing(t_game *game)
{
    if (game->direction == 'u')
        ft_printf("* Facing : up                     \n");
    if (game->direction == 'd')
        ft_printf("* Facing : down                   \n");
    if (game->direction == 'l')
        ft_printf("* Facing : left                   \n");
    if (game->direction == 'r')
        ft_printf("* Facing : right                  \n");
}

void    ft_direction_by_pos_after_launch(t_game *game)
{
    int random;

    srand(time(0));
    random = rand() % 4;
    //ft_printf("%d", random);

    if (random == 0)
        game->direction = 'u';
    if (random == 1)
        game->direction = 'd';
    if (random == 2)
        game->direction = 'l';
    if (random == 3)
        game->direction = 'r';
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


int		ft_lose_game(t_game *game)
{
	ft_printf(LOSE_MSG "%d ", game->step);
	ft_printf("Storage : %d\n", game->storage);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_FAILURE);
}
