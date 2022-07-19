/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:24:45 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/19 20:47:37 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

/*
	repating myself here how can i fix it ?
*/

void	ft_player_animation(t_player *player)
{
    static int	frame;
	if (player->frames == 0)// remove after for test hors is usefull i we put 0 but bro ....
		return ;
	if (frame == player->frames)
	{
		player->up_anim.frame_0 = player->up_anim.frame_1;
		player->down_anim.frame_0 = player->down_anim.frame_1;
		player->left_anim.frame_0 = player->left_anim.frame_1;
		player->right_anim.frame_0 = player->right_anim.frame_1;
	}
	else if (frame >= player->frames * 2)
	{
		player->up_anim.frame_0 = player->up_anim.frame_2;
		player->down_anim.frame_0 = player->down_anim.frame_2;
		player->left_anim.frame_0 = player->left_anim.frame_2;
		player->right_anim.frame_0 = player->right_anim.frame_2;
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

void ft_door_animation(t_door *door)
{
    static int	frame;// long it on all frame ?

	frame += 1;
	if (door->frames == 0)// remove after for test hors is usefull i we put 0 but bro ....
		return ;
	if (frame == door->frames)
		door->open.frame_0 = door->open.frame_1;
	else if (frame >= door->frames * 2)
	{
		door->open.frame_0 = door->open.frame_2;
		frame = 0;
	}
	frame += 1;
}
