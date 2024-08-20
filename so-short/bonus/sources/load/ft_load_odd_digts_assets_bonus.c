/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_odd_digts_assets_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:21:40 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/20 23:45:46 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_digit_one(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"digits/1/digit_1_frame_0.xpm",
		PATH_ASSET"digits/1/digit_1_frame_1.xpm",
		PATH_ASSET"digits/1/digit_1_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.digits.one), \
		game, paths, paths);
}

void	ft_load_digit_tree(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"digits/3/digit_3_frame_0.xpm",
		PATH_ASSET"digits/3/digit_3_frame_1.xpm",
		PATH_ASSET"digits/3/digit_3_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.digits.three), \
		game, paths, paths);
}

void	ft_load_digit_five(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"digits/5/digit_5_frame_0.xpm",
		PATH_ASSET"digits/5/digit_5_frame_1.xpm",
		PATH_ASSET"digits/5/digit_5_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.digits.five), \
		game, paths, paths);
}

void	ft_load_digit_seven(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"digits/7/digit_7_frame_0.xpm",
		PATH_ASSET"digits/7/digit_7_frame_1.xpm",
		PATH_ASSET"digits/7/digit_7_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.digits.seven), \
		game, paths, paths);
}

void	ft_load_digit_nine(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"digits/9/digit_9_frame_0.xpm",
		PATH_ASSET"digits/9/digit_9_frame_1.xpm",
		PATH_ASSET"digits/9/digit_9_frame_2.xpm"};

	ft_load_animation_sprites(&(game->hud.digits.nine), \
		game, paths, paths);
}
