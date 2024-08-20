/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_door_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:37:08 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 19:59:20 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

/**
 * @brief
 *
 * 			Same thing for every animation
 *
 * 	so every x.frames and x.frame * 2
 *  	we change the frame_0 to the 1 when we hit
 * 			the frame fof the object aka frame count
 * 				in the fct, then change it to frame 2
 * 					when we hit the double of the frame
 * 						the reset it to 0 again and again
 *
 *
 * @param door
 */
void	ft_door_open_animation(t_anim_door *animation)
{
	static int	frame = 0x0;

	if (frame == animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= animation->frames * 0x2)
	{
		animation->current = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

/**
 * @brief
 *
 * 			Same thing for every animation
 *
 * 	so every x.frames and x.frame * 2
 *  	we change the frame_0 to the 1 when we hit
 * 			the frame fof the object aka frame count
 * 				in the fct, then change it to frame 2
 * 					when we hit the double of the frame
 * 						the reset it to 0 again and again
 *
 *
 * @param door
 */
void	ft_door_closed_animation(t_anim_door *animation)
{
	static int	frame = 0x0;

	if (frame >= 0x0 && frame < animation->frames)
		animation->current = animation->frame_0;
	else if (frame >= animation->frames && frame < 0x2 * animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= 0x2 * animation->frames)
	{
		animation->current = animation->frame_2;
		frame = -1;
	}
	frame++;
}
