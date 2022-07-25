/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus_mac.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:24:45 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/25 17:07:38 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_mac/so_long_bonus_mac.h"

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
 * @param animation 
 */
void	ft_wall_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->frame_0 = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->frame_0 = animation->frame_2;
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
 * @param animation 
 */
void	ft_lava_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->frame_0 = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->frame_0 = animation->frame_2;
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
 * @param animation 
 */
void	ft_key_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->frame_0 = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->frame_0 = animation->frame_2;
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
void	ft_door_animation(t_door *door)
{
	static int	frame;

	frame += 1;
	if (frame == door->frames)
		door->open.frame_0 = door->open.frame_1;
	else if (frame >= door->frames * 2)
	{
		door->open.frame_0 = door->open.frame_2;
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
void	ft_love_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->frame_0 = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->frame_0 = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}
