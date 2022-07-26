/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/26 15:59:17 by gcomlan          ###   ########.fr       */
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
		/*
		mlx_loop_hook(game.mlx, sl_loop_hook, &game);
		int	sl_key_press_hook(unsigned long keysym, t_game *game)
		int	sl_key_press_hook(unsigned long keysym, t_game *game)

			mlx_hook(game.win, 2, 1 << 0, sl_key_press_hook, &game);
	mlx_hook(game.win, 3, 1 << 1, sl_key_release_hook, &game);

			if (keysym == UP_KEYSYM)
		game->lvl.pressing_up = true;
	else if (keysym == LEFT_KEYSYM)
		game->lvl.pressing_left = true;
	else if (keysym == DOWN_KEYSYM)
		game->lvl.pressing_down = true;
	else if (keysym == RIGHT_KEYSYM)
		game->lvl.pressing_right = true;
		
		*/
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
	free(game->map);
	//free(game->win);
	//free(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

/*

	all img 
		mlx_destroy_image(g->mlx, g->images[i++].image);
	mlx_destroy_image(game->mlx, game->canvas.image);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);

*/