/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_alphabet_even_two_assets_bonus.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:41:50 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:38:54 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_alphabet_v(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/v/v_frame_0.xpm",
		PATH_ASSET"alphabet/v/v_frame_1.xpm",
		PATH_ASSET"alphabet/v/v_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.v), \
		game, paths, paths);
}

void	ft_load_alphabet_x(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/x/x_frame_0.xpm",
		PATH_ASSET"alphabet/x/x_frame_1.xpm",
		PATH_ASSET"alphabet/x/x_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.x), \
		game, paths, paths);
}

void	ft_load_alphabet_z(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/z/z_frame_0.xpm",
		PATH_ASSET"alphabet/z/z_frame_1.xpm",
		PATH_ASSET"alphabet/z/z_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.alphabet.z), \
		game, paths, paths);
}
