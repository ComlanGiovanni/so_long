/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:11 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/03 22:34:20 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void ft_reset_grid(t_game *game)
{
    // Iterate through the map and reset collectibles
    for (int y = 0; y < game->map.size.y; y++)
    {
        for (int x = 0; x < game->map.size.x; x++)
			game->map.grid[y][x] = game->map.original[y][x];
    }
}

void ft_restart_game(t_game *game)
{
	//is it simple to free all and redo ? fo
	//for simplicity ? but that look very dumb
	system("pkill paplay > /dev/null 2>&1");
	ft_printf("\nRestart game %s\n", game->map.map_name);
	ft_free_pawns_array(game);
	ft_reset_grid(game);
	ft_init_fps(game);
	ft_init_player_info(game);
	ft_update_player_position(game);
	ft_dir_player_by_pos_exit_after_launch(game);
	ft_init_monster_info(game);
	ft_init_pawns_array(game);
	game->key_collected = 0;
	//ft_init_camera(game);
	//reset grid with original;
	//reset coin collectable
	//rest state ?
    // Reset move count
    // Reset life
	//what should i free ?
    game->state = STATE_PLAYING;
	ft_play_random_theme();
}

void ft_start_game(t_game *game)
{
	ft_restart_game(game);
}

void ft_play_levels(t_game *game)
{
    ft_printf("Levels selected %s\n", game->map.map_name);
	//ft_init_game(game, "tiny.ber");
	//mlx_loop_end(game->mlx);
	//ft_free_pawns_array(game);
	//ft_free_sprites_list(&game->node, game->mlx);
	//if (game->map.map_str)
		//free(game->map.map_str);
	//if (game->map.grid)
		//ft_clean_grid_map(game->map.grid, game->height);
	//if (game->map.original)
		//ft_clean_grid_map(game->map.original, game->height);
	//ft_free_mlx(game);
}

void ft_resume_game(t_game *game)
{
    ft_toggle_pause(game);
}

void ft_return_to_main_menu(t_game *game)
{
	system("pkill paplay > /dev/null 2>&1");
    game->state = STATE_MENU;
    // Implémentez ici la logique pour réinitialiser le jeu pour le menu principal
    // Par exemple : libérer les ressources du niveau actuel, réinitialiser les scores, etc.
}

void ft_menu_input_manager(t_game *game, int key_code)
{
    int num_buttons;
    void (*button_actions[4])(t_game *);

    if (game->state == STATE_MENU)
    {
        num_buttons = 3;
        button_actions[0] = ft_start_game;
        button_actions[1] = ft_play_levels;
        button_actions[2] = (void *)ft_exit_game;
    }
    else if (game->state == STATE_PAUSED)
    {
        num_buttons = 4;
        button_actions[0] = ft_resume_game;
        button_actions[1] = ft_restart_game;
        button_actions[2] = ft_return_to_main_menu;
        button_actions[3] = (void *)ft_exit_game;
		if (key_code == LINUX_LETTER_P)
		{
			ft_toggle_pause(game);
		}
	}
    else if (game->state == STATE_WIN || game->state == STATE_LOSE)
    {
        num_buttons = 3;
        button_actions[0] = ft_restart_game;
        button_actions[1] = ft_return_to_main_menu;
        button_actions[2] = (void *)ft_exit_game;
    }
    else
    {
        return; // Ne rien faire si ce n'est pas un état de menu
    }

    if (key_code == LINUX_UP_ARROW_KEY || key_code == LINUX_W_KEY)
    {
        game->menu.selected_button--;
        if (game->menu.selected_button < 0)
            game->menu.selected_button = num_buttons - 1;
    }
    else if (key_code == LINUX_DOWN_ARROW_KEY || key_code == LINUX_S_KEY)
    {
        game->menu.selected_button++;
        if (game->menu.selected_button >= num_buttons)
            game->menu.selected_button = 0;
    }
    else if (key_code == 65293)
    {
        if (game->menu.selected_button >= 0 && game->menu.selected_button < num_buttons)
            button_actions[game->menu.selected_button](game);
    }
	// else if (key_code == LINUX_LETTER_P)
	// 	ft_toggle_pause(game);
}

typedef struct s_key_map {
    int key_code;
    char konami_char;
} t_key_map;

void ft_activate_konami_code(t_game *game)
{
    ft_printf("Konami Code activé !%s\n", game->map.map_name);
    // Implémentez ici l'effet désiré du Konami code
}
char convert_key_to_char(int key_code)
{
    static const t_key_map key_mappings[] = {
        {LINUX_UP_ARROW_KEY, 'U'},
        {LINUX_W_KEY, 'U'},
        {LINUX_DOWN_ARROW_KEY, 'D'},
        {LINUX_S_KEY, 'D'},
        {LINUX_LEFT_ARROW_KEY, 'L'},
        {LINUX_A_KEY, 'L'},
        {LINUX_RIGHT_ARROW_KEY, 'R'},
        {LINUX_D_KEY, 'R'},
        {LINUX_A_KEY, 'B'},
        {LINUX_A_KEY, 'A'},
        {0, '\0'}  // Sentinelle pour marquer la fin du tableau
    };

    for (int i = 0; key_mappings[i].key_code != 0; i++)
    {
        if (key_code == key_mappings[i].key_code)
        {
            return key_mappings[i].konami_char;
        }
    }
    return '\0';  // Retourne le caractère nul si aucune correspondance n'est trouvée
}

void check_konami_code(t_game *game, char input)
{
    static const char *konami_code = "UUDDLRLRBA";
    static int konami_index = 0;

    if (input == konami_code[konami_index])
    {
        konami_index++;
        if (konami_index == ft_strlen((char *)konami_code))
        {
            ft_activate_konami_code(game);
            konami_index = 0;
        }
    }
    else
    {
        konami_index = 0;
    }
}

int ft_input_manager(int key_code, t_game *game)
{
    ft_exit_handler_helper(game, key_code);

	char konami_input = convert_key_to_char(key_code);
	ft_printf("%c", konami_input);
	if (konami_input != '\0')
    {
        check_konami_code(game, konami_input);
    }
    if (game->state == STATE_MENU || game->state == STATE_PAUSED ||
        game->state == STATE_WIN || game->state == STATE_LOSE)
    {
        ft_menu_input_manager(game, key_code);
    }
    else if (game->state == STATE_PLAYING)
    {
        if (key_code == LINUX_LETTER_P)
        {
            ft_toggle_pause(game);
        }
        else
        {
            ft_movement_input(game, key_code);
        }
    }
    return (EXIT_SUCCESS);
}

// void	ft_menu_input_manager(t_game *game, int key_code)
// {
//     // game->menu.start_button.is_hovered = 0;
//     // game->menu.levels_button.is_hovered = 0;
//     // game->menu.quit_button.is_hovered = 0;
// 	if (key_code == LINUX_UP_ARROW_KEY || key_code == LINUX_W_KEY) // Flèche Haut ou W
// 	{
// 		 game->menu.selected_button--;
// 		 if (game->menu.selected_button < 0)
// 			game->menu.selected_button = 2; // Remonter à "Quit" si on dépasse le début
// 		 ft_printf("|||%d|||||\n", game->menu.selected_button);
// 		// if (game->menu.selected_button == 0)
// 		// 	game->menu.start_button.is_hovered = 1;
// 	}
// 	else if (key_code == LINUX_DOWN_ARROW_KEY || key_code == LINUX_S_KEY) // Flèche Bas ou S
// 	{
// 		game->menu.selected_button++;
// 		if (game->menu.selected_button > 2)
// 			game->menu.selected_button = 0; // Revenir à "Start" si on dépasse la fin
// 		ft_printf("|||%d|||||\n", game->menu.selected_button);
// 	}
// 	else if (key_code == 65293) // Entrée/Retour
// 	{
// 		if (game->menu.selected_button == 0)
// 		{
// 			ft_printf("plllaaayyy\n");
// 			game->state = STATE_PLAYING;
// 		}
// 		else if (game->menu.selected_button == 1)
// 			ft_printf("Levels selected\n");
// 		else if (game->menu.selected_button == 2)
// 			ft_exit_game(game);
// 		ft_printf("|||%d|||||\n", game->menu.selected_button);
// 	}
// 	// else if (game->menu.selected_button == 1)
// 	// 	game->menu.levels_button.is_hovered = 1;
// 	// else if (game->menu.selected_button == 2)
// 	// 	game->menu.quit_button.is_hovered = 1;
// 	ft_printf("-[%d]-", key_code);
// }

// //recup key_code and put in game struct
// //make enumaration for input ?abcd
// int	ft_input_manager(int key_code, t_game *game)
// {
// 	if (game->state == STATE_MENU)
// 	{
// 		ft_exit_handler_helper(game, key_code);
// 		ft_menu_input_manager(game, key_code);
// 	}
// 	if (game->state == STATE_PLAYING)
// 	{
// 		if (key_code == LINUX_LETTER_P)
// 		{
// 			ft_toggle_pause(game);
// 			return (EXIT_SUCCESS);
// 		}
// 		if (game->state == STATE_PAUSED)
// 		{
// 			ft_exit_handler_helper(game, key_code);
// 			return (EXIT_SUCCESS);
// 		}
// 		ft_movement_input(game, key_code);
// 	}
// 	return (EXIT_SUCCESS);
// }

void	ft_movement_input(t_game *game, int key_code)
{
	if ((key_code == LINUX_W_KEY || key_code == LINUX_UP_ARROW_KEY
			|| key_code == LINUX_UP_PAV_NUM_KEY))
		ft_input_up(game);
	if ((key_code == LINUX_S_KEY || key_code == LINUX_DOWN_ARROW_KEY
			|| key_code == LINUX_DOWN_PAV_NUM_KEY))
		ft_input_down(game);
	if ((key_code == LINUX_A_KEY || key_code == LINUX_LEFT_ARROW_KEY
			|| key_code == LINUX_LEFT_PAV_NUM_KEY))
		ft_input_left(game);
	if ((key_code == LINUX_D_KEY || key_code == LINUX_RIGHT_ARROW_KEY
			|| key_code == LINUX_RIGHT_PAV_NUM_KEY))
		ft_input_right(game);
	ft_exit_handler_helper(game, key_code);
}

void	ft_move_player(t_game *game, int new_x, int new_y)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	next_tile = game->map.grid[new_y][new_x];
	if (next_tile == PAWN_CHAR)
		ft_deactivate_pawn_at_position(game, (t_point){new_x, new_y});
	ft_handle_box_movement(game, (t_point){new_x, new_y}, &next_tile);
	if (ft_handle_teleport(game, (t_point){new_x, new_y}, next_tile))
		return ;
	if (ft_play_can_move_to_tile(game, next_tile))
	{
		game->map.grid[y][x] = VOID_CHAR;
		game->map.grid[new_y][new_x] = PLAYER_CHAR;
		game->player.movement.current_position.x = new_x;
		game->player.movement.current_position.y = new_y;
		ft_play_movement_sound(game);
		ft_handle_tile_action(game, next_tile);
	}
}

void	ft_exit_handler_helper(t_game *game, int key_code)
{
	if (key_code == LINUX_ESC_KEY)
		ft_exit_game(game);
}

void	ft_toggle_pause(t_game *game)
{
	if (game->state == STATE_PAUSED)
	{
		//ft_play_random_theme();
		game->state = STATE_PLAYING;
	}
	else
	{
		game->state = STATE_PAUSED;
		//system("pkill paplay > /dev/null 2>&1");
	}
}
