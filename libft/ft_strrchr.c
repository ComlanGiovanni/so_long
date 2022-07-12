/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:21:08 by gcomlan           #+#    #+#             */
/*   Updated: 2022/05/25 23:02:51 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		idx;
	char	*str;

	idx = 0;
	str = 0;
	while (s[idx])
	{
		if (s[idx] == (unsigned char)c)
			str = (char *)(s + idx);
		idx++;
	}
	if (s[idx] == (unsigned char)c)
		str = (char *)(s + idx);
	return (str);
}
