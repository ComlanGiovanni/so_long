/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_even_alphabet_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:24:19 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 21:52:03 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_alphabet_b_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_d_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_f_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_h_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_j_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}
