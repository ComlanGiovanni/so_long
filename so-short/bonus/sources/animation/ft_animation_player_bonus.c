/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_player_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:45:04 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/18 08:56:39 by gicomlan         ###   ########.fr       */
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
 * 	same but we change every state of the player
 * 		in can we are facing up down left and right
 *
 * @param player
 */
void	ft_player_animation(t_player *player)
{
	static int	frame;

	if (frame == player->frames)
	{
		player->up_anim.current = player->up_anim.frame_1;
		player->down_anim.current = player->down_anim.frame_1;
		player->left_anim.current = player->left_anim.frame_1;
		player->right_anim.current = player->right_anim.frame_1;
	}
	else if (frame >= player->frames * 2)
	{
		player->up_anim.current = player->up_anim.frame_2;
		player->down_anim.current = player->down_anim.frame_2;
		player->left_anim.current = player->left_anim.frame_2;
		player->right_anim.current = player->right_anim.frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_monster_animation(t_monster *monster)
{
	static int	frame;

	if (frame == monster->frames)
	{
		monster->up_anim.current = monster->up_anim.frame_1;
		monster->down_anim.current = monster->down_anim.frame_1;
		monster->left_anim.current = monster->left_anim.frame_1;
		monster->right_anim.current = monster->right_anim.frame_1;
	}
	else if (frame >= monster->frames * 2)
	{
		monster->up_anim.current = monster->up_anim.frame_2;
		monster->down_anim.current = monster->down_anim.frame_2;
		monster->left_anim.current = monster->left_anim.frame_2;
		monster->right_anim.current = monster->right_anim.frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}
