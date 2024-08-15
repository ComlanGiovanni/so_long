/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:28:03 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 01:03:58 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		idx;
	va_list	args;
	int		len;

	idx = 0;
	len = 0;
	va_start(args, format);
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			len += check_format(args, format[idx + 1]);
			idx++;
		}
		else
			len += put_char(format[idx]);
		idx++;
	}
	va_end(args);
	return (len);
}

int	check_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += put_char(va_arg(args, int));
	else if (format == '%')
	{
		write(1, "%", 1);
		len++;
	}
	else if (format == 's')
		len += print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += print_nbr(va_arg(args, int));
	else if (format == 'u')
		len += print_unsign(va_arg(args, unsigned int));
	else if (format == 'p')
		len += print_ptr(va_arg(args, unsigned long long));
	else if (format == 'x' || format == 'X')
		len += print_hexa(va_arg(args, unsigned int), format);
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && (s1[idx] != '\0' || s2[idx] != '\0'))
		idx++;
	return (s1[idx] - s2[idx]);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	put_char(int c)
{
	write(1, &c, 1);
	return (1);
}
