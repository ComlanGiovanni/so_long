/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:58:13 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/20 14:52:12 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

/*
ft_print_error(FAIL_OPEN_ERROR);
make a custom fct for fd fail segfautl or
ft_print_error(map_name);
*/
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
	game->width = width;
	game->map.map_str = ft_custom_strdup(line);
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
			game->map.map_str = ft_custom_strjoin(game->map.map_str, line);
	}
	close(fd);
	game->map.len = ft_strlen(game->map.map_str);
}

/*
//ft_check_rectangular(game);
in bonus we can have squared map
*/
void	ft_check_map(t_game *game)
{
	ft_check_valid_char(game);
	ft_check_sealed(game);
	ft_get_info_map(game);
	ft_check_playability(game);
	ft_print_map_better_format(game);
}

void	ft_check_sealed(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx < game->map.len)
	{
		if (idx > (game->map.len - game->width))
		{
			if (game->map.map_str[idx] != '1')
				ft_print_error(WALL_ERROR);
		}
		else if (idx < game->width)
		{
			if (game->map.map_str[idx] != '1')
				ft_print_error(WALL_ERROR);
		}
		else if (idx % game->width == 0 || idx % game->width == game->width - 1)
		{
			if (game->map.map_str[idx] != '1')
				ft_print_error(WALL_ERROR);
		}
		idx++;
	}
}

/*
void	ft_check_rectangular(t_game *game)
{
	if (game->height == game->width)
		ft_print_error(FORM_ERROR);
}
*/

/*
	on profite pour recup
	les info de la map
*/

//lol that fuck up and funny idx flemme move
//ft_check_playability

// maka fucking fct for init mapino to 0

void	ft_get_info_map(t_game *game)
{
	int	idx;

	idx = 0;
	game->map.nbr_player = idx;
	game->map.nbr_key = idx;
	game->map.nbr_exit = idx;
	game->map.nbr_lava = idx;
	game->map.nbr_love = idx;
	game->map.nbr_wall = 1;
	game->map.nbr_void = idx;
	while (idx++ < game->map.len)
	{		
		if (game->map.map_str[idx] == KEY_CHAR)
			game->map.nbr_key++;
		else if (game->map.map_str[idx] == PLAYER_CHAR)
			game->map.nbr_player++;
		else if (game->map.map_str[idx] == EXIT_CHAR)
			game->map.nbr_exit++;
		else if (game->map.map_str[idx] == LAVA_CHAR)
			game->map.nbr_lava++;
		else if (game->map.map_str[idx] == LOVE_CHAR)
			game->map.nbr_love++;
		else if (game->map.map_str[idx] == WALL_CHAR)
			game->map.nbr_wall++;
		else
			game->map.nbr_void++;
	}
}

void	ft_check_playability(t_game *game)
{
	if (game->map.nbr_key == 0)
		ft_print_error(COIN_ERROR);
	if (game->map.nbr_player != 1)
		ft_print_error(PLAYER_ERROR);
	if (game->map.nbr_exit == 0)
		ft_print_error(EXIT_ERROR);
}
