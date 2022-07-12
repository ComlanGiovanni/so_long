/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:39:25 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 23:41:25 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;
	char	str;

	idx = 0;
	str = c;
	while (s[idx] && s[idx] != str)
		idx++;
	if (s[idx] == str)
		return ((char *)&s[idx]);
	return (NULL);
}
