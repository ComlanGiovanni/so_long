/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:55:14 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/09 16:23:51 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
    THIS FCT PRINT THE NUMBER AND RETURN
    THE LEN O THE NBR SO WE NEED UNSIGNED_ITOA TO
    GET THE LEN WITH PRINT_STR
*/

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

/*
    THIS FCT TRANSFORM A INTER TO A STRING ONLY FOR
	UNSIGN [0 to 4294967295]
*/

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

/*
	THIS FCT RETURN THE LEN OF THE UNSIGN
	[0 - 42 - 4294 - 4294967295]
*/

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
