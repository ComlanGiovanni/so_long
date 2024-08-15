/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_digits_assets_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:16:38 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 19:43:01 by gicomlan         ###   ########.fr       */
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
	//ft_load_digit_tab(game);
}

// void	ft_load_digit_tab(t_game *game)
// {
// 	game->hud.digits.tab[0] = game->hud.digits.zero.current;
// 	game->hud.digits.tab[1] = game->hud.digits.one.current;
// 	game->hud.digits.tab[2] = game->hud.digits.two.current;
// 	game->hud.digits.tab[3] = game->hud.digits.three.current;
// 	game->hud.digits.tab[4] = game->hud.digits.four.current;
// 	game->hud.digits.tab[5] = game->hud.digits.five.current;
// 	game->hud.digits.tab[6] = game->hud.digits.six.current;
// 	game->hud.digits.tab[7] = game->hud.digits.seven.current;
// 	game->hud.digits.tab[8] = game->hud.digits.eight.current;
// 	game->hud.digits.tab[9] = game->hud.digits.nine.current;
// }
