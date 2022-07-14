/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:55:40 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/13 23:07:03 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE (24)

char	*get_next_line(int fd);
char	*get_stash(int fd, char *stash);
char	*get_line(char *stash);
char	*new_stash(char *stash);
size_t	str_len(char *str);
char	*str_chr(char *stash, int new_line);
char	*str_join(char *stash, char *buff);
size_t	line_len(char *line);
void	stash_cpy(char *line, char *stash);

#endif
