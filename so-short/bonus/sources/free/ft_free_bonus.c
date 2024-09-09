/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:17:50 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/09 17:09:46 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

/**
 * @brief
 *
 * 			Just exit the window by destroying
 * 		mlx and win with mlx_destroy_window and return
 * 			0 -> EXIT_SUCCESS hummm we exit the game
 * 		when we press esc so the exit for me is SUCCESS
 * 			think its good, this fct is call when
 * 				the mlx_hook in the game is trigger
 * 				by the x mask 17 -> CLOSE_ICON
 *
 * 		for ft_exit_game ft_win_game we should free the game malloc
 * 			if need send t_game * game to ft_print_error
 * 				for good free for linux version
 *
 * 			//system("pkill vlc");
 * 			mlx_destroy_window(game->mlx, game->win);
 * return (0x0);
 *
 * @param game
 * @return int
 */
int	ft_exit_game(t_game *game)
{
	system("pkill paplay > /dev/null 2>&1");
	ft_ascii_exit();
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
 *		//system("pkill vlc");
 * @param game
 * @return int
 */
void	ft_win_game(t_game *game)
{
	game->player.step++;
	system("pkill paplay > /dev/null 2>&1");
	ft_ascii_win(game);
}

/**
 * @brief
 *
 * 			This fct is call when the game->player.life is 0
 * 		this variable is dec only when we it a lava aka L see
 * 	ft_display_life_on_windows  all moving fct in -> input_bonus.c
 * 		he is set in ft_init_player_info in the main at 1
 *
 * 		we print storage at the death with the life 0 pretty dumb be meh is ok
 *
 * 		the we destroy the windows, we should probaly
 * 			free the game, check with valgrind
 * 					on the linux version
 *
 * 		return 1 because we fail hummmm legit ? or its 0
 *
 * 			mlx_destroy_window(game->mlx, game->win);
 *
 * @param game
 * @return int
 */
void	ft_lose_game(t_game *game)
{
	system("pkill paplay > /dev/null 2>&1");
	ft_ascii_loose(game);
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
 *
 * @param game
 */
void	ft_free_all(t_game *game)
{
	if (game)
	{
		if (game->mlx)
			mlx_loop_end(game->mlx);
		ft_free_pawns_array(game);
		ft_free_sprites_list(&game->node, game->mlx);
		if (game->map.map_str)
			free(game->map.map_str);
		if (game->map.grid)
			ft_clean_grid_map(game->map.grid, game->height);
		if (game->map.original)
			ft_clean_grid_map(game->map.original, game->height);
		ft_free_mlx(game);
	}
}

void	ft_free_mlx(t_game *game)
{
	if (game->window.img)
		mlx_destroy_image(game->mlx, game->window.img);
	if (game->window.img_data)
		free(game->window.img);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game)
		free(game);
}
