/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/13 14:06:20 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		perror(ERROR_MSG);
        ft_print_error(USAGE_MSG);
	}
	else
	{
		//secure malloc
		game = malloc(sizeof(t_game));
		ft_init_game(game, argv[1]);
		mlx_hook(game->win, KEY_PRESS, 0, &ft_input_manager, game);
		mlx_hook(game->win, KEY_EXIT, 0, &ft_input_manager, game);
		mlx_loop(game->mlx);
		return (EXIT_SUCCESS);
	}
}
 /*
int	ft_check_env(char **env)
{
	int	idx;

	if (!*env)
	{
		//env unreachable.
		return (EXIT_FAILURE);
	}
	idx = 0;
	while (env[idx])
	{
		if (!ft_strncmp("DISPLAY", env[idx], ft_strlen(env[idx])))
			return (EXIT_SUCCESS);
		idx++;
	}
	//DISPLAY unreachable.
	return (EXIT_FAILURE);
}
*/

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

ENV check ??
	if (ft_check_env(env))
		return (0);
*/