/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:20:02 by gcomlan           #+#    #+#             */
/*   Updated: 2022/05/24 14:08:30 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	lenn;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		c = ft_calloc(1, sizeof(char));
		if (!c)
			return (NULL);
	}
	else
	{
		lenn = ft_strlen(s + start);
		if (!(lenn < len))
			lenn = len;
		c = (char *)malloc((lenn + 1) * sizeof(char));
		if (!c)
			return (NULL);
		c[lenn] = 0;
		while (lenn-- > 0)
			c[lenn] = s[start + lenn];
	}
	return (c);
}
