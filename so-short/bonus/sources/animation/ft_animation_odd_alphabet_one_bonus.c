/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_odd_alphabet_one_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:47:58 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:59:53 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_alphabet_k_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_m_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_o_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_q_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_s_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}
