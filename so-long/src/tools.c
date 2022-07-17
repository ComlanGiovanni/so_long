/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:27:34 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/17 18:46:57 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief 
 * 
 * It's just a strdup but until \n
 * dest =	malloc(size + 1);
 * 
 * @param s1 
 * @return char* 
 */
char	*ft_custom_strdup(char *s1)
{
	char	*dest;
	int		size;
	int		idx;

	dest = NULL;
	size = ft_strlen(s1);
	idx = 0;
	dest =	(char *)malloc(sizeof(char) * size + 1);
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
	idx = 0;
	if (dst_size == 0)
		return (len);
	while (idx < dst_size - 1 && *src && *src != '\n')
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
 * its just a strjoing but by the \n
 * dst = malloc((s1_len + s2_len));
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

void	ft_check_env(char **env)
{
	int	idx;

	if (!*env)
        ft_print_error(NO_ENV_ERROR);
	idx = 0;
	while (env[idx])
	{
		if (ft_strncmp("DISPLAY", env[idx], ft_strlen("DISPLAY")) == 0)
            return ;
        else
			idx++;
	}
	ft_print_error(NO_DISP_ERROR);
}

int	ft_check_extension(char *map_name, char *extension)
{
	int	len_map_name;
	int	len_extension;

	len_map_name = ft_strlen(map_name);
	len_extension = ft_strlen(extension);
	if (len_map_name <= len_extension)
		return (EXIT_SUCCESS);
	map_name += len_map_name - len_extension;
	while (*map_name)
	{
		if (*map_name != *extension)
			return (EXIT_SUCCESS);
		map_name++;
		extension++;
	}
	return (EXIT_FAILURE);
}
