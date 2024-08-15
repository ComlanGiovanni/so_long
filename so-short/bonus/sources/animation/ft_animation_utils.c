/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:56:07 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 21:56:44 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_generic_animation(t_animation *animation, int *frame)
{
	if (*frame == animation->frames)
		animation->current = animation->frame_1;
	else if (*frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		*frame = FALSE;
	}
}
