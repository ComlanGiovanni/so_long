/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:48 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/17 23:22:28 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_init_game(t_game *game, char *map_name)
{
	//int width;
	//int height;
	//void *mlx;
	//void *win;

	if ((game->mlx = mlx_init()) == NULL)
        ft_print_error(MLX_INIT_ERROR);
	game->sprite = ft_init_sprites(game->mlx);
	ft_read_map(game, map_name);
	ft_check_map(game);
	//width = game->width * 64;
	//height = game->height * 64;
	//mlx = game->mlx;
	//win = game->win;
	if ((game->win = mlx_new_window(game->mlx, game->width * 64, game->height * 64, GAME_TITLE)) == NULL)
        ft_print_error(MLX_WINDOW_ERROR);
	game->direction = 'r';//lol changing the direction by they positon of the p int the map ?
	ft_put_sprites_by_line(game);
}

void	ft_check_valid_char(t_game *game)
{
	int idx;

	idx = 0;
	while (game->map[idx] != '\0')
	{
		if (game->map[idx] != WALL_CHAR &&  game->map[idx] != PLAYER_CHAR && game->map[idx] != COIN_CHAR  && game->map[idx] != EXIT_CHAR && game->map[idx] != VOID_CHAR)
			ft_print_error(BAD_CHAR_MAP_ERROR);
		idx++;
	}
}

int	ft_exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	//free mlx
	exit(EXIT_SUCCESS);
}

int		ft_win_game(t_game *game)
{
	ft_printf(WIN_MSG "%d", game->step);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
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
	write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	exit(EXIT_FAILURE);
	// add perror ?
}

//random idea : save the file name in struc to display it in error msg