/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:57:29 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/12 14:02:51 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//mac deine __apple_ and __linux 
//for copatibility

#include <stdlib.h> 

# define ESC		53
# define W			13
# define A			0
# define S			1
# define D			2

int		main(int ac, char *av[]);

//../src/input.c

int     ft_input_manager();
void	ft_move_up();
void	ft_move_left();
void	ft_move_down();
void	ft_move_right();

#endif
