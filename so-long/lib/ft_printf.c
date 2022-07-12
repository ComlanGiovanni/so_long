/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:55:14 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/09 19:14:41 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	THIS FCT RETURN THE LEN OF THE FORMAT DISPLAYED
*/

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

/*
	THIS FCT MANAGE THE CSPUDX% FORMAT AND DISLAY THE ARG 
	WITH THE RETURN OF THE LEN
*/

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

/*
	THOSE FONCTION MAKE COFFEE
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && (s1[idx] != '\0' || s2[idx] != '\0'))
	{
		idx++;
	}
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

/*
#include "ft_printf.h"
#include <limits.h>

int main (void) //  ඞ
{
	int test = 42;
    char *lorem = "Lorem ipsum dolor sit amet,";
    char *nu_ll = "llun";
    ft_printf("\n");
    ft_printf("-");
    ft_printf(" ");
    ft_printf("-");
    ft_printf("\n");
    ft_printf("Char no flag:            ");
    ft_printf("d");
    ft_printf("\n");
    ft_printf("String no flag:          lol");
    ft_printf("\n");
    ft_printf("Pointer no flag:         ");
    ft_printf("0x5fd2xbc2d123");
    ft_printf("\n");
    ft_printf("Decimal no flag          ");
    ft_printf("24");
    ft_printf("\n");
    ft_printf("Decimal no flag          ");
    ft_printf("-85");
    ft_printf("\n");
    ft_printf("Uint no flag             ");
    ft_printf("4294967295");
    ft_printf("\n");
    ft_printf("Percent sans flag        ");
    ft_printf("%%");
    ft_printf(" %c",'%');
    ft_printf(" %s","%");
    ft_printf(" %% ");
	ft_printf(" %%  %%  %% ");
    ft_printf("\n");
    ft_printf("-");
    ft_printf(" ");
    ft_printf("-");
    ft_printf("\n");
    ft_printf("Char:                    %c\n", '0');
    ft_printf("String:                  %s\n", "bonjour");
    ft_printf("String lorem :           %s\n", lorem);
    ft_printf("String Vide:             %s\n", "");
    ft_printf("Pointer:                 %p\n", &test);
    ft_printf("Pointer NULL             %s\n", NULL);
    ft_printf("Pointer INT MAX:         %p\n", INT_MAX);
    ft_printf("Pointer NULL:            %p\n", (char *)0);
    ft_printf("Int:                     %d or %i\n", 45, 54);
    ft_printf("Int 0:                   %d or %i\n", 0, 0);
    ft_printf("Int MIN-MAX:             %i or %d\n", INT_MAX, INT_MIN);
    ft_printf("Uint:                    %u\n", ULONG_MAX);
    ft_printf("Hex lower:               %x\n", 0xa); //a
    ft_printf("Hex lower:               %x\n", 0xabcf012);
    ft_printf("Hex upper:               %X\n", 0xabcf012);
    ft_printf("Percent:                 %%\n");
    ft_printf("v%c%savec%px%d ou %i ou %u, 
	et %p\n", '-', "random", &test, 66 , 7, 41946723, NULL);
	ft_printf("Multiple conv:           %d %u %d %x %d\n", 1, -2, 3, 0xa, 5);
    ft_printf("Multiple same stuff:     %s %s %s %s %s\n",
	 nu_ll, "llun", nu_ll, nu_ll, "llun");

	return (0);
}
*/