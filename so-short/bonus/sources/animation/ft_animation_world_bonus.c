/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_world_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:35:47 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 21:55:02 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_wall_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_pawn_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_lava_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_key_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_love_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}
