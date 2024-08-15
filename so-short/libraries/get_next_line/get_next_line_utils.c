/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:29:28 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 01:04:48 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_len(char *str)
{
	size_t	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*str_chr(char *stash, int new_line)
{
	int	idx;

	idx = 0;
	if (!stash)
		return (NULL);
	if (new_line == '\0')
		return ((char *)&stash[str_len(stash)]);
	while (stash[idx] != '\0')
	{
		if (stash[idx] == (char)new_line)
			return ((char *)&stash[idx]);
		idx++;
	}
	return (NULL);
}

char	*str_join(char *stash, char *buff)
{
	size_t	idx_stash;
	size_t	idx_buff;
	char	*str;

	idx_stash = -1;
	idx_buff = 0;
	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buff)
		return (NULL);
	str = (char *)malloc(((str_len(stash) + str_len(buff)) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (stash)
		while (stash[++idx_stash] != '\0')
			str[idx_stash] = stash[idx_stash];
	while (buff[idx_buff] != '\0')
		str[idx_stash++] = buff[idx_buff++];
	str[str_len(stash) + str_len(buff)] = '\0';
	free(stash);
	return (str);
}

size_t	line_len(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len);
}

void	stash_cpy(char *line, char *stash)
{
	int	idx;

	idx = 0;
	while (stash[idx] && stash[idx] != '\n')
	{
		line[idx] = stash[idx];
		idx++;
	}
	if (stash[idx] == '\n')
	{
		line[idx] = stash[idx];
		idx++;
	}
	line[idx] = '\0';
}
