/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_border_three_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:29:14 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:58:22 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_foliage_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_bog_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_snail_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_pillar_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_hedge_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}
