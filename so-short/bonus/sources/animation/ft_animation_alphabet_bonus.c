/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_alphabet_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:34:32 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 21:37:21 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_alphabet_animation(t_game *game)
{
	ft_odd_alphabet_animation(game);
	ft_even_alphabet_animation(game);
}

void	ft_odd_alphabet_animation(t_game *game)
{
	ft_alphabet_a_animation(&game->hud.alphabet.a);
	ft_alphabet_c_animation(&game->hud.alphabet.c);
	ft_alphabet_e_animation(&game->hud.alphabet.e);
	ft_alphabet_g_animation(&game->hud.alphabet.g);
	ft_alphabet_i_animation(&game->hud.alphabet.i);
	ft_alphabet_k_animation(&game->hud.alphabet.k);
	ft_alphabet_m_animation(&game->hud.alphabet.m);
	ft_alphabet_o_animation(&game->hud.alphabet.o);
	ft_alphabet_q_animation(&game->hud.alphabet.q);
	ft_alphabet_s_animation(&game->hud.alphabet.s);
	ft_alphabet_u_animation(&game->hud.alphabet.u);
	ft_alphabet_w_animation(&game->hud.alphabet.w);
	ft_alphabet_y_animation(&game->hud.alphabet.y);
}

void	ft_even_alphabet_animation(t_game *game)
{
	ft_alphabet_b_animation(&game->hud.alphabet.b);
	ft_alphabet_d_animation(&game->hud.alphabet.d);
	ft_alphabet_f_animation(&game->hud.alphabet.f);
	ft_alphabet_h_animation(&game->hud.alphabet.h);
	ft_alphabet_j_animation(&game->hud.alphabet.j);
	ft_alphabet_l_animation(&game->hud.alphabet.l);
	ft_alphabet_n_animation(&game->hud.alphabet.n);
	ft_alphabet_p_animation(&game->hud.alphabet.p);
	ft_alphabet_r_animation(&game->hud.alphabet.r);
	ft_alphabet_t_animation(&game->hud.alphabet.t);
	ft_alphabet_v_animation(&game->hud.alphabet.v);
	ft_alphabet_x_animation(&game->hud.alphabet.x);
	ft_alphabet_z_animation(&game->hud.alphabet.z);
}
