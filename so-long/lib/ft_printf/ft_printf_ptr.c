/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:55:14 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/10 11:35:00 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	THIS FCT MANAGE APPLE OR MAC POINTER NULL AND DISPLAY THE ADDR IN HEXA
*/

int	print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ft_strcmp(PTR_NULL, "0x0") == 0 && (void *)ptr == NULL)
			len += write(1, PTR_NULL, 5);
	else if (ft_strcmp(PTR_NULL, "(nil)") == 0 && (void *)ptr == NULL)
			len += write(1, PTR_NULL, 5);
	else
	{
		len += write(1, ADDR_PREF, 2);
		ft_put_ptr(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}
/*
	THIS FCT TRANLATE INTO HEXA THE POINTER
*/

void	ft_put_ptr(uintptr_t addr)
{
	if (addr >= 16)
	{
		ft_put_ptr(addr / 16);
		ft_put_ptr(addr % 16);
	}
	else
	{
		if (addr <= 9)
			ft_putchar_fd((addr + '0'), 1);
		else
			ft_putchar_fd((addr - 10 + 'a'), 1);
	}
}

/*
	THIS FCT RETURN THE LEN OF THE POINTER ADDR
*/

int	ft_ptr_len(uintptr_t addr)
{
	int	len;

	len = 0;
	while (addr != 0)
	{
		len++;
		addr = addr / 16;
	}
	return (len);
}

/*	
	MDR 26 lignes watch me

	int	len;

	len = 0;
	if (ft_strcmp(PTR_NULL, "0x0") == 0)
	{
		len += write(1, ADDR_PREF, 2);
		if ((void *)ptr == NULL)
			len += write(1, "0", 1);
		else
		{
			ft_put_ptr(ptr);
			len += ft_ptr_len(ptr);
		}
	}
	else if (ft_strcmp(PTR_NULL, "(nil)") == 0)
	{
		if ((void *)ptr == NULL)
			ft_putstr(PTR_NULL);
		else
		{
			len += write(1, ADDR_PREF, 2);
			ft_put_ptr(ptr);
			len += ft_ptr_len(ptr);
		}
	}
	return (len);
*/
