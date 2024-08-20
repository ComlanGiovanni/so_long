/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_wall_utils_two_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:03:07 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 20:06:11 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_east_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_south_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_no_neighbors_four_direction_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_south_plus_east_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_animation(t_animation *animation)
{
	static int	frame = 0x0;

	ft_generic_animation(animation, &frame);
	frame++;
}
