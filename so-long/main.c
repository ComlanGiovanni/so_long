/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/12 21:00:19 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;
	/*
	./so_long [pass to map][map name].ber
	*/
	if (argc != 2)
        ft_print_error();
	else if (argc > 2)
		ft_print_error(usage);
	else
	{
		game = malloc(sizeof(t_game));
		ft_init_game(game, argv[1]);
		mlx_hook(game->win, KEY_PRESS, 0, &ft_input_manager, game);
		mlx_hook(game->win, KEY_EXIT, 0, &ft_input_manager, game);
		mlx_loop(game->mlx);
		return (EXIT_SUCCESS);
	}
}

/*
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
*/