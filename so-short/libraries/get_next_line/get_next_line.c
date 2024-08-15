/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:29:09 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 01:04:49 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[8000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = get_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = new_stash(stash[fd]);
	return (line);
}

char	*get_stash(int fd, char *stash)
{
	char	*buff;
	int		idx;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	idx = 1;
	while (!str_chr(stash, '\n') && idx != 0)
	{
		idx = read(fd, buff, BUFFER_SIZE);
		if (idx == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[idx] = '\0';
		stash = str_join(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_line(char *stash)
{
	int		idx;
	char	*line;

	idx = 0;
	if (!stash[idx])
		return (NULL);
	line = (char *)malloc(sizeof(char) * (line_len(stash) + 2));
	if (!line)
		return (NULL);
	stash_cpy(line, stash);
	return (line);
}

char	*new_stash(char *stash)
{
	int		idx;
	int		idx_new_stash;
	char	*new_stash;

	idx = 0;
	idx_new_stash = 0;
	while (stash[idx] && stash[idx] != '\n')
		idx++;
	if (!stash[idx])
	{
		free(stash);
		return (NULL);
	}
	new_stash = (char *)malloc(sizeof(char) * (str_len(stash) - idx + 1));
	if (!new_stash)
		return (NULL);
	idx++;
	while (stash[idx])
		new_stash[idx_new_stash++] = stash[idx++];
	new_stash[idx_new_stash] = '\0';
	free(stash);
	return (new_stash);
}
