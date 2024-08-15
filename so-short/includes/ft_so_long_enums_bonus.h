/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_enums_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:24:20 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 13:20:40 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_ENUMS_BONUS_H
# define FT_SO_LONG_ENUMS_BONUS_H

enum e_game_state
{
	STATE_MENU,
	STATE_PAUSED,
	STATE_PLAYING,
	STATE_WIN,
	STATE_LOSE
};

enum	e_key_code
{
	LINUX_CLOSE_ICON = 17,
	LINUX_ESC_KEY = 65307,
	LINUX_KEY_PRESS = 2,
	LINUX_KEY_RELEASE = 3,
	LINUX_W_KEY = 119,
	LINUX_A_KEY = 97,
	LINUX_S_KEY = 115,
	LINUX_D_KEY = 100,
	LINUX_UP_ARROW_KEY = 65362,
	LINUX_DOWN_ARROW_KEY = 65364,
	LINUX_LEFT_ARROW_KEY = 65361,
	LINUX_RIGHT_ARROW_KEY = 65363,
	LINUX_UP_PAV_NUM_KEY = 65431,
	LINUX_DOWN_PAV_NUM_KEY = 65433,
	LINUX_LEFT_PAV_NUM_KEY = 65430,
	LINUX_RIGHT_PAV_NUM_KEY = 65432
};

enum	e_map_char
{
	EXIT_CHAR = 'E',
	LOVE_CHAR = 'S',
	KEY_CHAR = 'C',
	PLAYER_CHAR = 'P',
	WALL_CHAR = '1',
	VOID_CHAR = '0',
	BOX_CHAR = 'B',
	PORTAL_1_CHAR = 'Z',
	PORTAL_2_CHAR = 'N',
	LAVA_CHAR = 'L',
	KEKE_CHAR = 'K',
	PAWN_CHAR = 'W',
	GRASS_CHAR = '#',
	TREE_CHAR = '@',
	TREES_CHAR = '$',
	REED_CHAR = '%',
	HUSKS_CHAR = '&',
	FUNGUS_CHAR = '?',
	FUNGI_CHAR = '!',
	FLOWER_CHAR = '+',
	ALGAE_CHAR = '*',
	WATER_CHAR = '=',
	VISITED_CHAR = 'V',
	CRAB_CHAR = '~',
	FOLIAGE_CHAR = '"',
	BOG_CHAR = '.',
	SNAIL_CHAR = ',',
	PILLAR_CHAR = '|',
	HEDGE_CHAR = '/',
};

enum	e_bool
{
	TRUE = 1,
	FALSE = 0
};

#endif // !FT_SO_LONG_ENUMS_BONUS_H
