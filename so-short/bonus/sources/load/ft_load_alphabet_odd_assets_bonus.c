/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_alphabet_odd_assets_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:34:17 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:36:54 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_alphabet_a(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/a/a_frame_0.xpm",
		PATH_ASSET"alphabet/a/a_frame_1.xpm",
		PATH_ASSET"alphabet/a/a_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.a), \
		game, paths, paths);
}

void	ft_load_alphabet_c(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/c/c_frame_0.xpm",
		PATH_ASSET"alphabet/c/c_frame_1.xpm",
		PATH_ASSET"alphabet/c/c_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.c), \
		game, paths, paths);
}

void	ft_load_alphabet_e(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/e/e_frame_0.xpm",
		PATH_ASSET"alphabet/e/e_frame_1.xpm",
		PATH_ASSET"alphabet/e/e_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.e), \
		game, paths, paths);
}

void	ft_load_alphabet_g(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/g/g_frame_0.xpm",
		PATH_ASSET"alphabet/g/g_frame_1.xpm",
		PATH_ASSET"alphabet/g/g_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.g), \
		game, paths, paths);
}

void	ft_load_alphabet_i(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/i/i_frame_0.xpm",
		PATH_ASSET"alphabet/i/i_frame_1.xpm",
		PATH_ASSET"alphabet/i/i_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.i), \
		game, paths, paths);
}
