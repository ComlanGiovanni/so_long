/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format_linux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:35:15 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/31 00:58:52 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief Get the map height object
 * 
 * 			so we secure the open in read only of the file
 * 		then get the first line set height to 1 and inc
 * 			the height will the get_next_line is not NULL
 * 				free close and return the int
 * 
 * @param map_name 
 * @return int 
 */
int	get_map_height(char *map_name, t_game *game)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd <= FALSE)
		ft_print_error(FAIL_OPEN_ERROR, game);
	line = get_next_line(fd);
	height = TRUE;
	free(line);
	while (line)
	{
		height++;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	return (height);
}

/**
 * @brief 
 * 
 * 				this fct its call before doing anything else
 * 					the goal is symply exist when when 
 * 				have a empty ne line int the top 
 * 					and int the middle of the map
 * 
 * 	we open in readonly the file and if the open fail we print a error msg
 * 		else we get the first line of the .ber if is NULL or exist we quit then
 * 					get the len - 1 of the first line 
 * 			who is the width of the map and a checker for the next line
 * 	we are at the 1 height er get the next line et inc the curr_height
 * 	if the next line is empty or the first elm is \n and the curr_height is not
 * 			the height of the map get with get_map_height
 * 				we print a error msg , 
 * 			if we are at the last line and line is NULL we return
 *
 * 			this is a small problem that i will maybe fix,
 * 					we can have new line at the end of
 * 			the map, so i need to specify that if there is 
 * 		not new line at the last line is ok
 * 				else error, but is not a 
 * 			big deal because er have the map and not matter what if there
 * 		is anything else we have a error 
 * 			or if there is two map we also get an error because
 * 			there is a new line between the 
 * 				map because for us is only one map split by error
 * 
 * @param map_name 
 * @param height 
 */
void	check_ber_format(char *map_name, int height, t_game *game)
{
	int		fd;
	char	*line;
	int		curr_height;

	game->empty_line = 0;
	fd = open(map_name, O_RDONLY);
	if (fd <= FALSE)
		ft_print_error(FAIL_OPEN_ERROR, game);
	line = get_next_line(fd);
	if (line == NULL || line[FALSE] == '\n')
		game->empty_line = 1;
	curr_height = TRUE;
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		curr_height++;
		if ((line == NULL || line[FALSE] == '\n') && curr_height != height)
			game->empty_line = 1;
		if ((curr_height == height) && line == NULL)
			return ;
		free(line);
	}
	close(fd);
}
/**
 * @brief 
 * 
 * 		init to 0 height step
 * 				and init width to the
 * 		len of line send to the fct
 * 					the copy the line in map
 * 
 * @param game 
 * @param line 
 */

void	ft_init_map_info(t_game *game, char *line)
{
	game->height = FALSE;
	game->width = ft_strlen(line) - TRUE;
	game->map.map_str = ft_custom_strdup(line);
	free(line);
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
 * @param game 
 */
void	ft_check_rectangular(t_game *game)
{
	if (game->height * game->width != game->map.len)
		ft_print_error(FORM_ERROR, game);
}
