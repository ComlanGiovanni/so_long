/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:48 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 00:09:43 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	ft_init_game(t_game *game, char *map_name)
{
	//int width;
	//int height;
	//void *mlx;
	//void *win;

	if ((game->mlx = mlx_init()) == NULL)
        ft_print_error(MLX_INIT_ERROR);
	ft_load_sprites(game);
	ft_init_player_info(game);
	ft_read_map(game, map_name);
	ft_check_map(game);
	//width = game->width * IMG_SIZE;
	//height = game->height * IMG_SIZE;
	//mlx = game->mlx;
	//win = game->win;
	if ((game->win = mlx_new_window(game->mlx, game->width * IMG_SIZE, game->height * IMG_SIZE, GAME_TITLE)) == NULL)
        ft_print_error(MLX_WINDOW_ERROR);
	//ft_direction_by_pos_after_launch(game);
	//game->direction = 'r';//lol changing the direction by they positon of the p int the map ?
	ft_put_sprites_by_line(game);
}

void	ft_check_valid_char(t_game *game)
{
	int idx;

	idx = 0;
	while (game->map.map_str[idx] != '\0')
	{
		if (game->map.map_str[idx] != WALL_CHAR &&  game->map.map_str[idx] != PLAYER_CHAR && game->map.map_str[idx] != KEY_CHAR  && game->map.map_str[idx] != EXIT_CHAR && game->map.map_str[idx] != VOID_CHAR && game->map.map_str[idx] != LAVA_CHAR && game->map.map_str[idx] != LOVE_CHAR)
			ft_print_error(BAD_CHAR_MAP_ERROR);
		idx++;
	}
}

	/*
	free mlx
	et si t'as des leaks quand tu fermes ta fenêtre/programme 
	utilise toutes les fonctions mlx_destroy et free le pointeur
	que t'as utilisé avec mlx_init
	*/

int	ft_exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * This fct is call when the player 
 * get all the key in the map
 * 
 * print in the console a win message
 * destroy the windows 
 * and exit with success
 * 
 * @param game 
 * @return int 
 */
int		ft_win_game(t_game *game)
{
	ft_printf(WIN_MSG "%d ", game->player.step);
	ft_printf("Storage : %d, ", game->player.storage);
	ft_printf("Life : %d\n", game->player.life);
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
}
