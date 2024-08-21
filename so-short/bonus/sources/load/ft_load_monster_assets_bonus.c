/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_monster_assets_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:11:28 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/21 14:00:32 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_monster_up_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"monster/up/monster_up_frame_0.xpm",
		PATH_ASSET"monster/up/monster_up_frame_1.xpm",
		PATH_ASSET"monster/up/monster_up_frame_2.xpm"};

	ft_load_animation_sprites((t_animation *)&(game->monster.up_anim), \
		game, paths, paths);
	ft_load_sprite_frame(&(game->monster.up_anim.frame_move_0), \
		game, PATH_ASSET"monster/up/monster_up_frame_move_0.xpm", \
		PATH_ASSET"monster/up/monster_up_frame_move_0.xpm");
	ft_load_sprite_frame(&(game->monster.up_anim.frame_move_1), \
		game, PATH_ASSET"monster/up/monster_up_frame_move_1.xpm", \
		PATH_ASSET"monster/up/monster_up_frame_move_1.xpm");
}

void	ft_load_monster_down_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"monster/down/monster_down_frame_0.xpm",
		PATH_ASSET"monster/down/monster_down_frame_1.xpm",
		PATH_ASSET"monster/down/monster_down_frame_2.xpm"};

	ft_load_animation_sprites((t_animation *)&(game->monster.down_anim), \
		game, paths, paths);
	ft_load_sprite_frame(&(game->monster.down_anim.frame_move_0), \
		game, PATH_ASSET"monster/down/monster_down_frame_move_0.xpm",
		PATH_ASSET"monster/down/monster_down_frame_move_0.xpm");
	ft_load_sprite_frame(&(game->monster.down_anim.frame_move_1), \
		game, PATH_ASSET"monster/down/monster_down_frame_move_1.xpm", \
		PATH_ASSET"monster/down/monster_down_frame_move_1.xpm");
}

void	ft_load_monster_left_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"monster/left/monster_left_frame_0.xpm",
		PATH_ASSET"monster/left/monster_left_frame_1.xpm",
		PATH_ASSET"monster/left/monster_left_frame_2.xpm"};

	ft_load_animation_sprites((t_animation *)&(game->monster.left_anim), \
		game, paths, paths);
	ft_load_sprite_frame(&(game->monster.left_anim.frame_move_0), \
		game, PATH_ASSET"monster/left/monster_left_frame_move_0.xpm",
		PATH_ASSET"monster/left/monster_left_frame_move_0.xpm");
	ft_load_sprite_frame(&(game->monster.left_anim.frame_move_1), \
		game, PATH_ASSET"monster/left/monster_left_frame_move_1.xpm", \
		PATH_ASSET"monster/left/monster_left_frame_move_1.xpm");
}

void	ft_load_monster_right_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"monster/right/monster_right_frame_0.xpm",
		PATH_ASSET"monster/right/monster_right_frame_1.xpm",
		PATH_ASSET"monster/right/monster_right_frame_2.xpm",};

	ft_load_animation_sprites((t_animation *)&(game->monster.right_anim), \
		game, paths, paths);
	ft_load_sprite_frame(&(game->monster.right_anim.frame_move_0), \
		game, PATH_ASSET"monster/right/monster_right_frame_move_0.xpm", \
		PATH_ASSET"monster/right/monster_right_frame_move_0.xpm");
	ft_load_sprite_frame(&(game->monster.right_anim.frame_move_1), \
		game, PATH_ASSET"monster/right/monster_right_frame_move_1.xpm", \
		PATH_ASSET"monster/right/monster_right_frame_move_1.xpm");
}

void	ft_load_monster_current(t_game *game)
{
	game->monster.up_anim.current = game->monster.up_anim.frame_0;
	if (game->monster.up_anim.current == NULL)
		ft_print_error("game->monster.up_anim.current", game);
	game->monster.down_anim.current = game->monster.down_anim.frame_0;
	if (game->monster.down_anim.current == NULL)
		ft_print_error("game->monster.down_anim.current", game);
	game->monster.left_anim.current = game->monster.left_anim.frame_0;
	if (game->monster.left_anim.current == NULL)
		ft_print_error("game->monster.left_anim.current", game);
	game->monster.right_anim.current = game->monster.right_anim.frame_0;
	if (game->monster.right_anim.current == NULL)
		ft_print_error("game->monster.right_anim.current", game);
}
