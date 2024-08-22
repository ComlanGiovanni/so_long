/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_player_assets_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:11:28 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 14:22:10 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//macro file ?
void	ft_load_player_up_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"player/up/player_up_frame_0.xpm",
		PATH_ASSET"player/up/player_up_frame_1.xpm",
		PATH_ASSET"player/up/player_up_frame_2.xpm"};

	ft_load_animation_sprites((t_animation *)&(game->player.up_anim), \
		game, paths, paths);
	ft_load_sprite_frame(&(game->player.up_anim.frame_move), \
		game, PATH_ASSET"player/up/player_up_frame_move.xpm", \
		PATH_ASSET"player/up/player_up_frame_move.xpm");
}

//macro file ?
void	ft_load_player_down_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"player/down/player_down_frame_0.xpm",
		PATH_ASSET"player/down/player_down_frame_1.xpm",
		PATH_ASSET"player/down/player_down_frame_2.xpm"};

	ft_load_animation_sprites((t_animation *)&(game->player.down_anim), \
		game, paths, paths);
	ft_load_sprite_frame(&(game->player.down_anim.frame_move), \
		game, PATH_ASSET"player/down/player_down_frame_move.xpm", \
		PATH_ASSET"player/down/player_down_frame_move.xpm");
}

//macro file ?
void	ft_load_player_left_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"player/left/player_left_frame_0.xpm",
		PATH_ASSET"player/left/player_left_frame_1.xpm",
		PATH_ASSET"player/left/player_left_frame_2.xpm"};

	ft_load_animation_sprites((t_animation *)&(game->player.left_anim), \
		game, paths, paths);
	ft_load_sprite_frame(&(game->player.left_anim.frame_move), \
		game, PATH_ASSET"player/left/player_left_frame_move.xpm", \
		PATH_ASSET"player/left/player_left_frame_move.xpm");
}

//macro file ?
void	ft_load_player_right_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"player/right/player_right_frame_0.xpm",
		PATH_ASSET"player/right/player_right_frame_1.xpm",
		PATH_ASSET"player/right/player_right_frame_2.xpm",};

	ft_load_animation_sprites((t_animation *)&(game->player.right_anim), game,
		paths, paths);
	ft_load_sprite_frame(&(game->player.right_anim.frame_move), \
		game, PATH_ASSET"player/right/player_right_frame_move.xpm", \
		PATH_ASSET"player/right/player_right_frame_move.xpm");
}

/**
 * @brief
 *
 *  For real i rteally dont know, i jjust
 * notcce thatthe current frqme of the door
 * is not loadead and i can easly free the
 * frae 0 of te door even if its animated
 * aka cchange y the fram 1 2 when i am playing
 * the game so that meain that i can
 * free the frame 0 even if it animatead ????
 *
 * @param game
 */
void	ft_load_player_current(t_game *game)
{
	game->player.up_anim.current = game->player.up_anim.frame_0;
	if (game->player.up_anim.current == NULL)
		ft_print_error(PLAYER_U_0_ERROR, game);
	game->player.down_anim.current = game->player.down_anim.frame_0;
	if (game->player.down_anim.current == NULL)
		ft_print_error(PLAYER_D_0_ERROR, game);
	game->player.left_anim.current = game->player.left_anim.frame_0;
	if (game->player.left_anim.current == NULL)
		ft_print_error(PLAYER_L_0_ERROR, game);
	game->player.right_anim.current = game->player.right_anim.frame_0;
	if (game->player.right_anim.current == NULL)
		ft_print_error(PLAYER_R_0_ERROR, game);
}
