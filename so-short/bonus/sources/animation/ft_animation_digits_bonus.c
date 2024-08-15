/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_digits_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:01:57 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 21:44:07 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_digits_animation(t_game *game)
{
	ft_zero_animation(&game->hud.digits.zero);
	ft_one_animation(&game->hud.digits.one);
	ft_two_animation(&game->hud.digits.two);
	ft_three_animation(&game->hud.digits.three);
	ft_four_animation(&game->hud.digits.four);
	ft_five_animation(&game->hud.digits.five);
	ft_six_animation(&game->hud.digits.six);
	ft_seven_animation(&game->hud.digits.seven);
	ft_eight_animation(&game->hud.digits.eight);
	ft_nine_animation(&game->hud.digits.nine);
}
