/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:30:44 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 17:25:45 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

/**
 * @brief
 * 			map str is not the game->map struct
 *
 * 	first we need the height of the map to check if the map is well formatted
 * 		before reading it, then re-open the file to get every line in the
 * 			line variable.		(secure the open with a print message)
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
			game->map.map_str = ft_custom_strjoin(game->map.map_str, line);
	}
	close(fd);
	game->map.len = ft_strlen(game->map.map_str);
	game->map.size.x = game->width;
	game->map.size.y = game->height;
}

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
int	ft_get_map_height(char *map_name, t_game *game)
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

void ft_handle_line_error(char *line, int fd, t_game *game, int curr_height, int height) {
    if ((line == NULL || line[0] == '\n') && curr_height != height) {
        game->empty_line = 1;
    }
    free(line);
    if (curr_height == height) {
        close(fd);
		return;
    }
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
 * 			the height of the map get with ft_get_map_height
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
void	ft_check_ber_format(char *map_name, int height, t_game *game)
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
		ft_handle_line_error(line, fd, game, curr_height, height);
		// if (line == NULL)
		// 	break; // Exit loop if line is set to NULL
	}
	close(fd);
}
