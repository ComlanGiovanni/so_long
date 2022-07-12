/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:58:13 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/12 14:04:13 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
