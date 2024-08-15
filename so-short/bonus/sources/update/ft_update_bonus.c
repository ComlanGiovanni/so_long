/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:02:13 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 13:00:27 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//make a fct to return the good usleep in fonction of the limitation
//fps limiation usleep(game->fps.limitation); usleep(15000);

void	ft_display_string_sprites(t_game *game, char *alphabet_str,
		t_point position);

void	ft_draw_pause_message(t_game *game)
{
	if (game->state == STATE_PAUSED)
	{
		ft_display_string_sprites(game, "PAUSE", (t_point){400, 400});
		//mlx_string_put(game->mlx, game->win, 300, 200, 0xFFFFFF, "PAUSED");
	}
}

int	ft_update(t_game *game)
{
	if (game->state == STATE_PAUSED)
	{
		ft_draw_pause_message(game);
		return (EXIT_SUCCESS); // Do nothing if the game is paused
	}
	if (game->player.life <= 0)
		game->state = STATE_LOSE;
	if (game->state == STATE_PLAYING)
	{
		ft_update_fps(game);
		ft_update_camera(game);
		ft_play_animation(game);
		if ((game->map.info.nbr_key == game->player.storage) && !game->key_collected)
		{
			game->key_collected = 1;
			system("aplay sounds/theme/all_key_collected.wav > /dev/null 2>&1 &");
		}
		mlx_clear_window(game->mlx, game->win);
		ft_put_sprites_by_line(game);
		//mlx_do_sync(game->mlx);
		ft_print_info_on_window(game);
	}
	//system("clear");
	//ft_print_display_grid(game->map.grid);
	if (game->state == STATE_WIN)
		ft_win_game(game);//ft_draw_win_menu(game);
	else if (game->state == STATE_LOSE)
		ft_lose_game(game);//ft_draw_lose_menu(game);
	return (EXIT_SUCCESS);
}

void	ft_update_fps(t_game *game)
{
	clock_gettime(1, &game->fps.current_time);
	game->fps.elapsed = (game->fps.current_time.tv_sec
			- game->fps.last_time.tv_sec) +
		(game->fps.current_time.tv_nsec - game->fps.last_time.tv_nsec) / 1e9;
	game->fps.elapsed_time = (game->fps.current_time.tv_sec
			- game->fps.last_time.tv_sec) +
		(game->fps.current_time.tv_nsec - game->fps.last_time.tv_nsec) / 1e9;
	game->fps.frame_count++;
	if (game->fps.elapsed >= 1.0)
	{
		game->fps.fps = game->fps.frame_count / game->fps.elapsed;
		game->fps.frame_count = 0;
		game->fps.last_time = game->fps.current_time;
	}
	if (game->map.info.nbr_pawn && game->fps.elapsed_time >= 1.0) {
            // Perform the desired action
            //printf("One second has passed!\n");
			// srand((unsigned int)time(NULL));
			// int tic_or_tac = rand() % 2;
			if (game->fps.last_time.tv_sec % 2)
				system("aplay sounds/special-effects/clock_tic.wav > /dev/null 2>&1 &");
			else
				system("aplay sounds/special-effects/clock_tac.wav > /dev/null 2>&1 &");
			ft_move_pawn(game);
        }
}

void	ft_update_map_matrice(t_game *game)
{
	if (game->map.matrice != NULL)
		ft_clean_grid_map(game->map.matrice, game->height);
	game->map.matrice = ft_split_map(game);
}

void	ft_update_player_position(t_game *game)
{
	game->player.movement.current_position.x = game->map.start.x;
	game->player.movement.current_position.y = game->map.start.y;
}

// t_point	ft_find_pos_char_in_new_grid(char **tab, t_point size, char c)
// {
// 	int	x;
// 	int	y;

// 	if (!tab || size.x <= 0 || size.y <= 0)
// 		return ((t_point){-1, -1});
// 	y = 0;
// 	while (y < size.y)
// 	{
// 		if (tab[y] == NULL)
// 			return ((t_point){-1, -1});
// 		x = 0;
// 		while (x < size.x)
// 		{
// 			if (tab[y][x] == '\0')
// 				break ;
// 			if (tab[y][x] == c)
// 				return ((t_point){x, y});
// 			x++;
// 		}
// 		y++;
// 	}
// 	return ((t_point){-1, -1});
// }

void	ft_update_map_positions(t_game *game)
{
	game->map.start = ft_find_pos_char(game->map.grid, game->map.size,
			PLAYER_CHAR);
	game->map.end = ft_find_pos_char(game->map.grid, game->map.size, EXIT_CHAR);
	game->map.portal_1_pos = ft_find_pos_char(game->map.grid, game->map.size,
			PORTAL_1_CHAR);
	game->map.portal_2_pos = ft_find_pos_char(game->map.grid, game->map.size,
			PORTAL_2_CHAR);
	if ((game->map.start.x == -1 && game->map.start.y == -1)
		|| (game->map.end.x == -1 && game->map.end.y == -1))
		ft_free_and_print(game->map.matrice, game, NO_POSITION_FOUND);
}

//add in t_game struct info if you want
//   ft_find_edge_wall_position(&game);
// t_point top_left;
// t_point top_right;
// t_point bottom_left;
// t_point bottom_right;

// void find_corner(t_game *game, t_point *corner, int x_start, int y_start, int x_dir, int y_dir) {
//     int x = x_start;
//     int y = y_start;

//     while (y >= 0 && y < game->map.size.y) {
//         x = x_start;
//         while (x >= 0 && x < game->map.size.x) {
//             if (game->map.grid[y][x] == '1') {
//                 corner->x = x;
//                 corner->y = y;
//                 return;
//             }
//             x += x_dir;
//         }
//         y += y_dir;
//     }
// }

// void ft_find_edge_wall_position(t_game *game) {
//     game->top_left = (t_point){-1, -1};
//     game->top_right = (t_point){-1, -1};
//     game->bottom_left = (t_point){-1, -1};
//     game->bottom_right = (t_point){-1, -1};

//     find_corner(game, &game->top_left, 0, 0, 1, 1);
//     find_corner(game, &game->top_right, game->map.size.x - 1, 0, -1, 1);
//     find_corner(game, &game->bottom_left, 0, game->map.size.y - 1, 1, -1);
//     find_corner(game, &game->bottom_right, game->map.size.x - 1, game->map.size.y - 1, -1, -1);
// }
