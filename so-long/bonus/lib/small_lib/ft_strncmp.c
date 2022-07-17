/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:22:40 by gcomlan           #+#    #+#             */
/*   Updated: 2022/05/19 08:05:05 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t					idx;
	int						res;
	unsigned char			*t1;
	unsigned char			*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	idx = 0;
	res = 0;
	if (n == 0)
		return (0);
	while (t1[idx] != '\0' && t2[idx] != '\0' && idx < n)
	{
		if (t1[idx] != t2[idx])
			return (t1[idx] - t2[idx]);
		idx++;
	}
	if (idx < n)
		res = t1[idx] - t2[idx];
	else
		res = 0;
	return (res);
}
