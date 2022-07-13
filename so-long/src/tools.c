/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:27:34 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/13 13:55:16 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//ft_strdup_without_newline

char	*ft_custom_strdup(char *s1)
{
    int		idx;
	char	*dest;

	idx = 0;
	dest = (char *)malloc(ft_strlen((char *)s1) * sizeof(char) + 1);
	if (dest)
	{
		while (s1[idx] != '\n')
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

//ft_strlcpy_line_without_newline

int	ft_custom_strlcpy(char *dst, char *src, int dst_size)
{
	int	idx;
	int	len;

	len = ft_strlen(src);
	idx = 0;
	if (dst_size != 0)
	{
		while (src[idx] != '\n' && idx < dst_size - 1)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (len);
}

//ft_strjoin_line_without_newline

char	*ft_custom_strjoin(char *s1, char *s2)
{
	int	s1_len;
	int	s2_len;
	char	*dst;


    if (s1 == NULL && s2 == NULL)
		return (NULL);
    else if (s1 == NULL)
		return (ft_custom_strdup(s2));
	else if (s2 == NULL)
		return (ft_custom_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_custom_strlcpy(dst, s1, s1_len + 1);
	ft_custom_strlcpy((dst + s1_len), s2, s2_len + 1);
    free(s1);
	//free(s2);
	return (dst);
}
