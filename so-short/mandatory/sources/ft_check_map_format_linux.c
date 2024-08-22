/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_format_linux.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:00:42 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 15:27:58 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_mandatory.h"

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

static void	ft_handle_line_error(char *line, t_line_error_data *data)
{
	if ((line == NULL || line[0x0] == '\n')
		&& data->curr_height != data->height)
		data->game->empty_line = 0x1;
	free(line);
	if (data->curr_height == data->height)
	{
		close(data->fd);
		return ;
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
	int					fd;
	char				*line;
	int					curr_height;
	t_line_error_data	data;

	game->empty_line = 0;
	fd = open(map_name, O_RDONLY);
	if (fd <= FALSE)
		ft_print_error(FAIL_OPEN_ERROR, game);
	line = get_next_line(fd);
	if (line == NULL || line[FALSE] == '\n')
		game->empty_line = 1;
	curr_height = TRUE;
	free(line);
	data.curr_height = curr_height;
	data.height = height;
	data.fd = fd;
	data.game = game;
	while (line)
	{
		line = get_next_line(fd);
		data.curr_height++;
		ft_handle_line_error(line, &data);
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
	game->step = FALSE;
	game->width = ft_strlen(line) - TRUE;
	game->map = ft_custom_strdup(line);
	free(line);
}
