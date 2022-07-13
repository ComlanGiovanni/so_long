/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:58:13 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/13 18:27:09 by gcomlan          ###   ########.fr       */
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
	{
		perror(ERROR_MSG);
        //ft_print_error(USAGE_MSG);
		//ft_print_error("fail open");//perror
	}
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
	//free(line);
	close(fd);
}

void	ft_check_map(t_game *game)
{
	/*

	int map_len;
	map_len = ft_strlen(game->map);
	// and send it too all fct
	
	if the maps is rectangular
		check if its sealed
			if is sealed check playability
	else 
		print and exit
	*/
	ft_check_sealed(game);
	ft_check_rectangular(game);
	ft_check_playability(game);
}

void	ft_check_sealed(t_game *game)
{
	int	idx;
	int map_len;

	idx = 0;
	map_len = ft_strlen(game->map);

	while (idx < map_len)
	{
		if (idx > map_len - game->width)
		{
			if (game->map[idx] != '1')
			{
				perror(ERROR_MSG);
       			ft_print_error(WALL_ERROR);
			}
		}
		else if (idx < game->width)
		{
			if (game->map[idx] != '1')
			{
				perror(ERROR_MSG);
       			ft_print_error(WALL_ERROR);
			}
		}
		else if (idx % game->width == 0 || idx % game->width == game->width - 1)
		{
			if (game->map[idx] != '1')
			{
				perror(ERROR_MSG);
       			ft_print_error(WALL_ERROR);
			}
		}
		idx++;
	}
}

void	ft_check_rectangular(t_game *game)
{
	int len_full_map;

	len_full_map = ft_strlen(game->map);
	if (game->height * game->width != len_full_map)
	{
		perror(ERROR_MSG);
		ft_print_error(FORM_ERROR);
	}
}

void	ft_check_playability(t_game *game)
{
	int	idx;
	int map_len;
	
	idx = 0;
	//lol that fuck up funny
	game->coin = idx;
	game->exit = idx;
	game->coin = idx;

	map_len = ft_strlen(game->map);
	while (idx++ < map_len)
	{		
		if (game->map[idx] == COIN_CHAR)
			game->coin++;
		else if (game->map[idx] == PLAYER_CHAR)
			game->player++;
		else if (game->map[idx] == EXIT_CHAR)
			game->exit++;
	}
	if (game->coin == 0)
	{
		perror(ERROR_MSG);
       	ft_print_error(COIN_ERROR);
	}
	if (game->player != 1)
	{
		perror(ERROR_MSG);
       	ft_print_error(PLAYER_ERROR);
	}
	if (game->exit == 0)
	{
		perror(ERROR_MSG);
       	ft_print_error(EXIT_ERROR);
	}
}
