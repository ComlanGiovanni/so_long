/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:01:54 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/12 14:04:00 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int     ft_input_manager()
{
	if (key == ESC )
		//exit the game;
	else if (key == W || key == w)
		ft_move_up();
    else if (key == S || key == s)
		ft_move_down();
	else if (key == A || key == a)
		ft_move_left();
	else if (key == D || key == d)
		ft_move_right();
    else
        /*iddle animation*/
	return (0);
}

void	ft_move_up()
{
    int	idx;

	idx = 0;
    //print step_count;
}

void	ft_move_left()
{
	int	idx;

	idx = 0;
    //print step_count;
}

void	ft_move_down()
{
	int	idx;

	idx = 0;
}

void	ft_move_right()
{
	int	idx;

	idx = 0;
    //print step_count;
}
