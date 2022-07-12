/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:39:30 by gcomlan           #+#    #+#             */
/*   Updated: 2022/05/25 22:55:38 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*src1;
	unsigned char			*dest1;

	src1 = (unsigned char *)src;
	dest1 = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*dest1++ = *src1++;
		n--;
	}
	return (dest);
}
