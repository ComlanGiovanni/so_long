/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:55:45 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/03 10:34:20 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	CETTE FONCTION PREPARE LE CAFER
*/

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

/*
cette fonction chercher dans la stash le retour a la ligne
	if (new_line == '\0')
*/

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

/*
Cette fonction

Si la stash est vide on malloc a 1 e on metune fin de char
	adding a lot of line 
	if (stash)
	{
		while (stash[idx_stash] != '\0')
		{
			str[idx_stash] = stash[idx_stash];
			idx_stash++;
		}
	}
*/

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

/*
Calcul la taille de la ligne
*/

size_t	line_len(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len);
}

/*
Modifie line en copiant la stash formater en ligne
*/

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
