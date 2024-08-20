/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_alphabet_even_assets_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:34:19 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:49:15 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_alphabet_b(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/b/b_frame_0.xpm",
		PATH_ASSET"alphabet/b/b_frame_1.xpm",
		PATH_ASSET"alphabet/b/b_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.b), game, \
		paths, paths);
}

void	ft_load_alphabet_d(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/d/d_frame_0.xpm",
		PATH_ASSET"alphabet/d/d_frame_1.xpm",
		PATH_ASSET"alphabet/d/d_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.d), \
		game, paths, paths);
}

void	ft_load_alphabet_f(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/f/f_frame_0.xpm",
		PATH_ASSET"alphabet/f/f_frame_1.xpm",
		PATH_ASSET"alphabet/f/f_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.f), \
		game, paths, paths);
}

void	ft_load_alphabet_h(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/h/h_frame_0.xpm",
		PATH_ASSET"alphabet/h/h_frame_1.xpm",
		PATH_ASSET"alphabet/h/h_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.h), \
		game, paths, paths);
}

void	ft_load_alphabet_j(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/j/j_frame_0.xpm",
		PATH_ASSET"alphabet/j/j_frame_1.xpm",
		PATH_ASSET"alphabet/j/j_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.j), \
		game, paths, paths);
}
