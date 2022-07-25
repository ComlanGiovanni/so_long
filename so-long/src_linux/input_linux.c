/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:01:54 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/25 19:11:50 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_linux/so_long_linux.h"

/**
 * @brief 
 * 
 * 		this fct will be trigger by mlx_hook in the main
 * 	mlx_hook is alway listening if there i KEY_PRESS -> 2 x_event
 * the send it to input manager as a int, look at the mlx_hook
 * 	prototype, the here i manager wasd up down left right arrow
 * 		those are set in the enumeration in .h  t_key_code
 * 
 * for each direction we call the good fct and seed the t_game pointer
 * 			alway returning 0 -> EXIT_SUCCESS
 * 
 * 
 * @param key_code 
 * @param game 
 * @return int 
 */
int	ft_input_manager(int key_code, t_game *game)
{
	if (key_code == ESC_KEY)
		ft_exit_game(game);
	if (key_code == W_KEY || key_code == UP_ARROW_KEY)
		ft_move_up(game);
	if (key_code == S_KEY || key_code == DOWN_ARROW_KEY)
		ft_move_down(game);
	if (key_code == A_KEY || key_code == LEFT_ARROW_KEY)
		ft_move_left(game);
	if (key_code == D_KEY || key_code == RIGHT_ARROW_KEY)
		ft_move_right(game);
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 *  the player is never at map[0] so we can idx++ right away in the first line
 * 	so if we found the p char we get out of the while to manage P behaviour
 * 					-        +
 * 			str "11111PC11CE11111"  len 16 	width 	4	height 4
 * 1111
 * 1CC1		-(width) is for up because in str up is before
 * 1PE1  so game->map[idx - game->width] is the char just in font of map[idx]
 * 1111  
 * 	
 * so if in front the player there is a wall or exit you can not move
 * else move the p and change the char at the previous index to void char 0
 * and the [idx - game->width] is now the player char
 * 
 * 		if the player is down front of a exit and he collect all the coin
 * 			game->key == game->storage we exit the game by calling
 * 					ft_win_game(game);
 * 
 *	so if we move inc step and print the game->step in console
 * 	then display again all the sprite line by line because we change position
 *
 * @param game 
 */
void	ft_move_up(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx++ < game->map_len)
	{
		if (game->map[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map[idx - game->width] == COIN_CHAR)
		game->storage++;
	if (game->map[idx - game->width] == EXIT_CHAR && game->key == game->storage)
		ft_win_game(game);
	else if (game->map[idx - game->width] != WALL_CHAR
		&& game->map[idx - game->width] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx - game->width] = PLAYER_CHAR;
		game->step++;
		ft_printf("Step : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

void	ft_move_down(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx++ < game->map_len)
	{
		if (game->map[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map[idx + game->width] == COIN_CHAR)
		game->storage++;
	if (game->map[idx + game->width] == EXIT_CHAR && game->key == game->storage)
		ft_win_game(game);
	else if (game->map[idx + game->width] != WALL_CHAR
		&& game->map[idx + game->width] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx + game->width] = PLAYER_CHAR;
		game->step++;
		ft_printf("Step : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

/**
 * @brief 
 * 
 *  the player is never at map[0] so we can idx++ right away in the first line
 * 	so if we found the p char we get out of the while to manage P behaviour
 * 					-        +
 * 			str "11111PC11CE11111"  len 16 	width 	4	height 4
 * 1111
 * 1CC1		-(1) is for left because in str left is moving downward so --
 * 1PE1  so game->map[idx - 1] is the char just in left of map[idx]
 * 1111  
 * 	
 * so if in the of left the player there is a wall or exit you can not move
 * else move the p and change the char at the previous index to void char 0
 * and the [idx - 1] is now the player char
 * 
 * 		if the player is in right of a exit and he collect all the coin
 * 			game->key == game->storage we exit the game by calling
 * 					ft_win_game(game);
 * 
 *	so if we move inc step and print the game->step in console
 * 	then display again all the sprite line by line because we change position
 *
 * @param game 
 */
void	ft_move_left(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx++ < game->map_len)
	{
		if (game->map[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map[idx - TRUE] == COIN_CHAR)
		game->storage++;
	if (game->map[idx - TRUE] == EXIT_CHAR && game->storage == game->key)
		ft_win_game(game);
	else if (game->map[idx - TRUE] != WALL_CHAR
		&& game->map[idx - TRUE] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx - TRUE] = PLAYER_CHAR;
		game->step++;
		ft_printf("Step : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

/**
 * @brief 
 * 
 *  the player is never at map[0] so we can idx++ right away in the first line
 * 	so if we found the p char we get out of the while to manage P behaviour
 * 					-        +
 * 			str "11111PC11CE11111"  len 16 	width 	4	height 4
 * 1111
 * 1CC1		+(1) is for right because in str left is moving forward so ++
 * 1PE1  so game->map[idx + 1] is the char just in right of map[idx]
 * 1111  
 * 	
 * so if in the right of the player there is a wall or exit you can not move
 * else move the p and change the char at the previous index to void char 0
 * and the [idx - 1] is now the player char
 * 
 * 		if the player is in left of a exit and he collect all the coin
 * 			game->key == game->storage we exit the game by calling
 * 					ft_win_game(game);
 * 
 *	so if we move inc step and print the game->step in console
 * 	then display again all the sprite line by line because we change position
 *
 * @param game 
 */
void	ft_move_right(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx++ < game->map_len)
	{
		if (game->map[idx] == PLAYER_CHAR)
			break ;
	}
	if (game->map[idx + TRUE] == COIN_CHAR)
		game->storage++;
	if (game->map[idx + TRUE] == EXIT_CHAR && game->storage == game->key)
		ft_win_game(game);
	else if (game->map[idx + TRUE] != WALL_CHAR
		&& game->map[idx + TRUE] != EXIT_CHAR)
	{
		game->map[idx] = VOID_CHAR;
		game->map[idx + TRUE] = PLAYER_CHAR;
		game->step++;
		ft_printf("Step : %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}
