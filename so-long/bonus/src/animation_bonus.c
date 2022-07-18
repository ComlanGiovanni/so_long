/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:24:45 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/18 13:58:56 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	ft_render(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	//mlx_put_image_to_window(game->mlx, game->win, game->sprite.wall, 64,  64);
	ft_put_sprites_by_line(game);
	//mlx_destroy_image(game->mlx, game->sprite.wall);
}


void	ft_wall_animation(t_sprites *sprite)
{
    static int	frame;
	if (sprite->wall_frames == 0)
		return ;
	if (frame == sprite->wall_frames)
	{
		sprite->wall = sprite->wall_0;
	}
	else if (frame >= sprite->wall_frames * 2)
	{
		sprite->wall = sprite->wall_1;
		frame = 0;
	}
	frame += 1;
}


void	ft_player_animation(t_sprites *sprite)
{
    static int	frame;
	if (sprite->player_frames == 0)
		return ;
	if (frame == sprite->player_frames)
	{
		sprite->player_up = sprite->player_up_frame_0;
		sprite->player_down = sprite->player_down_frame_0;
		sprite->player_left = sprite->player_left_frame_0;
		sprite->player_right = sprite->player_right_frame_0;
	}
	else if (frame >= sprite->player_frames * 2)
	{
		sprite->player_up = sprite->player_up_frame_1;
		sprite->player_down = sprite->player_down_frame_1;
		sprite->player_left = sprite->player_left_frame_1;
		sprite->player_right = sprite->player_right_frame_1;
		frame = 0;
	}
	frame += 1;
}


int	ft_update(t_game *game)
{
    //printf("ici\n");
	ft_wall_animation(&game->sprite);
	ft_player_animation(&game->sprite);
	ft_render(game);
	return (1);
}