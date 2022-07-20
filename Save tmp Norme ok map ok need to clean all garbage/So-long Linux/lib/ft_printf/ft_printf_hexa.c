/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:55:14 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/09 18:18:57 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	THIS FCT RETURN THE LEN OF THE HEXA AND DIPLAY IT
*/

int	print_hexa(unsigned int hexa, const char format)
{
	if (hexa == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(hexa, format);
	return (ft_hex_len(hexa));
}

/*
	THIS FCT DISPLAY THE INT IN TE HEXA FORMAT MIN OR MAJ
*/

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

/*
	THIS FCT RETURN THE LEN OF THE HEXA NBR
*/

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
