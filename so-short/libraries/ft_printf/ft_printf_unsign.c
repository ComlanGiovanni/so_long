/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:28:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 01:03:34 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsign(unsigned int nbr)
{
	int		len;
	char	*str;

	len = 0;
	if (nbr == 0)
		len += write(1, "0", 1);
	else
	{
		str = unsign_itoa(nbr);
		len += print_str(str);
		free(str);
	}
	return (len);
}

char	*unsign_itoa(unsigned int nbr)
{
	char	*str;
	int		len;

	len = nbr_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (nbr != 0)
	{
		str[len - 1] = nbr % 10 + 48;
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

int	nbr_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}
