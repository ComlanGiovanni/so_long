/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_wall_south_direction_assets_bonus.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:00:52 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/17 01:54:55 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"
void	ft_load_wall_south_plus_east_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/south_plus_east/wall_south_plus_east_frame_0.xpm",
		PATH_ASSET"wall/south_plus_east/wall_south_plus_east_frame_1.xpm",
		PATH_ASSET"wall/south_plus_east/wall_south_plus_east_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message change soon",
		"Generic messagrhwe change soon",
		"Generic messergrgage change soon"};

	ft_load_animation_sprites(&(game->wall.south_plus_east), game, paths,
		error_messages);
}

void	ft_load_wall_south_plus_west_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/south_plus_west/wall_south_plus_west_frame_0.xpm",
		PATH_ASSET"wall/south_plus_west/wall_south_plus_west_frame_1.xpm",
		PATH_ASSET"wall/south_plus_west/wall_south_plus_west_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic 123eherh1message change soon",
		"Genericwertq me2342342341ssage change soon",
		"Generic meretqrt3425353ssage change soon"};

	ft_load_animation_sprites(&(game->wall.south_plus_west), game, paths,
		error_messages);
}

void	ft_load_wall_south_plus_west_plus_east_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/south_plus_west_plus_east/wall_south_plus_west_plus_east_frame_0.xpm",
		PATH_ASSET"wall/south_plus_west_plus_east/wall_south_plus_west_plus_east_frame_1.xpm",
		PATH_ASSET"wall/south_plus_west_plus_east/wall_south_plus_west_plus_east_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic 12312message change soon",
		"Genewerric33f message change soon",
		"Generic 1werq3message change soon"};

	ft_load_animation_sprites(&(game->wall.south_plus_west_plus_east), game, paths,
		error_messages);
}
