/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:48 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/12 04:19:36 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_init_game()
{
	ft_read_map();
	ft_check_map();
    //"so_long" title name define
}

void	ft_read_map()
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
    if (fd <= 0)
		//"File open fail.\n"
    line = get_next_line(fd);
	close(fd);
}

void	ft_check_map()
{
    //"Map must be rectangular.\n"
	//wall
	//params
}
