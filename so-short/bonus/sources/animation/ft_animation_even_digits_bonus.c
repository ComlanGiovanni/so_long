/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:32:50 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/06 23:34:52 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_five_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_six_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_seven_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_eight_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_nine_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}
