/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/25 21:04:38 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_linux/so_long_linux.h"

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
 * 				> norminette bonus inc lib main.c src
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
		mlx_key_hook(game->win, &ft_input_manager, game);
		//mlx_hook(game->win, KEY_PRESS, FALSE, &ft_input_manager, game);
		mlx_hook(game->win, CLOSE_ICON, FALSE, &ft_exit_game, game);
		mlx_loop(game->mlx);
	}
	return (EXIT_SUCCESS);
}

void	ft_free_all(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprite.player);
	mlx_destroy_image(game->mlx, game->sprite.ground);
	mlx_destroy_image(game->mlx, game->sprite.wall);
	mlx_destroy_image(game->mlx, game->sprite.key);
	mlx_destroy_image(game->mlx, game->sprite.exit);
	//free(game->mlx);
	free(game->win);
	free(game->map);
	free(game);
	//mlx_destroy_window(game->mlx, game->win);
	if (game->mlx != NULL)
		mlx_destroy_display(game->mlx);
}