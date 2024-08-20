/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_alphabet_even_one_assets_bonus.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:40:55 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:38:41 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_alphabet_l(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/l/l_frame_0.xpm",
		PATH_ASSET"alphabet/l/l_frame_1.xpm",
		PATH_ASSET"alphabet/l/l_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.l), \
		game, paths, paths);
}

void	ft_load_alphabet_n(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/n/n_frame_0.xpm",
		PATH_ASSET"alphabet/n/n_frame_1.xpm",
		PATH_ASSET"alphabet/n/n_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.n), \
		game, paths, paths);
}

void	ft_load_alphabet_p(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/p/p_frame_0.xpm",
		PATH_ASSET"alphabet/p/p_frame_1.xpm",
		PATH_ASSET"alphabet/p/p_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.p), \
		game, paths, paths);
}

void	ft_load_alphabet_r(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/r/r_frame_0.xpm",
		PATH_ASSET"alphabet/r/r_frame_1.xpm",
		PATH_ASSET"alphabet/r/r_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.r), \
		game, paths, paths);
}

void	ft_load_alphabet_t(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/t/t_frame_0.xpm",
		PATH_ASSET"alphabet/t/t_frame_1.xpm",
		PATH_ASSET"alphabet/t/t_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.t), \
		game, paths, paths);
}
