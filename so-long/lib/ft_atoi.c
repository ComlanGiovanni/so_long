/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:21:08 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/25 23:41:50 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						idx;
	int						sign;
	long long int			storage;

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
