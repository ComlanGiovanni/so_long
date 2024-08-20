/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_wall_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 04:35:36 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 20:06:37 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_south_plus_west_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_plus_east_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_south_plus_west_plus_east_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_plus_south_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_plus_south_plus_east_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}
