/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:45:04 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 16:46:28 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	if ((src_len + 0x1) < size)
		ft_memcpy(dst, src, (src_len + 0x1));
	else if (size != 0x0)
	{
		ft_memcpy(dst, src, (size - 0x1));
		dst[size - 0x1] = 0x0;
	}
	return (src_len);
}
