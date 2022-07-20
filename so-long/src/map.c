/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:58:13 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 03:36:18 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_read_map(t_game *game, char *map_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
		ft_print_error(FAIL_OPEN_ERROR);
	line = get_next_line(fd);
	width = ft_strlen(line) - 1;
	game->height = 0;
	game->step = 0;
	game->width = width;
	game->map = ft_custom_strdup(line);
	free(line);
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

void	ft_check_map(t_game *game)
{
	ft_check_valid_char(game);
	ft_check_rectangular(game);
	ft_check_sealed(game);
	ft_check_playability(game);
}

void	ft_check_sealed(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx < game->map_len)
	{
		if (idx > (game->map_len - game->width))
		{
			if (game->map[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR);
		}
		else if (idx < game->width)
		{
			if (game->map[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR);
		}
		else if (idx % game->width == 0 || idx % game->width == game->width - 1)
		{
			if (game->map[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR);
		}
		idx++;
	}
}

void	ft_check_rectangular(t_game *game)
{
	if (game->height == game->width)
		ft_print_error(FORM_ERROR);
}

void	ft_check_playability(t_game *game)
{
	int	idx;

	idx = 0;
	game->player = 0;
	game->key = 0;
	game->exit = 0;
	game->storage = 0;
	while (idx++ < game->map_len)
	{		
		if (game->map[idx] == COIN_CHAR)
			game->key++;
		else if (game->map[idx] == PLAYER_CHAR)
			game->player++;
		else if (game->map[idx] == EXIT_CHAR)
			game->exit++;
	}
	if (game->key == 0)
		ft_print_error(COIN_ERROR);
	if (game->player != 1)
		ft_print_error(PLAYER_ERROR);
	if (game->exit == 0)
		ft_print_error(EXIT_ERROR);
}
