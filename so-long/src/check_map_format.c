/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:35:15 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/21 23:13:10 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
int	get_map_height(char *map_name)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd <= FALSE)
		ft_print_error(FAIL_OPEN_ERROR);
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

void	check_ber_format(char *map_name, int height)
{
	int		fd;
	int		width;
	char	*line;
	int		curr_height;

	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
		ft_print_error(FAIL_OPEN_ERROR);
	line = get_next_line(fd);
	if (line == NULL || line[0] == '\n')
		ft_print_error(EMPTY_LINE);
	width = ft_strlen(line) - 1;
	curr_height = 1;
	while (line)
	{
		line = get_next_line(fd);
		curr_height++;
		if ((line == NULL || line[0] == '\n') && curr_height != height)
			ft_print_error(EMPTY_LINE);
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
	game->step = FALSE;
	game->width = ft_strlen(line) - TRUE;
	game->map = ft_custom_strdup(line);
	free(line);
}
