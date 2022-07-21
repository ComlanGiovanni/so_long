/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:35:15 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/21 15:12:15 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_map_height(char *map_name)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
		ft_print_error(FAIL_OPEN_ERROR);
	line = get_next_line(fd);
	height = 1;
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

void	ft_init_map_info(t_game *game, char *line)
{
	int		width;

	width = ft_strlen(line) - 1;
	game->height = 0;
	game->step = 0;
	game->width = width;
	game->map = ft_custom_strdup(line);
	free(line);
}
