/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus_linux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:58:13 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/31 00:58:22 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief 
 * 			map str is not the game->map struct
 * 
 * 	first we need the height of the map to check if the map is well formatted
 * 		before reading it, then re-open the file to get every line in the
 * 			line variable.	 (secure the open with a print message)
 * 		just before joining every line we initialized all the map info
 * 			step height width to 0 and map to the first line of the map with a 
 * 						custom strdup of first line.
 * 	when we are able to open the map on READONLY we can get the next line of the
 * 		map aka the first line, we can now join the next line until the end
 * 			to the game->map(str), then free and close the fd
 * 							the get the full len of it
 * 
 * @param game 
 * @param map_name 
 */
void	ft_read_map(t_game *game, char *map_name)
{
	int		fd;
	int		height;
	char	*line;

	height = get_map_height(map_name, game);
	check_ber_format(map_name, height, game);
	if (game->empty_line == 1)
		ft_print_error(EMPTY_LINE, game);
	fd = open(map_name, O_RDONLY);
	if (fd <= FALSE)
		ft_print_error(FAIL_OPEN_ERROR, game);
	line = get_next_line(fd);
	ft_init_map_info(game, line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
			game->map.map_str = ft_custom_strjoin(game->map.map_str, line);
	}
	close(fd);
	game->map.len = ft_strlen(game->map.map_str);
}

/**
 * @brief 
 * 
 * 
 *  	here is the fct who call all the check we need to the game
 * 
 * 	valid char 0 1 P C E			 ----------- void wall player coin exit
 * 	 NOT	rectangular form		|			|   FOR BONUS
 * 	no breathing room around the map ----------
 * 				playable P = 1 C/E >=1
 * 	in bonus we can have squared map
 * 				all the fct need game->map so we send a pointer to
 * 		t_game *game we could just send the game->map but who care ? i am lazy
 * 
 * 		we init some map info 
 *	 		nbr of key 
 *   	exit player storage
 *  	lava love wall void etc
 * 	 the wall is 1 because
 * we start already at the firs wall
 * 
 * the we print the map in console not in line but in
 * the file format with they new line
 * 
 * @param game 
 */
void	ft_check_map(t_game *game)
{
	ft_map_fit_screen(game);
	ft_check_valid_char(game);
	ft_check_rectangular(game);
	ft_check_sealed(game);
	game->map.nbr_player = FALSE;
	game->map.nbr_key = FALSE;
	game->map.nbr_exit = FALSE;
	game->map.nbr_lava = FALSE;
	game->map.nbr_love = FALSE;
	game->map.nbr_wall = TRUE;
	game->map.nbr_void = FALSE;
	ft_get_info_map(game);
	ft_check_playability(game);
	ft_print_map_better_format(game);
}

/**
 * @brief 
 * 					11111CC11PE11111 
 * 
 * 1111	(game->map_len - game->width) 11111CC11PE * [11111] (idx near end)
 * 1CC1 (idx < game->width) [1111] * 1CC11PE11111 (idx less)
 * 1PE1	(idx % game->width == 0 || idx % game->width == game->width - 1)
 * 1111			(1111) [1CC1] [1PE1] (1111)
 * 
 * 	     *      *
 * 		[1CC1] [1PE1]	the first idx modulo width is alway 0 
 * 						because we alway add the width because
 * 						its a perfect form square rectangle
 * 			*	   *
 * 		[1CC1] [1PE1]	this last idx of a line modulo of width
 * 						is alway equal to width - 1 because
 * 						we are almost near to the next whose
 * 						modulo is 0 cf above
 * 
 * 		first if it's for the last width bottom of map
 * 		second if it's for the first width top of the map
 * 		third if is for 
 * 
 * 
 * @param game 
 */
void	ft_check_sealed(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx < game->map.len)
	{
		if (idx > (game->map.len - game->width))
		{
			if (game->map.map_str[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR, game);
		}
		else if (idx < game->width)
		{
			if (game->map.map_str[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR, game);
		}
		else if (idx % game->width == FALSE
			|| idx % game->width == game->width - TRUE)
		{
			if (game->map.map_str[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR, game);
		}
		idx++;
	}
}

/**
 * @brief 
 * 		we loop in the map until we reach the end (map.len)
 * 			we get all the map info that we read previously 
 * 		if we found any char 0 1 P E L S we inc the variable
 * 
 * @param game 
 */
void	ft_get_info_map(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx++ < game->map.len)
	{		
		if (game->map.map_str[idx] == KEY_CHAR)
			game->map.nbr_key++;
		else if (game->map.map_str[idx] == PLAYER_CHAR)
			game->map.nbr_player++;
		else if (game->map.map_str[idx] == EXIT_CHAR)
			game->map.nbr_exit++;
		else if (game->map.map_str[idx] == LAVA_CHAR)
			game->map.nbr_lava++;
		else if (game->map.map_str[idx] == LOVE_CHAR)
			game->map.nbr_love++;
		else if (game->map.map_str[idx] == WALL_CHAR)
			game->map.nbr_wall++;
		else
			game->map.nbr_void++;
	}
}

/**
 * @brief 
 * 
 * then check if there is at least one key one exit and
 * only one player otherwise we print the proper error msg
 * 
 * @param game 
 */
void	ft_check_playability(t_game *game)
{
	if (game->map.nbr_key == FALSE)
		ft_print_error(COIN_ERROR, game);
	if (game->map.nbr_player != TRUE)
		ft_print_error(PLAYER_ERROR, game);
	if (game->map.nbr_exit == FALSE)
		ft_print_error(EXIT_ERROR, game);
}
