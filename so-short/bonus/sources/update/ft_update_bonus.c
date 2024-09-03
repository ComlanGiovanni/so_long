/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:02:13 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/03 21:13:18 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//make a fct to return the good usleep in fonction of the limitation
//fps limiation usleep(game->fps.limitation); usleep(15000);

void	ft_draw_button(t_game *game, t_button *button)
{
	if (button->is_hovered)//replace or put ??
		mlx_put_image_to_window(game->mlx, game->win, button->img_hover, \
			button->position.x, button->position.y);
	else
		mlx_put_image_to_window(game->mlx, game->win, button->img_normal, \
			button->position.x, button->position.y);
}

void	ft_draw_main_menu(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->menu.game_welcome, ((game->window.width / 2) - 290), 5);
	ft_draw_button(game, &game->menu.start_button);
	ft_draw_button(game, &game->menu.levels_button);
	ft_draw_button(game, &game->menu.quit_button);
}

void	ft_draw_pause_menu(t_game *game)
{
	ft_draw_button(game, &game->menu.resume_button);
	ft_draw_button(game, &game->menu.restart_button);
	ft_draw_button(game, &game->menu.main_menu_button);
	ft_draw_button(game, &game->menu.quit_button);
}

static void ft_handle_button_click(t_game *game, int button_index)
{
    if (game->state == STATE_MENU)
    {
		system("pkill paplay > /dev/null 2>&1");
        if (button_index == 0)
        {
			//ft_start_game(game);
            game->state = STATE_PLAYING;
			ft_play_random_theme();
        }
        else if (button_index == 1)
            ft_printf("Levels button clicked\n");
        else if (button_index == 2)
            ft_exit_game(game);
    }
    else if (game->state == STATE_PAUSED)
    {
        if (button_index == 0)
            game->state = STATE_PLAYING;//ft_start_game(game);
        else if (button_index == 1)
             ft_printf("ft_restart_game(game);\n");//ft_restart_game(game);;
        else if (button_index == 2)
		{
            game->state = STATE_MENU;//make fonction like ft_start_game etc
		}
		else if (button_index == 3)
            ft_exit_game(game);
    }
    else if (game->state == STATE_WIN || game->state == STATE_LOSE)
    {
        if (button_index == 0)
            ft_printf("ft_restart_game(game);\n");//ft_restart_game(game);
        else if (button_index == 1)
		{
            game->state = STATE_MENU;
		}
		else if (button_index == 2)
            ft_exit_game(game);
    }
}

static int ft_is_mouse_over_button(t_button *button, int x, int y)
{
    return (x >= button->position.x && x <= button->position.x + button->width
        && y >= button->position.y && y <= button->position.y + button->height);
}

void ft_check_mouse_hover(t_game *game)
{
    t_button *buttons[4];
    int num_buttons;

    if (game->state == STATE_MENU)
    {
        buttons[0] = &game->menu.start_button;
        buttons[1] = &game->menu.levels_button;
        buttons[2] = &game->menu.quit_button;
        num_buttons = 3;
    }
    else if (game->state == STATE_PAUSED)
    {
        buttons[0] = &game->menu.resume_button;
        buttons[1] = &game->menu.restart_button;
        buttons[2] = &game->menu.main_menu_button;
        buttons[3] = &game->menu.quit_button;
        num_buttons = 4;
    }
    else if (game->state == STATE_WIN || game->state == STATE_LOSE)
    {
        buttons[0] = &game->menu.restart_button;
        buttons[1] = &game->menu.main_menu_button;
        buttons[2] = &game->menu.quit_button;
        num_buttons = 3;
    }
    else
    {
        return; // No buttons to check in other states
    }
    for (int i = 0; i < num_buttons; i++)
    {
        if (ft_is_mouse_over_button(buttons[i], game->mouse.mouse_position.x, game->mouse.mouse_position.y))
        {
            game->menu.selected_button = i;
            if (ft_strcmp(game->mouse.button_name, MOUSE_LEFT_CLICK) == 0)
            {
                game->mouse.button_name = "";
                ft_handle_button_click(game, i);
            }
            break;
        }
    }
}

/*wdwdwq
loop like this can be a one fonction and different display by the state
*/

void	ft_draw_win_menu(t_game *game)
{
	//draw  win image
	mlx_put_image_to_window(game->mlx, game->win, \
		game->menu.game_win, ((game->window.width / 2) - 300), 50);
	ft_draw_button(game, &game->menu.restart_button);
	ft_draw_button(game, &game->menu.main_menu_button);
	ft_draw_button(game, &game->menu.quit_button);
}

void	ft_draw_game_over_menu(t_game *game)
{
	//draw gameover image
	mlx_put_image_to_window(game->mlx, game->win, \
		game->menu.game_over, ((game->window.width / 2) - 298), 50);
	ft_draw_button(game, &game->menu.restart_button);
	ft_draw_button(game, &game->menu.main_menu_button);
	ft_draw_button(game, &game->menu.quit_button);
}

static void ft_update_menu_state(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	ft_draw_main_menu(game);
	game->menu.start_button.is_hovered = (game->menu.selected_button == 0x0);
	game->menu.levels_button.is_hovered = (game->menu.selected_button == 0x1);
	game->menu.quit_button.is_hovered = (game->menu.selected_button == 0x2);
}

static void ft_update_pause_state(t_game *game)
{
	ft_draw_pause_message(game);
	ft_draw_pause_menu(game);//put it int ft_draw_pause_message
	game->menu.resume_button.is_hovered = (game->menu.selected_button == 0x0);
	game->menu.restart_button.is_hovered = (game->menu.selected_button == 0x1);
	game->menu.main_menu_button.is_hovered = (game->menu.selected_button == 0x2);
	game->menu.quit_button.is_hovered = (game->menu.selected_button == 0x3);
}


static void ft_update_playing_state(t_game *game)
{
	ft_update_fps(game);
	ft_update_camera(game);
	ft_play_animation(game);
	ft_check_coin_collected(game);
	mlx_clear_window(game->mlx, game->win);
	ft_put_sprites_by_line(game);
	ft_print_info_on_window(game);
	if (game->player.life <= 0x0)
	{
		game->state = STATE_LOSE;
		ft_lose_game(game);
	}
}

static void ft_update_win_lose_state(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	if (game->state == STATE_WIN)
		ft_draw_win_menu(game);//ft_win_game(game);
	else if (game->state == STATE_LOSE)
		ft_draw_game_over_menu(game);//ft_win_game(game);
	game->menu.restart_button.is_hovered = (game->menu.selected_button == 0x0);
	game->menu.main_menu_button.is_hovered = (game->menu.selected_button == 0x1);
	game->menu.quit_button.is_hovered = (game->menu.selected_button == 0x2);
}

int ft_update(t_game *game)
{
	mlx_mouse_get_pos(game->mlx, game->win, &game->mouse.mouse_position.x,
		&game->mouse.mouse_position.y);
	ft_check_mouse_hover(game);
	if (game->state == STATE_MENU)
		ft_update_menu_state(game);
	else if (game->state == STATE_PAUSED)
		ft_update_pause_state(game);
	else if (game->state == STATE_PLAYING)
		ft_update_playing_state(game);
	else if (game->state == STATE_WIN || game->state == STATE_LOSE)
		ft_update_win_lose_state(game);
	return (EXIT_SUCCESS);
}

//this shit is dirty time managment bad and movement in update fps
void	ft_update_fps(t_game *game)
{
	clock_gettime(1, &game->fps.current_time);
	game->fps.elapsed = (game->fps.current_time.tv_sec - \
		game->fps.last_time.tv_sec) + \
		(game->fps.current_time.tv_nsec - game->fps.last_time.tv_nsec) / 1e9;
	game->fps.elapsed_time = (game->fps.current_time.tv_sec - \
		game->fps.last_time.tv_sec) + \
		(game->fps.current_time.tv_nsec - game->fps.last_time.tv_nsec) / 1e9;
	game->fps.frame_count++;
	if (game->fps.elapsed >= 1.0)
	{
		game->fps.fps = game->fps.frame_count / game->fps.elapsed;
		game->fps.frame_count = 0x0;
		game->fps.last_time = game->fps.current_time;
	}
	if (game->map.info.nbr_pawn && game->fps.elapsed_time >= 1.0)
	{
		if (game->fps.last_time.tv_sec % 0x2)
			system("paplay sounds/special-effects/clock_tic.wav \
			> /dev/null 2>&1 &");
		else
			system("paplay sounds/special-effects/clock_tac.wav \
			> /dev/null 2>&1 &");
		ft_move_pawn(game);
		if (game->map.info.nbr_monster)
			ft_a_star_monster_movement(game);
	}
}
