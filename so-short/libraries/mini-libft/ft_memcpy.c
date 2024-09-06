/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:45:13 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 16:53:30 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (n >= sizeof(unsigned long))
	{
		*(unsigned long *)dest_cpy = *(const unsigned long *)src_cpy;
		dest_cpy += sizeof(unsigned long);
		src_cpy += sizeof(unsigned long);
		n -= sizeof(unsigned long);
	}
	while (n > 0x0)
	{
		*dest_cpy++ = *src_cpy++;
		n--;
	}
	return (dest);
}
