/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/17 03:52:56 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
        ft_print_error(USAGE_MSG);
	else
	{
		if ((game = malloc(sizeof(t_game))) == NULL)
			ft_print_error(MALLOC_GAME_ERROR);
		ft_init_game(game, argv[1]);
		mlx_hook(game->win, KEY_PRESS, 0, &ft_input_manager, game);
		mlx_hook(game->win, CLOSE_ICON, 0, &ft_exit_game, game);
		mlx_loop(game->mlx);
	}
	return(EXIT_SUCCESS);
}
 /*
-g3 -fsanitize=address
int	ft_check_env(char **env)
{
	int	idx;

	if (!*env)
		return (EXIT_FAILURE);
	idx = 0;
	while (env[idx])
	{
		if (!ft_strncmp("DISPLAY", env[idx], ft_strlen(env[idx])))
			return (EXIT_SUCCESS);
		idx++;
	}
	return (EXIT_FAILURE);
}
*/

/*

prevent segfault when map is not found null or something

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

h for help menum ??

ENV check ??
	if (ft_check_env(env))
		return (0);
*/
