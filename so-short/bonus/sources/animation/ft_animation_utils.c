/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:56:07 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:26:43 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_generic_animation(t_animation *animation, int *frame)
{
	if (*frame < animation->frames)
		animation->current = animation->frame_0;
	else if (*frame < animation->frames * 0x2)
		animation->current = animation->frame_1;
	else if (*frame < animation->frames * 0x3)
		animation->current = animation->frame_2;
	else
		*frame = 0x0;
	(*frame)++;
}

void	ft_life_management(t_game *game)
{
	if (game->player.life == PLAYER_MAX_LIFE)
		game->love.animation.current = game->love.nope;
	else
		ft_love_animation(&game->love.animation);
}
