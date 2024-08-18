/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:56:07 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/18 10:53:16 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void ft_generic_animation(t_animation *animation, int *frame) {
    if (*frame < animation->frames) {
        animation->current = animation->frame_0;
    } else if (*frame < animation->frames * 2) {
        animation->current = animation->frame_1;
    } else if (*frame < animation->frames * 3) {
        animation->current = animation->frame_2;
    } else {
        *frame = 0; // Reset the frame counter after a full cycle
    }
    (*frame)++;
}
