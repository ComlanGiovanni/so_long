/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_alphabet_odd_one_assets_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:50:19 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:39:20 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_alphabet_k(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/k/k_frame_0.xpm",
		PATH_ASSET"alphabet/k/k_frame_1.xpm",
		PATH_ASSET"alphabet/k/k_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.k), \
		game, paths, paths);
}

void	ft_load_alphabet_m(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/m/m_frame_0.xpm",
		PATH_ASSET"alphabet/m/m_frame_1.xpm",
		PATH_ASSET"alphabet/m/m_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.m), \
		game, paths, paths);
}

void	ft_load_alphabet_o(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/o/o_frame_0.xpm",
		PATH_ASSET"alphabet/o/o_frame_1.xpm",
		PATH_ASSET"alphabet/o/o_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.o), \
		game, paths, paths);
}

void	ft_load_alphabet_q(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/q/q_frame_0.xpm",
		PATH_ASSET"alphabet/q/q_frame_1.xpm",
		PATH_ASSET"alphabet/q/q_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.q), \
		game, paths, paths);
}

void	ft_load_alphabet_s(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/s/s_frame_0.xpm",
		PATH_ASSET"alphabet/s/s_frame_1.xpm",
		PATH_ASSET"alphabet/s/s_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.s), \
		game, paths, paths);
}
