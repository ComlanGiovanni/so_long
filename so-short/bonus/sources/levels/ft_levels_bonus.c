/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_levels_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:46:23 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/28 12:39:21 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_so_long_bonus.h"

// typedef struct s_levels {
//     char **map_names;
//     int current_level;
//     int total_levels;
// 	t_game	game;
// } t_levels;

// typedef struct s_game {
//     // ... autres membres existants ...
//     t_levels levels;
// } t_game;

// void ft_init_levels(t_game *game, int num_levels, char **level_names)
// {
//     int i;

//     game->levels.total_levels = num_levels;
//     game->levels.current_level = 0;
//     game->levels.map_names = ft_calloc(num_levels, sizeof(char *));

//     for (i = 0; i < num_levels; i++)
//     {
//         game->levels.map_names[i] = ft_strdup(level_names[i]);
//     }
// }

// void ft_init_game(t_game *game, char *map_name)
// {
//     ft_check_map_argument(game, map_name);
//     game->state = STATE_PLAYING;
//     // ... reste du code ...
// }

// void ft_next_level(t_game *game)
// {
//     game->levels.current_level++;
//     if (game->levels.current_level < game->levels.total_levels)
//     {
//         ft_cleanup_current_level(game);
//         ft_init_game(game, game->levels.map_names[game->levels.current_level]);
//     }
//     else
//     {
//         game->state = STATE_WIN;
//         // Afficher un message de victoire finale
//     }
// }
