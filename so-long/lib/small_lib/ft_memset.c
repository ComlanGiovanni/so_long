/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:39:30 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/26 23:47:47 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			idx;
	unsigned char	*s;

	if (!b)
		return (NULL);
	idx = 0;
	s = (unsigned char *)b;
	while (idx < len)
	{
		s[idx] = c;
		idx++;
	}
	return (s);
}
