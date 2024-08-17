/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_wall_direction_assets_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:37:39 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/17 01:54:55 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_wall_bit_masking_sprites(t_game *game)
{
	ft_load_wall_north_sprites(game);
	ft_load_wall_east_sprites(game);
	ft_load_wall_west_sprites(game);
	ft_load_wall_south_sprites(game);
	ft_load_wall_south_plus_east_sprites(game);
	ft_load_wall_south_plus_west_sprites(game);
	ft_load_wall_north_plus_east_sprites(game);
	ft_load_wall_south_plus_west_plus_east_sprites(game);
	ft_load_wall_north_plus_south_sprites(game);
	ft_load_wall_north_plus_south_plus_east_sprites(game);
	ft_load_wall_north_plus_south_plus_west_sprites(game);
	ft_load_wall_no_neighbors_four_direction_sprites(game);
	ft_load_wall_north_plus_south_plus_west_plus_east_sprites(game);
	ft_load_wall_north_plus_west_plus_east_sprites(game);
	ft_load_wall_west_plus_east_sprites(game);
	ft_load_wall_north_west_sprites(game);
	//ft_init_wall_bit_masking(game);
}
void	ft_load_wall_east_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/east/wall_east_frame_0.xpm",
		PATH_ASSET"wall/east/wall_east_frame_1.xpm",
		PATH_ASSET"wall/east/wall_east_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic meertssage change soon",
		"Generic mesrjersage change soon",
		"Generic metweessage change soon"};

	ft_load_animation_sprites(&(game->wall.east), game, paths,
		error_messages);
}

void	ft_load_wall_south_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/south/wall_south_frame_0.xpm",
		PATH_ASSET"wall/south/wall_south_frame_1.xpm",
		PATH_ASSET"wall/south/wall_south_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic mesertwsage change soon",
		"Generic message change soon",
		"Generic message change soon"};

	ft_load_animation_sprites(&(game->wall.south), game, paths,
		error_messages);
}

void	ft_load_wall_north_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/north/wall_north_frame_0.xpm",
		PATH_ASSET"wall/north/wall_north_frame_1.xpm",
		PATH_ASSET"wall/north/wall_north_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic mewerrrssage change soon",
		"Generic mewwwssage change soon",
		"Generic mewwwwssage change soon"};

	ft_load_animation_sprites(&(game->wall.north), game, paths,
		error_messages);
}

void	ft_load_wall_west_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"wall/west/wall_west_frame_0.xpm",
		PATH_ASSET"wall/west/wall_west_frame_1.xpm",
		PATH_ASSET"wall/west/wall_west_frame_2.xpm"};
	const char	*error_messages[] = {
		"Genewqrwreic message change soon",
		"Genewqrwwrieec mewqwrssage change soon",
		"Genewwwwwric message change soon"};

	ft_load_animation_sprites(&(game->wall.west), game, paths,
		error_messages);
}
