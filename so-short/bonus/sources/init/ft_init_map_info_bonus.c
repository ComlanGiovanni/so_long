/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_info_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:32:36 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/19 19:33:50 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_get_info_map(t_game *game)
{
	int		idx;
	char	map_char;

	idx = 0x0;
	while (idx < game->map.len)
	{
		map_char = game->map.map_str[idx];
		ft_gameplay_map_info(&game->map.info, map_char);
		ft_enemies_map_info(&game->map.info, map_char);
		ft_border_map_info(&game->map.info, map_char);
		ft_increment_map_info(&game->map.info, map_char);
		idx++;
	}
}

void	ft_gameplay_map_info(t_info *info, char map_char)
{
	if (map_char == LOVE_CHAR)
		info->nbr_love++;
	else if (map_char == BOX_CHAR)
		info->nbr_box++;
	else if (map_char == PLAYER_CHAR)
		info->nbr_player++;
	else if (map_char == PORTAL_1_CHAR)
		info->nbr_portal_1++;
	else if (map_char == PORTAL_2_CHAR)
		info->nbr_portal_2++;
}

void	ft_enemies_map_info(t_info *info, char map_char)
{
	if (map_char == PAWN_CHAR)
		info->nbr_pawn++;
	else if (map_char == MONSTER_CHAR)
		info->nbr_monster++;
	else if (map_char == LAVA_CHAR)
		info->nbr_lava++;
}

// else if (map_char == WATER_CHAR)
//     info->nbr_water++;
// else if (map_char == BOG_CHAR)
//     info->nbr_bog++;
void	ft_border_map_info(t_info *info, char map_char)
{
	if (map_char == GRASS_CHAR)
		info->nbr_grass++;
}

void	ft_increment_map_info(t_info *info, char map_char)
{
	if (map_char == KEY_CHAR)
		info->nbr_key++;
	else if (map_char == EXIT_CHAR)
		info->nbr_exit++;
	else if (map_char == WALL_CHAR)
		info->nbr_wall++;
	else
		info->nbr_void++;
}
