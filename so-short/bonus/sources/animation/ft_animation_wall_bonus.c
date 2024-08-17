/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_wall_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 04:35:34 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/17 04:46:44 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_east_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_south_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_no_neighbors_four_direction_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_south_plus_east_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_south_plus_west_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_plus_east_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_south_plus_west_plus_east_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_plus_south_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_plus_south_plus_east_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_plus_south_plus_west_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_plus_south_plus_west_plus_east_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_west_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_plus_west_plus_east_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_west_plus_east_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_north_west_animation(t_animation *animation)
{
	static int	 frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_wall_animation(t_game *game)
{
	ft_east_animation(&game->wall.east);
	ft_south_animation(&game->wall.south);
	ft_no_neighbors_four_direction_animation(&game->wall.no_neighbors_four_direction);
	ft_south_plus_east_animation(&game->wall.south_plus_east);
	ft_north_animation(&game->wall.north);
	ft_south_plus_west_animation(&game->wall.south_plus_west);
	ft_north_plus_east_animation(&game->wall.north_plus_east);
	ft_south_plus_west_plus_east_animation(&game->wall.south_plus_west_plus_east);
	ft_north_plus_south_animation(&game->wall.north_plus_south);
	ft_north_plus_south_plus_east_animation(&game->wall.north_plus_south_plus_east);
	ft_north_plus_south_plus_west_animation(&game->wall.north_plus_south_plus_west);
	ft_north_plus_south_plus_west_plus_east_animation(&game->wall.north_plus_south_plus_west_plus_east);
	ft_west_animation(&game->wall.west);
	ft_north_plus_west_plus_east_animation(&game->wall.north_plus_west_plus_east);
	ft_west_plus_east_animation(&game->wall.west_plus_east);
	ft_north_west_animation(&game->wall.north_west);
}
