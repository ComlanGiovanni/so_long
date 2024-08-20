/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:57:15 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:27:54 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

char	*ft_custom_strdup(char *s1)
{
	char	*dest;
	int		size;
	int		idx;

	dest = NULL;
	size = ft_strlen(s1);
	idx = FALSE;
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!(dest))
		return (NULL);
	while (s1[idx] && s1[idx] != '\n')
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

/**
 * @brief
 *
 * It's just ft_strlcpy but the end file is \n
 *
 * @param dst
 * @param src
 * @param dst_size
 * @return int
 */
int	ft_custom_strlcpy(char *dst, char *src, int dst_size)
{
	int	idx;
	int	len;

	len = ft_strlen(src);
	idx = FALSE;
	if (dst_size == FALSE)
		return (len);
	while (idx < dst_size - TRUE && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		idx++;
	}
	*dst = '\0';
	return (len);
}

/**
 * @brief
 *
 * its just a strjoin but by the \n
 *
 * @param s1
 * @param s2
 * @return char*
 */
char	*ft_custom_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*dst;

	dst = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_custom_strdup(s2));
	else if (s2 == NULL)
		return (ft_custom_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!(dst))
		return (NULL);
	ft_custom_strlcpy(dst, s1, s1_len + 1);
	ft_custom_strlcpy((dst + s1_len), s2, s2_len + 1);
	free(s1);
	free(s2);
	return (dst);
}
