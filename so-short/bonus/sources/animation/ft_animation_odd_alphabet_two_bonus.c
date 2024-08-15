/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_odd_alphabet_two_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:51:15 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 21:51:25 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_alphabet_u_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_w_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_y_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}
