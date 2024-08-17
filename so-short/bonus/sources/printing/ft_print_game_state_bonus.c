/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_game_state_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:29:35 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/17 04:28:22 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_ascii_exit(void)
{
	ft_printf("\n\n");
	ft_printf("\033[0;31m        \\           EXIT            /\n");
	ft_printf("\033[0;31m         \\                         /\n");
	ft_printf("\033[0;31m          \\    Road to cube 3D   /\n");
	ft_printf("\033[0;31m           ]    So_long was fun   [    ,'|\n");
	ft_printf("\033[0;31m           ]                     [   /  |\n");
	ft_printf("\033[0;31m           ]___               ___[ ,'   |\n");
	ft_printf("\033[0;31m           ]  ]\\             /[  [ |:   |\n");
	ft_printf("\033[0;31m           ]  ] \\           / [  [ |:   |\n");
	ft_printf("\033[0;31m           ]  ]  ]         [  [  [ |:   |\n");
	ft_printf("\033[0;31m           ]  ]  ]__     __[  [  [ |:   |\n");
	ft_printf("\033[0;31m           ]  ]  ] ]\\ _ /[ [  [  [ |:   |\n");
	ft_printf("\033[0;31m           ]  ]  ] ] (#) [ [  [  [ :===='\n");
	ft_printf("\033[0;31m           ]  ]  ]_].nHn.[_[  [  [\n");
	ft_printf("\033[0;31m           ]  ]  ]  HHHHH. [  [  [\n");
	ft_printf("\033[0;31m           ]  ] /   `HH(\"N  \\ [  [\n");
	ft_printf("\033[0;31m           ]__]/     HHH  \"  \\[__[\n");
	ft_printf("\033[0;31m           ]         NNN         [\n");
	ft_printf("\033[0;31m           ]         N/\"         [\n");
	ft_printf("\033[0;31m           ]         N H         [\n");
	ft_printf("\033[0;31m          /          N            \\\n");
	ft_printf("\033[0;31m         /           q,            \\\n");
	ft_printf("\033[0;31m        /                           \\\n");
	ft_printf("\033[0m\n");
}

void	ft_ascii_win(t_game *game)
{
	ft_printf("\n\033[0;32m\n");
	ft_printf("WE HAVE A WINNER !!!     -.\n");
	ft_printf("                         )`\n");
	ft_printf("Steps : %d            ]-I-I-I-[\n", game->player.step);
	ft_printf("Storage : %d          \\_,_,_,_/\n", game->player.storage);
	ft_printf("Life : %d             |\\     |\n", game->player.life);
	ft_printf("                       \\`-._ |\n");
	ft_printf("                       |`._ `.\n");
	ft_printf("                       |  _`. \\\n");
	ft_printf("                       | / \\ \\/\n");
	ft_printf("         |>           /' |_| |\n");
	ft_printf("         |            | \\'-' |       |>\n");
	ft_printf("        / \\           \\  `-. |       |\n");
	ft_printf("       /___\\           `.   `-.     / \\\n");
	ft_printf("        |u|            | `-.   \\   /___\\\n");
	ft_printf("        | |   __       |    `. |    |u|\n");
	ft_printf("        | '  /-.`.     |-   u| /  _-' |\n");
	ft_printf("        ' __    \\ ` _  |  u  |/ _-   .'\n");
	ft_printf("        ,´  `-.  `_(o)/|u    |_-     |\n");
	ft_printf("   _   / ,'':. `-(o)(o)| .--.|       '\n");
	ft_printf("   ``-´;     ':. / vv  | |__||\n");
	ft_printf("    `\"         '( V  V |   -_\n");
	ft_printf("                 `.^^  | |   -_\n");
	ft_printf("      -  - - -- -------'       -_  -- -  -\033[0m\n\n");
}

void	ft_ascii_loose(t_game *game)
{
	ft_printf("\n\n\033[0;31m⢸⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⡷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf("⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠢⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf("⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠈⠑⢦⡀⠀⠀⠀⠀⠀\n");
	ft_printf("⢸⠀⠀⠀⠀⢀⠖⠒⠒⠒⢤⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠙⢦⡀⠀⠀⠀⠀\n");
	ft_printf("⢸⠀⠀⣀⢤⣼⣀⡠⠤⠤⠼⠤⡄⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠙⢄⠀⠀⠀⠀\n");
	ft_printf("⢸⠀⠀⠑⡤⠤⡒⠒⠒⡊⠙⡏⠀⢀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠢⡄⠀\n");
	ft_printf("⢸⠀⠀⠀⠇⠀⣀⣀⣀⣀⢀⠧⠟⠁⠀⡇⠀ARE YOU LOSSSSSSSSSIIIIIINNNNG SON?⠀\n");
	ft_printf("⢸⠀⠀⠀⠸⣀⠀⠀⠈⢉⠟⠓⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n");
	ft_printf("⢸⠀⠀⠀⠀⠈⢱⡖⠋⠁⠀⠀⠀⠀⠀⠀⡇Steps : %d   ⢸\n", game->player.step);
	ft_printf("⢸⠀⠀⠀⠀⣠⢺⠧⢄⣀⠀⠀⣀⣀⠀⠀⡇Storage : %d ⢸\n", game->player.storage);
	ft_printf("⢸⠀⠀⠀⣠⠃⢸⠀⠀⠈⠉⡽⠿⠯⡆⠀⡇Life : %d    ⢸\n", game->player.life);
	ft_printf("⢸⠀⠀⣰⠁⠀⢸⠀⠀⠀⠀⠉⠉⠉⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n");
	ft_printf("⢸⠀⠀⠣⠀⠀⢸⢄⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n");
	ft_printf("⢸⠀⠀⠀⠀⠀⢸⠀⢇⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n");
	ft_printf("⢸⠀⠀⠀⠀⠀⡌⠀⠈⡆⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n");
	ft_printf("⢸⠀⠀⠀⠀⢠⠃⠀⠀⡇⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n");
	ft_printf("⢸⠀⠀⠀⠀⢸⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠷\n\n\033[0m");
}
