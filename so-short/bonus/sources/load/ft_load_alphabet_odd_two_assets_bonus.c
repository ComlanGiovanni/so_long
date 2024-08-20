/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_alphabet_odd_two_assets_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:50:22 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:49:00 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_alphabet_u(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/u/u_frame_0.xpm",
		PATH_ASSET"alphabet/u/u_frame_1.xpm",
		PATH_ASSET"alphabet/u/u_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.u), \
		game, paths, paths);
}

void	ft_load_alphabet_w(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/w/w_frame_0.xpm",
		PATH_ASSET"alphabet/w/w_frame_1.xpm",
		PATH_ASSET"alphabet/w/w_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.w), \
		game, paths, paths);
}

void	ft_load_alphabet_y(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/y/y_frame_0.xpm",
		PATH_ASSET"alphabet/y/y_frame_1.xpm",
		PATH_ASSET"alphabet/y/y_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.y), \
		game, paths, paths);
}
