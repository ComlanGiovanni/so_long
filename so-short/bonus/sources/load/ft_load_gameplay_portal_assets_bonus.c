/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_gameplay_portal_assets_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:25:32 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/13 13:00:18 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_portal_z_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"portal/second/portal_2_frame_1.xpm",
		PATH_ASSET"portal/second/portal_2_frame_0.xpm",
		PATH_ASSET"portal/second/portal_2_frame_2.xpm",};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon",
	};

	ft_load_animation_sprites((t_animation *)&(game->portal.z), game,
		paths, error_messages);
}

void	ft_load_portal_n_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"portal/first/portal_1_frame_1.xpm",
		PATH_ASSET"portal/first/portal_1_frame_0.xpm",
		PATH_ASSET"portal/first/portal_1_frame_2.xpm",};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon",
	};

	ft_load_animation_sprites((t_animation *)&(game->portal.n), game,
		paths, error_messages);
}