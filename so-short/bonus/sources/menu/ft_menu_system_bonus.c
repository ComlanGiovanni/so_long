/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_system_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:10:12 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/28 12:36:00 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// typedef struct s_button
// {
// 	void	*img_normal;
// 	void	*img_hover;
// 	void	*img_clicked;
// 	int		x;
// 	int		y;
// 	int		width;
// 	int		height;
// 	int		is_hovered;
// }			t_button;

//     // t_button start_button;
//     // t_button other_option_button;
//     // t_button quit_button;
//     // int selected_button; // 0: Start, 1: Other Option, 2: Quit


// game->selected_button = 0;

// int	ft_key_manager(int keycode, t_game *game)
// {
//     if (game->state == MENU_MAIN)
//     {
//         if (keycode == 126 || keycode == 13)
//         {
//             game->selected_button--;
//             if (game->selected_button < 0)
//                 game->selected_button = 2;
//         }
//         else if (keycode == 125 || keycode == 1)
//         {
//             game->selected_button++;
//             if (game->selected_button > 2)
//                 game->selected_button = 0;
//         }
//         else if (keycode == 36) // Entrée/Retour
//         {
//             if (game->selected_button == 0)
//                 game->state = GAME_RUNNING;
//             else if (game->selected_button == 1)
//                 ft_printf("Other option selected\n");
//             else if (game->selected_button == 2)
//                 ft_exit_game(game);
//         }
//     }
//     return (0);
// }

// void	ft_check_mouse_hover(t_game *game, int x, int y)
// {
//     t_button *buttons[] = { &game->start_button, &game->other_option_button, &game->quit_button };
//     int num_buttons = 3;

//     for (int i = 0; i < num_buttons; i++)
//     {
//         t_button *button = buttons[i];
//         if (x >= button->x && x <= button->x + button->width &&
//             y >= button->y && y <= button->y + button->height)
//         {
//             button->is_hovered = 1;
//             game->selected_button = i;
//         }
//         else
//         {
//             button->is_hovered = 0;
//         }
//     }
// }



// void	ft_draw_button(t_game *game, t_button *button)
// {
//     if (button->is_hovered)
//         mlx_put_image_to_window(game->mlx, game->win, button->img_hover, button->x, button->y);
//     else
//         mlx_put_image_to_window(game->mlx, game->win, button->img_normal, button->x, button->y);
// }

// void	ft_init_buttons(t_game *game)
// {
//     int width, height;

//     // Start Button
//     game->start_button.img_normal = mlx_xpm_file_to_image(game->mlx, "path/to/start_button.xpm", &width, &height);
//     game->start_button.img_hover = mlx_xpm_file_to_image(game->mlx, "path/to/start_button_hover.xpm", &width, &height);
//     game->start_button.x = 300;
//     game->start_button.y = 100;
//     game->start_button.width = width;
//     game->start_button.height = height;
//     game->start_button.is_hovered = 0;

//     // Other Option Button
//     game->other_option_button.img_normal = mlx_xpm_file_to_image(game->mlx, "path/to/other_option_button.xpm", &width, &height);
//     game->other_option_button.img_hover = mlx_xpm_file_to_image(game->mlx, "path/to/other_option_button_hover.xpm", &width, &height);
//     game->other_option_button.x = 300;
//     game->other_option_button.y = 200;
//     game->other_option_button.width = width;
//     game->other_option_button.height = height;
//     game->other_option_button.is_hovered = 0;

//     // Quit Button
//     game->quit_button.img_normal = mlx_xpm_file_to_image(game->mlx, "path/to/quit_button.xpm", &width, &height);
//     game->quit_button.img_hover = mlx_xpm_file_to_image(game->mlx, "path/to/quit_button_hover.xpm", &width, &height);
//     game->quit_button.x = 300;
//     game->quit_button.y = 300;
//     game->quit_button.width = width;
//     game->quit_button.height = height;
//     game->quit_button.is_hovered = 0;
// }


// void	ft_draw_main_menu(t_game *game)
// {
//     ft_draw_button(game, &game->start_button);
//     ft_draw_button(game, &game->other_option_button);
//     ft_draw_button(game, &game->quit_button);
// }

