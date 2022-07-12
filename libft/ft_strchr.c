/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:21:08 by gcomlan           #+#    #+#             */
/*   Updated: 2022/05/24 13:39:29 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)(s + idx));
		idx++;
	}
	if (s[idx] == (unsigned char)c)
		return ((char *)(s + idx));
	return (NULL);
}
