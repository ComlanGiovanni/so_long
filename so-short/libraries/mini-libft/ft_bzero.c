/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:29:43 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/20 03:31:19 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			idx;
	char			*str;

	if (!s)
		return ;
	idx = 0;
	str = (char *)s;
	while (idx < n)
	{
		str[idx] = 0;
		idx++;
	}
}
