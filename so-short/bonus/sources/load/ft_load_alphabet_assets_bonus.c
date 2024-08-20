/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_alphabet_assets_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:35:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:13:53 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_odd_alphabet_sprite(t_game *game)
{
	ft_load_alphabet_a(game);
	ft_load_alphabet_c(game);
	ft_load_alphabet_e(game);
	ft_load_alphabet_g(game);
	ft_load_alphabet_i(game);
	ft_load_alphabet_k(game);
	ft_load_alphabet_m(game);
	ft_load_alphabet_o(game);
	ft_load_alphabet_q(game);
	ft_load_alphabet_s(game);
	ft_load_alphabet_u(game);
	ft_load_alphabet_w(game);
	ft_load_alphabet_y(game);
}

void	ft_load_even_alphabet_sprite(t_game *game)
{
	ft_load_alphabet_b(game);
	ft_load_alphabet_d(game);
	ft_load_alphabet_f(game);
	ft_load_alphabet_h(game);
	ft_load_alphabet_j(game);
	ft_load_alphabet_l(game);
	ft_load_alphabet_n(game);
	ft_load_alphabet_p(game);
	ft_load_alphabet_r(game);
	ft_load_alphabet_t(game);
	ft_load_alphabet_v(game);
	ft_load_alphabet_x(game);
	ft_load_alphabet_z(game);
}

void	ft_load_alphabet_sprites(t_game *game)
{
	ft_load_odd_alphabet_sprite(game);
	ft_load_even_alphabet_sprite(game);
}
