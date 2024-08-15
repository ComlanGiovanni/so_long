/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_console_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:52:04 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 12:32:20 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_print_fill_grid(char **map)
{
	ft_print_display_grid(map);
	system("clear");
}

void	ft_print_display_grid(char **res)
{
	if (!res)
		return ;
	while (*res)
	{
		ft_printf("%s\n", *res);
		res++;
	}
}

void	ft_display_position(t_point start, t_point end, t_point z, t_point n)
{
	ft_printf("\nPlayer Start   position in grid x->%d y->%d\n", start.x,
			start.y);
	ft_printf("Player Exit    position in grid x->%d y->%d\n\n", end.x, end.y);
	ft_printf("Portal 1 : {%c} position in grid x->%d y->%d\n", PORTAL_1_CHAR,
			z.x, z.y);
	ft_printf("Portal 2 : {%c} position in grid x->%d y->%d\n\n", PORTAL_2_CHAR,
			n.x, n.y);
}

void	ft_print_map_info(t_game *game)
{
	ft_printf("\n[All item in map Number]\n\n");
	ft_printf("Player : [%c] -> {%d}\n", PLAYER_CHAR,
			game->map.info.nbr_player);
	ft_printf("Wall   : [%c] -> {%d}\n", WALL_CHAR, game->map.info.nbr_wall);
	ft_printf("Pawn   : [%c] -> {%d}\n", PAWN_CHAR, game->map.info.nbr_pawn);
	ft_printf("Void   : [%c] -> {%d}\n", VOID_CHAR, game->map.info.nbr_void);
	ft_printf("Life   : [%c] -> {%d}\n", LOVE_CHAR, game->map.info.nbr_love);
	ft_printf("Lava   : [%c] -> {%d}\n", LAVA_CHAR, game->map.info.nbr_lava);
	ft_printf("Keke   : [%c] -> {%d}\n", KEKE_CHAR, game->map.info.nbr_keke);
	ft_printf("Key    : [%c] -> {%d}\n", KEY_CHAR, game->map.info.nbr_key);
	ft_printf("Exit   : [%c] -> {%d}\n", EXIT_CHAR, game->map.info.nbr_exit);
	ft_printf("Box    : [%c] -> {%d}\n", BOX_CHAR, game->map.info.nbr_box);
	ft_printf("Portal : [%c] -> {%d}\n", BOX_CHAR, game->map.info.nbr_portal_1
			+ game->map.info.nbr_portal_2);
	ft_printf("Grass :  [%c] -> {%d}\n\n", GRASS_CHAR,
			game->map.info.nbr_grass);
	//ohter print for border map perlin-noise
}

void	ft_print_initial_positions(t_game *game)
{
	ft_printf("\nPlayer Start  position in grid x->%d y->%d\n",
		game->map.start.x, game->map.start.y);
	ft_printf("Player Exit  position in grid x->%d y->%d\n\n",
		game->map.end.x, game->map.end.y);
}
