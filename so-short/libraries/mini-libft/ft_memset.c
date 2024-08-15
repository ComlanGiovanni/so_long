/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:30:33 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/20 03:30:36 by gicomlan         ###   ########.fr       */
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
