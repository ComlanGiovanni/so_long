/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_keke_assets_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:11:28 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/13 13:00:18 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_keke_up_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"keke/up/keke_up_frame_0.xpm",
		PATH_ASSET"keke/up/keke_up_frame_1.xpm",
		PATH_ASSET"keke/up/keke_up_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites((t_animation *)&(game->keke.up_anim), game,
		paths, error_messages);
	ft_load_sprite_frame(&(game->keke.up_anim.frame_move_0), game,
		PATH_ASSET"keke/up/keke_up_frame_move_0.xpm",
		"Generic message error replace soon");
	ft_load_sprite_frame(&(game->keke.up_anim.frame_move_1), game,
		PATH_ASSET"keke/up/keke_up_frame_move_1.xpm",
		"Generic message error replace soon");
}

void	ft_load_keke_down_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"keke/down/keke_down_frame_0.xpm",
		PATH_ASSET"keke/down/keke_down_frame_1.xpm",
		PATH_ASSET"keke/down/keke_down_frame_2.xpm"};
	const char	*error_messages[] = {
		"keke_D_0_ERROR",
		"keke_D_1_ERROR",
		"keke_D_2_ERROR"};

	ft_load_animation_sprites((t_animation *)&(game->keke.down_anim), game,
		paths, error_messages);
	ft_load_sprite_frame(&(game->keke.down_anim.frame_move_0), game,
		PATH_ASSET"keke/down/keke_down_frame_move_0.xpm",
		"Generic message error replace soon");
	ft_load_sprite_frame(&(game->keke.down_anim.frame_move_1), game,
		PATH_ASSET"keke/down/keke_down_frame_move_1.xpm",
		"Generic message error replace soon");
}

void	ft_load_keke_left_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"keke/left/keke_left_frame_0.xpm",
		PATH_ASSET"keke/left/keke_left_frame_1.xpm",
		PATH_ASSET"keke/left/keke_left_frame_2.xpm"};
	const char	*error_messages[] = {
		"keke_L_0_ERROR",
		"keke_L_1_ERROR",
		"keke_L_2_ERROR"};

	ft_load_animation_sprites((t_animation *)&(game->keke.left_anim), game,
		paths, error_messages);
	ft_load_sprite_frame(&(game->keke.left_anim.frame_move_0), game,
		PATH_ASSET"keke/left/keke_left_frame_move_0.xpm",
		"Generic message error replace soon");
	ft_load_sprite_frame(&(game->keke.left_anim.frame_move_1), game,
		PATH_ASSET"keke/left/keke_left_frame_move_1.xpm",
		"Generic message error replace soon");
}

void	ft_load_keke_right_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"keke/right/keke_right_frame_0.xpm",
		PATH_ASSET"keke/right/keke_right_frame_1.xpm",
		PATH_ASSET"keke/right/keke_right_frame_2.xpm",};
	const char	*error_messages[] = {
		"keke_R_0_ERROR",
		"keke_R_1_ERROR",
		"keke_R_2_ERROR",
	};

	ft_load_animation_sprites((t_animation *)&(game->keke.right_anim), game,
		paths, error_messages);
	ft_load_sprite_frame(&(game->keke.right_anim.frame_move_0), game,
		PATH_ASSET"keke/right/keke_right_frame_move_0.xpm",
		"Generic message error replace soon");
	ft_load_sprite_frame(&(game->keke.right_anim.frame_move_1), game,
		PATH_ASSET"keke/right/keke_right_frame_move_1.xpm",
		"Generic message error replace soon");
}


void	ft_load_keke_current(t_game *game)
{
	game->keke.up_anim.current = game->keke.up_anim.frame_0;
	if (game->keke.up_anim.current == NULL)
		ft_print_error("Generic message error replace soon", game);
	game->keke.down_anim.current = game->keke.down_anim.frame_0;
	if (game->keke.down_anim.current == NULL)
		ft_print_error("Generic message error replace soon", game);
	game->keke.left_anim.current = game->keke.left_anim.frame_0;
	if (game->keke.left_anim.current == NULL)
		ft_print_error("Generic message error replace soon", game);
	game->keke.right_anim.current = game->keke.right_anim.frame_0;
	if (game->keke.right_anim.current == NULL)
		ft_print_error("Generic message error replace soon", game);
}
