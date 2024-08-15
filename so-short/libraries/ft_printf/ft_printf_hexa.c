/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:28:50 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 01:02:50 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned int hexa, const char format)
{
	if (hexa == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(hexa, format);
	return (ft_hex_len(hexa));
}

void	ft_put_hex(unsigned int hexa, const char format)
{
	if (hexa >= 16)
	{
		ft_put_hex(hexa / 16, format);
		ft_put_hex(hexa % 16, format);
	}
	else
	{
		if (hexa <= 9)
			ft_putchar_fd((hexa + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((hexa - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((hexa - 10 + 'A'), 1);
		}
	}
}

int	ft_hex_len(unsigned	int hexa)
{
	int	len;

	len = 0;
	while (hexa != 0)
	{
		len++;
		hexa = hexa / 16;
	}
	return (len);
}
