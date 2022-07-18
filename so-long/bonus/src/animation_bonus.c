/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:24:45 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/18 21:55:15 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

/*
	repating myself here how can i fix it ?
*/

void	ft_player_animation(t_sprites *sprite)
{
    static int	frame;
	if (sprite->player_frames == 0)
		return ;
	if (frame == sprite->player_frames)
	{
		sprite->player_up = sprite->player_up_frame_0;
		sprite->player_down = sprite->player_down_frame_0;
		sprite->player_left = sprite->player_left_frame_0;
		sprite->player_right = sprite->player_right_frame_0;
	}
	else if (frame >= sprite->player_frames * 2)
	{
		sprite->player_up = sprite->player_up_frame_1;
		sprite->player_down = sprite->player_down_frame_1;
		sprite->player_left = sprite->player_left_frame_1;
		sprite->player_right = sprite->player_right_frame_1;
		frame = 0;
	}
	frame += 1;
}

/*
void	ft_wall_animation(t_sprites *sprite)
{
    static int	frame;

	if (frame == sprite->wall_frames)
		sprite->wall = sprite->wall_0;
	else if (frame >= sprite->wall_frames * 2)
	{
		sprite->wall = sprite->wall_1;
		frame = 0;
	}
	frame += 1;
}
*/
void	ft_wall_animation(t_animation *animation)
{
    static int	frame;

	if (frame == animation->frames)
		animation->frame_0 = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->frame_0 = animation->frame_2;
		frame = 0;
	}
	frame += 1;
}

void ft_lava_animation(t_animation *animation)
{
    static int	frame;

	if (frame == animation->frames)
		animation->frame_0 = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->frame_0 = animation->frame_2;
		frame = 0;
	}
	frame += 1;
}

void ft_key_animation(t_animation *animation)
{
    static int	frame;

	if (frame == animation->frames)
		animation->frame_0 = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->frame_0 = animation->frame_2;
		frame = 0;
	}
	frame += 1;
}
