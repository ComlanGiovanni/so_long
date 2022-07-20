/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 03:27:42 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

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
		mlx_hook(game->win, KEY_PRESS, 0, &ft_input_manager, game);
		mlx_hook(game->win, CLOSE_ICON, 0, &ft_exit_game, game);
		mlx_loop(game->mlx);
	}
	return (EXIT_SUCCESS);
}
