/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:28:23 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 01:03:19 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
