/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 02:58:56 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/06 01:37:19 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_mandatory.h"

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
 * 				> norminette bonus_* inc_* src_* lib main_*
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
	{
		write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
		write(STDERR_FILENO, USAGE_MSG, ft_strlen(USAGE_MSG));
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_check_env(envp);
		game = ft_calloc(sizeof(t_game), sizeof(t_game));
		if (game == NULL)
			ft_print_error(MALLOC_GAME_ERROR, game);
		if (!ft_check_extension(argv[1], BER_EXTENSION))
			ft_print_error(EXTENSION_ERROR, game);
		ft_init_game(game, argv[1]);
		mlx_key_hook(game->win, &ft_input_manager, game);
		mlx_hook(game->win, CLOSE_ICON, FALSE, &ft_exit_game, game);
		mlx_loop(game->mlx);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief
 *
 * 	Free of last minutes, need to read the project again for better free fct
 * 	we need to free all the image load in sprites before so we check and free
 * 	then the map in str (alway check if exist)
 * 	then we destroy the game (mlx, win)
 * 	then the display (mlx)
 * 	and at the end we need to free the mlx and the game we malloc in the main
 *
 *  make garbage collector next time
 *
 * @param game
 */
void	ft_free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->sprite.player)
		mlx_destroy_image(game->mlx, game->sprite.player);
	if (game->sprite.ground)
		mlx_destroy_image(game->mlx, game->sprite.ground);
	if (game->sprite.wall)
		mlx_destroy_image(game->mlx, game->sprite.wall);
	if (game->sprite.key)
		mlx_destroy_image(game->mlx, game->sprite.key);
	if (game->sprite.exit)
		mlx_destroy_image(game->mlx, game->sprite.exit);
	if (game->map)
		free(game->map);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game)
		free(game);
}

void	ft_map_fit_screen(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	width = 0;
	mlx_get_screen_size(game->mlx, &width, &height);
	if (game->width * 64 > width || game->height * 64 > height)
		ft_print_error(MAP_TOO_BIG, game);
}
// /**
//  * @brief
//  *
//  * If the error value is >= 1
//  * 	print Error in standard error
//  * else 0 -1 etc
//  * 	just exit the code
//  *
//  * EXIT_SUCCESS = 0
//  * EXIT_FAILURE = 1;
//  *
//  * STDIN_FILENO    Standard input value, stdin. Its value is 0.
//  * STDOUT_FILENO   Standard output value, stdout. Its value is 1.
//  * STDERR_FILENO   Standard error value, stderr. Its value is 2.
//  *
//  * @param error_code
//  * @return int
//  */
// void	ft_print_error(char *error_msg)
// {
// 	write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
// 	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
// 	exit(EXIT_FAILURE);
// }
