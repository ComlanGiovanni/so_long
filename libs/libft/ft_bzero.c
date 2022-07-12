/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:31:43 by gcomlan           #+#    #+#             */
/*   Updated: 2022/05/25 22:58:31 by gcomlan          ###   ########.fr       */
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
