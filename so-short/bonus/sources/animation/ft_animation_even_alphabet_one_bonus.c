/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_even_alphabet_one_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:48:14 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:59:37 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_alphabet_l_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_n_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_p_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_r_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_t_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}
