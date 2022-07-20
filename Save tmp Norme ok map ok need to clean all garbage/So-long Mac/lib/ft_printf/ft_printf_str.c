/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:55:14 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/09 16:24:22 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	THIS FCT CAN MAKE U TELEPORT
*/

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

/*
	THIS FT PRINT NULL IF THE POINTER IS NULL
					&&
	RETURN THE LEN OF THE STR
*/

int	print_str(char *str)
{
	int	idx;

	idx = 0;
	if (str == NULL)
	{
		ft_putstr(ADDR_NULL);
		return (6);
	}
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
	return (idx);
}
