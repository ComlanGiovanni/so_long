/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:58:13 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/12 20:38:33 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_read_map(char *filename, t_game *game)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(filename, O_RDONLY);
    if (fd <= 0)
		ft_print_error("fail open");//perror
    line = get_next_line(fd);
	width = ft_strlen(line) - 1;
	game->height = 0;
	game->step = 0;
	game->width = width;
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
		{
			//
		}
	}
	free(line);
	close(fd);
}

void	ft_check_map(t_game *game)
{
	/*
	if the maps is rectangular
		check if its sealed
			if is sealed check playability
	else 
		print and exit
	*/
	ft_check_map_sealed(game);
	ft_check_rectangular(game);
	ft_check_playability(game);
}

void	ft_check_params(t_game *game)
{
	int	idx;

	idx = 0;
}

void	ft_check_sealed(t_game *game)
{
	int	idx;

	idx = 0;
}

void	ft_check_playability(t_game *game)
{
	int len_full_map;

	len_full_map = ft_strlen();
	if (game->height * game->width != len_full_map)
		return ;
	//"Map must be rectangular.\n" perrno
}
