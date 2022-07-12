/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:21:08 by gcomlan           #+#    #+#             */
/*   Updated: 2022/05/25 23:01:20 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_1(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

char	*ft_strdup(const char *s1)
{
	int		idx;
	char	*dest;

	idx = 0;
	dest = (char *)malloc(ft_strlen_1((char *)s1) * sizeof(char) + 1);
	if (dest)
	{
		while (s1[idx] != '\0')
		{
			dest[idx] = s1[idx];
			idx++;
		}
		dest[idx] = '\0';
		return (dest);
	}
	else
		return (NULL);
}
