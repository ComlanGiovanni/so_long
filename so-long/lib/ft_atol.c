/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:18:16 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/01 04:27:17 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int						idx;
	int						sign;
	long					storage;

	idx = 0;
	sign = 1;
	storage = 0;
	while (str[idx] == ' ' || (str[idx] >= '\t' && str[idx] <= '\r'))
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] != '\0' && (str[idx] >= '0' && str[idx] <= '9'))
	{
		storage *= 10;
		storage += str[idx] - 48;
		idx++;
	}
	return (storage * sign);
}
