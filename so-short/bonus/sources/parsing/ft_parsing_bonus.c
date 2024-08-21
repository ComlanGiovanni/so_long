/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:30:44 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/21 13:57:09 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

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

// void	ft_handle_line_error(char *line, int fd,
// 	t_game *game, int curr_height, int height)
// {
// 	if ((line == NULL || line[0] == '\n') && curr_height != height)
// 		game->empty_line = 0x1;
// 	free(line);
// 	if (curr_height == height)
// 	{
// 		close(fd);
// 		return ;
// 	}
// }

// void	ft_check_ber_format(char *map_name, int height, t_game *game)
// {
// 	int		fd;
// 	char	*line;
// 	int		curr_height;

// 	game->empty_line = 0x0;
// 	fd = open(map_name, O_RDONLY);
// 	if (fd <= FALSE)
// 		ft_print_error(FAIL_OPEN_ERROR, game);
// 	line = get_next_line(fd);
// 	if (line == NULL || line[FALSE] == '\n')
// 		game->empty_line = 0x1;
// 	curr_height = TRUE;
// 	free(line);
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		curr_height++;
// 		ft_handle_line_error(line, fd, game, curr_height, height);
// 	}
// 	close(fd);
// }

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

void	ft_check_ber_format(char *map_name, int height, t_game *game)
{
	int					fd;
	char				*line;
	int					curr_height;
	t_line_error_data	data;

	game->empty_line = 0x0;
	fd = open(map_name, O_RDONLY);
	if (fd <= FALSE)
		ft_print_error(FAIL_OPEN_ERROR, game);
	line = get_next_line(fd);
	if (line == NULL || line[FALSE] == '\n')
		game->empty_line = 0x1;
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
