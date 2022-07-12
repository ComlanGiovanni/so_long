/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:55:14 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/09 16:19:27 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
    THIS FCT PRINT THE NUMBER AND RETURN
    THE LEN O THE NBR SO WE NEED ITOA TO
    GET THE LEN WITH PRINT_STR
*/

int	print_nbr(int nbr)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(nbr);
	len = print_str(str);
	free(str);
	return (len);
}

/*
    THIS FCT GET THE LEN OF THE NBR IF 0 1 OR 42 OR 1024
*/

int	len_nbr(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

/*
    THIS FCT TRANSFORM A INTER TO A STRING
*/

char	*ft_itoa(int nbr)
{
	long	len;
	long	tmp_len;
	char	*res;

	len = len_nbr(nbr);
	tmp_len = nbr;
	if (nbr < 0)
		tmp_len *= -1;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = 0;
	if (tmp_len == 0)
		res[0] = '0';
	else
	{
		while (len--, tmp_len != 0)
		{
			res[len] = (tmp_len % 10) + '0';
			tmp_len = (tmp_len - (tmp_len % 10)) / 10;
		}
		if (nbr < 0)
			res[len] = '-';
	}
	return (res);
}
