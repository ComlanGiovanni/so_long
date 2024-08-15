/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_linux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:00:19 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 15:45:33 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_mandatory.h"

/**
 * @brief
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

	height = ft_get_map_height(map_name, game);
	ft_check_ber_format(map_name, height, game);
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
			game->map = ft_custom_strjoin(game->map, line);
	}
	close(fd);
	game->map_len = ft_strlen(game->map);
}

/**
 * @brief
 *
 * 			here is the fct who call all the check we need to the game
 *
 * 	valid char 0 1 P C E			 ----------- void wall player coin exit
 * 			rectangular form		|			|
 * 	no breathing room around the map ----------
 * 				playable P = 1 C/E >=1
 *
 * 				all the fct need game->map so we send a pointer to
 * 		t_game *game we could just send the game->map but who care ? i am lazy
 *
 * @param game
 */
void	ft_check_map(t_game *game)
{
	ft_check_sealed(game);
	ft_map_fit_screen(game);
	ft_check_valid_char(game);
	ft_check_rectangular(game);
	ft_check_playability(game);
	ft_get_number_collectible(game);
	ft_check_map_finishable(game);
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
	while (idx < game->map_len)
	{
		if (idx > (game->map_len - game->width))
		{
			if (game->map[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR, game);
		}
		else if (idx < game->width)
		{
			if (game->map[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR, game);
		}
		else if (idx % game->width == FALSE
			|| (idx % game->width) == game->width - TRUE)
		{
			if (game->map[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR, game);
		}
		idx++;
	}
}

/**
 * @brief
 *
 * 			In Euclidean plane geometry,
 * 	 a rectangle is a quadrilateral with four right angles.
 * 	A rectangle with four sides of equal length is a square.
 *
 * Les côtés d'un rectangle étant deux à deux de même longueur
 * 						a et b
 *
 * 		rec : a != b 		&& 		carr  a = b
 *
 * 			 Mine de rien dans la rigolade
 * 		j'avais oublier qu'un carree est un rectangle
 *
 * 	du coup si height == width is a reactangle
 *
 * bon bah du les square cest ok
 *
 * @param game
 */
void	ft_check_rectangular(t_game *game)
{
	if (game->height * game->width != game->map_len)
		ft_print_error(FORM_ERROR, game);
}

/**
 * @brief
 *
 * 	we init some map info nbr of key exit player storage
 * 	we loop in the map until we reach the end (map_len)
 *
 * 	if we found coin player exit char we ++ the map info
 *
 * then check if there is at least one key one exit and
 * only one player otherwise we print the proper error msg
 *
 * @param game
 */
void	ft_check_playability(t_game *game)
{
	int	idx;

	idx = FALSE;
	game->player = idx;
	game->key = FALSE;
	game->exit = idx;
	game->storage = FALSE;
	while (idx++ < game->map_len)
	{
		if (game->map[idx] == COIN_CHAR)
			game->key++;
		else if (game->map[idx] == PLAYER_CHAR)
			game->player++;
		else if (game->map[idx] == EXIT_CHAR)
			game->exit++;
	}
	if (game->key == FALSE)
		ft_print_error(COIN_ERROR, game);
	if (game->player != TRUE)
		ft_print_error(PLAYER_ERROR, game);
	if (game->exit != TRUE)
		ft_print_error(EXIT_ERROR, game);
}
