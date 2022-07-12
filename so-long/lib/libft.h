/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:32:22 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/10 17:32:58 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		ft_count_str(char *str, char c);
int		ft_allocate_memory(char **strs, char *str, char c);
void	ft_fill_strs(char **strs, char *str, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen_2(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	ft_free_tab(char **tab);
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen_1(char *str);
int		ft_isspace(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strchr(const char *s, int c);

#endif
