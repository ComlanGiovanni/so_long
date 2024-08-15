/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:27:58 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 12:48:41 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define ADDR_PREF "0x"
# define ADDR_NULL "(null)"
# define PTR_NULL "(nil)"

int		ft_printf(const char *format, ...);
int		check_format(va_list args, const char format);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar_fd(char c, int fd);
int		put_char(int c);

void	ft_putstr(char *str);
int		print_str(char *str);

int		print_ptr(unsigned long long ptr);
void	ft_put_ptr(uintptr_t addr);
int		ft_ptr_len(uintptr_t addr);

int		print_nbr(int nbr);
int		len_nbr(long nbr);
char	*ft_itoa(int nbr);

int		print_unsign(unsigned int nbr);
char	*unsign_itoa(unsigned int nbr);
int		nbr_len(unsigned	int nbr);

int		print_hexa(unsigned int hexa, const char format);
void	ft_put_hex(unsigned int hexa, const char format);
int		ft_hex_len(unsigned	int hexa);

#endif
