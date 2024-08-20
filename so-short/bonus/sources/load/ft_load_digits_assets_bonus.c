/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_digits_assets_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:16:38 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 22:21:14 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_digits_sprites(t_game *game)
{
	ft_load_digit_zero(game);
	ft_load_digit_one(game);
	ft_load_digit_two(game);
	ft_load_digit_tree(game);
	ft_load_digit_four(game);
	ft_load_digit_five(game);
	ft_load_digit_six(game);
	ft_load_digit_seven(game);
	ft_load_digit_eight(game);
	ft_load_digit_nine(game);
}
