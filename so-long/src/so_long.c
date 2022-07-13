/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:48 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/13 18:16:45 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_init_game(t_game *game, char *map_name)
{
	int width;
	int height;

	game->mlx = mlx_init();
	game->sprite = ft_init_sprites(game->mlx);
	width = game->width;
	height = game->height;
	ft_read_map(game, map_name);
	ft_check_map(game);
	game->win = mlx_new_window(game->mlx, width * 64, height * 64, GAME_TITLE);
	ft_put_sprites_by_line(game);
}

int	ft_exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	//free mlx
	exit(EXIT_SUCCESS);
}

int		ft_win_game(t_game *game)
{
	ft_printf("You win like a chad !%s %d%s\n", "steps : ", game->step, ". Thanks for playing !");
	exit(0);
}

/**
 * @brief 
 * 
 * If the error value is >= 1
 * 	print Error in standard error
 * else 0 -1 etc
 * 	just exit the code
 * 
 * EXIT_SUCCESS = 0
 * EXIT_FAILURE = 1;
 *
 * STDIN_FILENO    Standard input value, stdin. Its value is 0.
 * STDOUT_FILENO   Standard output value, stdout. Its value is 1.
 * STDERR_FILENO   Standard error value, stderr. Its value is 2.
 * 
 * @param error_code 
 * @return int 
 */
void	ft_print_error(char *error_msg)
{
	//write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	exit(EXIT_FAILURE);
	// add perror ?
}

//random idea : save the file name in struc to display it in error msg