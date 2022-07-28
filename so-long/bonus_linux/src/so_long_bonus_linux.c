/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_linux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:48 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/28 16:09:21 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief 
 * 
 * 		we check the mlx_init() that will be in game->mlx
 * 	we also check the mlx_new_windows that will be in game->win
 * 
 * 			we need the width height and a title for it
 * 		those are set inside ft_read_map/ft_init_map_info
 *	and get inc will reading the map file, then those nbr would be
 *		multiply by IMG_SIZE -> (64) who is the size of every
 * 				sprite load int ft_init_sprites()
 * 	  		the we print every sprite line by line
 * 			we make sure that the map is well formatted
 * 				before printing all the sprite
 * 
 * @param game 
 * @param map_name 
 */
void	ft_init_game(t_game *game, char *map_name)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_print_error(MLX_INIT_ERROR, game);
	ft_load_sprites(game);
	ft_init_player_info(game);
	ft_read_map(game, map_name);
	ft_check_map(game);
	game->win = mlx_new_window(game->mlx, game->width * IMG_SIZE,
			game->height * IMG_SIZE, GAME_TITLE);
	if (game->win == NULL)
		ft_print_error(MLX_WINDOW_ERROR, game);
	ft_put_sprites_by_line(game);
}

/**
 * @brief 
 * 
 * 		we check if every char until the end is
 *  		equal to typedef enum e_map_char
 * 		if not quit and print the error msg for it
 * 
 * @param game 
 */
void	ft_check_valid_char(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (game->map.map_str[idx] != '\0')
	{
		if (game->map.map_str[idx] != WALL_CHAR
			&& game->map.map_str[idx] != PLAYER_CHAR
			&& game->map.map_str[idx] != KEY_CHAR
			&& game->map.map_str[idx] != EXIT_CHAR
			&& game->map.map_str[idx] != VOID_CHAR
			&& game->map.map_str[idx] != LAVA_CHAR
			&& game->map.map_str[idx] != LOVE_CHAR)
			ft_print_error(BAD_CHAR_MAP_ERROR, game);
		idx++;
	}
}

/**
 * @brief 
 * 
 * 			Just exit the window by destroying
 * 		mlx and win with mlx_destroy_window and return
 * 			0 -> EXIT_SUCCESS hummm we exit the game
 * 		when we press esc so the exit for me is SUCCESS
 * 			think its good, this fct is call when
 * 			 the mlx_hook in the game is trigger
 * 				by the x mask 17 -> CLOSE_ICON
 * 
 * 		for ft_exit_game ft_win_game we should free the game malloc
 * 			if need send t_game * game to ft_print_error
 * 				for good free for linux version
 * 
 * 			mlx_destroy_window(game->mlx, game->win);
 * 
 * @param game 
 * @return int 
 */
int	ft_exit_game(t_game *game)
{
	ft_free_all(game);
	exit(EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * 		This fct is called only when the player win the game
 * 			so we print the number of step a the end
 * 					with a define win msg
 * 
 * 		we also print the storage and the life of the player
 * 	
 *  			Just exit the window by destroying
 * 		mlx and win with mlx_destroy_window and return
 * 			0 -> EXIT_SUCCESS hummm we exit the game
 * 		when we player win so for me is SUCCESS var
 * 
 * 
 * 		for ft_exit_game ft_win_game we should free the game malloc
 * 			if need send t_game * game to ft_print_error
 * 				for good free for linux version
 * 
 * 		mlx_destroy_window(game->mlx, game->win);
 * 
 * @param game 
 * @return int 
 */
int	ft_win_game(t_game *game)
{
	ft_printf(WIN_MSG "%d ", game->player.step);
	ft_printf("Storage : %d, ", game->player.storage);
	ft_printf("Life : %d\n", game->player.life);
	ft_free_all(game);
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
void	ft_print_error(char *error_msg, t_game *game)
{
	ft_free_all(game);
	write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	exit(EXIT_FAILURE);
}
