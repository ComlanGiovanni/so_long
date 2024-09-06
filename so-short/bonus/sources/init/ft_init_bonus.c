/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:20:05 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 19:13:20 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_camera(t_game *game)
{
	game->camera.current.x = game->player.movement.current_position.x;
	game->camera.current.y = game->player.movement.current_position.y;
	game->camera.target.x = game->player.movement.current_position.x;
	game->camera.target.y = game->player.movement.current_position.y;
	game->camera.shake_intensity = 0.0;
	game->camera.shake_speed = 0.0;
	game->camera.lerp_speed = 0.01;
}

//make position offset ?
//missing t_point for life
//game->hud.direction.x = ;
//game->hud.direction.y = ;
// game->hud.position.life.x = 0x5;
// game->hud.position.life.y = 0x5;
void	ft_init_hud_sprites_position(t_game *game)
{
	game->hud.position.step.x = 0x5;
	game->hud.position.step.y = game->window.height - 150;
	game->hud.position.fps.x = 0x5;
	game->hud.position.fps.y = game->window.height - 100;
	game->hud.position.direction.x = 0x5;
	game->hud.position.direction.y = 320;
	game->hud.position.keys.x = 0x5;
	game->hud.position.keys.y = game->window.height - 200;
	game->hud.position.pause.x = 400;
	game->hud.position.pause.y = 400;
}

void	ft_init_fps(t_game *game)
{
	clock_gettime(1, &game->fps.current_time);
	game->fps.frame_count = 0x0;
	game->fps.fps = 0.0;
	game->fps.last_time = game->fps.current_time;
	game->fps.elapsed = 0.0;
}

void	ft_init_map_info(t_game *game, char *line)
{
	game->height = FALSE;
	game->width = ft_strlen(line) - TRUE;
	game->map.map_str = ft_custom_strdup(line);
	game->window.width = 0x0;
	game->window.height = 0x0;
	game->window.size_line = 0x0;
	game->window.bpp = 0x0;
	game->window.endian = 0x0;
	free(line);
}

void	ft_init_game_info(t_game *game)
{
	game->map.info.nbr_player = FALSE;
	game->map.info.nbr_key = FALSE;
	game->map.info.nbr_exit = FALSE;
	game->map.info.nbr_lava = FALSE;
	game->map.info.nbr_monster = FALSE;
	game->map.info.nbr_love = FALSE;
	game->map.info.nbr_wall = TRUE;
	game->map.info.nbr_pawn = FALSE;
	game->map.info.nbr_void = FALSE;
	game->map.info.nbr_box = FALSE;
	game->map.info.nbr_grass = FALSE;
	game->map.info.nbr_portal_1 = FALSE;
	game->map.info.nbr_portal_2 = FALSE;
	game->map.border_width = BORDERS_WIDTH;
}
