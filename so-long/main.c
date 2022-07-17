/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/17 23:26:10 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

/*

int	ft_strend_cmp(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name += name_len - ext_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

*/
int	main(int argc, char *argv[], char **envp)
{
	t_game	*game;

	if (argc != 2)
        ft_print_error(USAGE_MSG);
	else
	{
		ft_check_env(envp);
		if ((game = malloc(sizeof(t_game))) == NULL)
			ft_print_error(MALLOC_GAME_ERROR);
		if (!ft_check_extension(argv[1], BER_EXTENSION))
			ft_print_error(EXTENSION_ERROR);
		ft_init_game(game, argv[1]);
		mlx_hook(game->win, KEY_PRESS, 0, &ft_input_manager, game);
		mlx_hook(game->win, CLOSE_ICON, 0, &ft_exit_game, game);
		mlx_loop(game->mlx);
	}
	return(EXIT_SUCCESS);
}
