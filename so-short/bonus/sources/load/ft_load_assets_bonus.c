/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:10:08 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/03 22:57:54 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_state_title(t_game *game)
{
	ft_load_sprite_frame(&(game->menu.game_welcome), game, \
		PATH_ASSET"menu/title/title.xpm",
		PATH_ASSET"menu/title/title.xpm");

	ft_load_sprite_frame(&(game->menu.game_win), game, \
		PATH_ASSET"menu/win/baba_win.xpm",
		PATH_ASSET"menu/win/baba_win.xpm");

	ft_load_sprite_frame(&(game->menu.game_over), game, \
		PATH_ASSET"menu/lose/baba_lose.xpm",
		PATH_ASSET"menu/lose/baba_lose.xpm");
}

void	ft_load_play_buttons_sprites(t_game *game)
{
	ft_load_sprite_frame(&(game->menu.start_button.img_normal), game, \
		PATH_ASSET"menu/play/play_the_game.xpm",
		PATH_ASSET"menu/play/play_the_game.xpm");
	ft_load_sprite_frame(&(game->menu.start_button.img_hover), game, \
		PATH_ASSET"menu/play/play_the_game_hover.xpm",
		PATH_ASSET"menu/play/play_the_game_hover.xpm");
	ft_load_sprite_frame(&(game->menu.start_button.img_clicked), game, \
		PATH_ASSET"menu/play/play_the_game_clicked.xpm",
		PATH_ASSET"menu/play/play_the_game_clicked.xpm");
}


void	ft_load_play_levels_buttons_sprites(t_game *game)
{
	ft_load_sprite_frame(&(game->menu.levels_button.img_normal), game, \
		PATH_ASSET"menu/levels/play_levels.xpm",
		PATH_ASSET"menu/levels/play_levels.xpm");
	ft_load_sprite_frame(&(game->menu.levels_button.img_hover), game, \
		PATH_ASSET"menu/levels/play_levels_hover.xpm",
		PATH_ASSET"menu/levels/play_levels_hover.xpm");
	// ft_load_sprite_frame(&(game->menu.levels_button.img_clicked), game,
	// 	PATH_ASSET"menu/levels/play_levels_clicked.xpm",
	// 	PATH_ASSET"menu/levels/play_levels_clicked.xpm");
}

void	ft_load_exit_buttons_sprites(t_game *game)
{
	ft_load_sprite_frame(&(game->menu.quit_button.img_normal), game, \
		PATH_ASSET"menu/exit/exit_the_game.xpm",
		PATH_ASSET"menu/exit/exit_the_game.xpm");
	ft_load_sprite_frame(&(game->menu.quit_button.img_hover), game, \
		PATH_ASSET"menu/exit/exit_the_game_hover.xpm",
		PATH_ASSET"menu/exit/exit_the_game_hover.xpm");
	ft_load_sprite_frame(&(game->menu.quit_button.img_clicked), game, \
		PATH_ASSET"menu/exit/exit_the_game_clicked.xpm",
		PATH_ASSET"menu/exit/exit_the_game_clicked.xpm");
}

void	ft_load_resume_buttons_sprites(t_game *game)
{
	ft_load_sprite_frame(&(game->menu.resume_button.img_normal), game, \
		PATH_ASSET"menu/resume/resume.xpm",
		PATH_ASSET"menu/resume/resume.xpm");
	ft_load_sprite_frame(&(game->menu.resume_button.img_hover), game, \
		PATH_ASSET"menu/resume/resume_hover.xpm",
		PATH_ASSET"menu/resume/resume_hover.xpm");
	ft_load_sprite_frame(&(game->menu.resume_button.img_clicked), game, \
		PATH_ASSET"menu/resume/resume_clicked.xpm",
		PATH_ASSET"menu/resume/resume_clicked.xpm");
}

void	ft_load_restart_buttons_sprites(t_game *game)
{
	ft_load_sprite_frame(&(game->menu.restart_button.img_normal), game, \
		PATH_ASSET"menu/restart/restart.xpm",
		PATH_ASSET"menu/restart/restart.xpm");
	ft_load_sprite_frame(&(game->menu.restart_button.img_hover), game, \
		PATH_ASSET"menu/restart/restart_hover.xpm",
		PATH_ASSET"menu/restart/restart_hover.xpm");
	ft_load_sprite_frame(&(game->menu.restart_button.img_clicked), game, \
		PATH_ASSET"menu/restart/restart_clicked.xpm",
		PATH_ASSET"menu/restart/restart_clicked.xpm");
}

void	ft_load_return_main_menu_buttons_sprites(t_game *game)
{
	ft_load_sprite_frame(&(game->menu.main_menu_button.img_normal), game, \
		PATH_ASSET"menu/main/return_to_main_menu.xpm",
		PATH_ASSET"menu/main/return_to_main_menu.xpm");
	ft_load_sprite_frame(&(game->menu.main_menu_button.img_hover), game, \
		PATH_ASSET"menu/main/return_to_main_menu_hover.xpm",
		PATH_ASSET"menu/main/return_to_main_menu_hover.xpm");
	ft_load_sprite_frame(&(game->menu.main_menu_button.img_clicked), game, \
		PATH_ASSET"menu/main/return_to_main_menu_clicked.xpm",
		PATH_ASSET"menu/main/return_to_main_menu_clicked.xpm");
}

// void	ft_init_menu_buttons_position(t_game *game)
// {
// 	game->menu.selected_button = 0x0;
// 	game->menu.start_button.position.x = 0x0;
// 	game->menu.start_button.position.y = 400;
// 	game->menu.start_button.width = 238;
// 	game->menu.start_button.height = 20;
// 	game->menu.start_button.is_hovered = 0;
// 	game->menu.levels_button.position.x = 300;
// 	game->menu.levels_button.position.y = 500;
// 	game->menu.levels_button.width = 238;
// 	game->menu.levels_button.height = 20;
// 	game->menu.levels_button.is_hovered = 0;
// 	game->menu.quit_button.position.x = 300;
// 	game->menu.quit_button.position.y = 600;
// 	game->menu.quit_button.width = 238;
// 	game->menu.quit_button.height = 20;
// 	game->menu.quit_button.is_hovered = 0;
// 	game->menu.resume_button.position.x = 300;
// 	game->menu.resume_button.position.y = 450;
// 	game->menu.resume_button.width = 238;
// 	game->menu.resume_button.height = 20;
// 	game->menu.resume_button.is_hovered = 0;
// 	game->menu.restart_button.position.x = 300;
// 	game->menu.restart_button.position.y = 500;
// 	game->menu.restart_button.width = 238;
// 	game->menu.restart_button.height = 20;
// 	game->menu.restart_button.is_hovered = 0;
// 	game->menu.main_menu_button.position.x = 300;
// 	game->menu.main_menu_button.position.y = 550;
// 	game->menu.main_menu_button.width = 238;
// 	game->menu.main_menu_button.height = 20;
// 	game->menu.main_menu_button.is_hovered = 0;
// }

void	ft_load_buttons_sprites(t_game *game)
{
	ft_load_play_buttons_sprites(game);
	ft_load_play_levels_buttons_sprites(game);
	ft_load_exit_buttons_sprites(game);
	ft_load_restart_buttons_sprites(game);
	ft_load_resume_buttons_sprites(game);
	ft_load_return_main_menu_buttons_sprites(game);



//return to main menu

	game->menu.selected_button = 0;
	// Start Button
	//game->menu.start_button.img_normal = mlx_xpm_file_to_image(game->mlx, PATH_ASSET"menu/play/play_the_game.xpm", &width, &height);
	//game->menu.start_button.img_hover = mlx_xpm_file_to_image(game->mlx, PATH_ASSET"menu/play/play_the_game_hover.xpm", &width, &height);
	//game->menu.start_button.img_clicked = mlx_xpm_file_to_image(game->mlx, PATH_ASSET"menu/play/play_the_game_clicked.xpm", &width, &height);
	game->menu.start_button.position.x = 0;//put that shit in init
	game->menu.start_button.position.y = 400;//put that shit in init
	game->menu.start_button.width = 238; //custom load ? that take the address of width
	game->menu.start_button.height = 20; //custom load ? that take the address of width
	game->menu.start_button.is_hovered = 0;
	// Levels Button
	//game->menu.levels_button.img_normal = mlx_xpm_file_to_image(game->mlx, PATH_ASSET"menu/levels/play_levels.xpm", &width, &height);
	//game->menu.levels_button.img_hover = mlx_xpm_file_to_image(game->mlx, PATH_ASSET"menu/levels/play_levels_hover.xpm", &width, &height);
	//game->menu.levels_button.img_clicked = mlx_xpm_file_to_image(game->mlx, PATH_ASSET"menu/levels/play_levels_clicked.xpm", &width, &height);
	game->menu.levels_button.position.x = 300;//put that shit in init
	game->menu.levels_button.position.y = 500;//put that shit in init
	game->menu.levels_button.width = 238; //custom load ? that take the address of width
	game->menu.levels_button.height = 20; //custom load ? that take the address of width
	game->menu.levels_button.is_hovered = 0;
	// Quit Button
	//game->menu.quit_button.img_normal = mlx_xpm_file_to_image(game->mlx, PATH_ASSET"menu/exit/exit_the_game.xpm", &width, &height);
	//game->menu.quit_button.img_hover = mlx_xpm_file_to_image(game->mlx, PATH_ASSET"menu/exit/exit_the_game_hover.xpm", &width, &height);
	//game->menu.quit_button.img_clicked = mlx_xpm_file_to_image(game->mlx, PATH_ASSET"menu/exit/exit_the_game_clicked.xpm", &width, &height);
	game->menu.quit_button.position.x = 300;//put that shit in init
	game->menu.quit_button.position.y = 600;//put that shit in init
	game->menu.quit_button.width = 238; //custom load ? that take the address of width
	game->menu.quit_button.height = 20; //custom load ? that take the address of width
	game->menu.quit_button.is_hovered = 0;
//start 0
//level 1
//resume;2
//restart 3
//mainmenu 4
//exit 5
	game->menu.resume_button.position.x = 300;//put that shit in init
	game->menu.resume_button.position.y = 450;//put that shit in init
	game->menu.resume_button.width = 238; //custom load ? that take the address of width
	game->menu.resume_button.height = 20; //custom load ? that take the address of width
	game->menu.resume_button.is_hovered = 0;

	game->menu.restart_button.position.x = 300;//put that shit in init
	game->menu.restart_button.position.y = 500;//put that shit in init
	game->menu.restart_button.width = 238; //custom load ? that take the address of width
	game->menu.restart_button.height = 20; //custom load ? that take the address of width
	game->menu.restart_button.is_hovered = 0;

	game->menu.main_menu_button.position.x = 300;//put that shit in init
	game->menu.main_menu_button.position.y = 550;//put that shit in init
	game->menu.main_menu_button.width = 238; //custom load ? that take the address of width
	game->menu.main_menu_button.height = 20; //custom load ? that take the address of width
	game->menu.main_menu_button.is_hovered = 0;
	//need to free by adding in node mistake was made at the start of the projet
}

void	ft_load_sprites(t_game *game)
{
	game->node = NULL;
	ft_load_state_title(game);
	ft_load_buttons_sprites(game);
	ft_load_enemies_sprites(game);
	ft_load_ground_sprites(game);
	ft_load_borders_sprite(game);
	ft_load_player_sprites(game);
	ft_load_monster_sprites(game);
	ft_load_gameplay_sprites(game);
	ft_load_digits_sprites(game);
	ft_load_box_sprites(game);
	ft_load_alphabet_sprites(game);
	ft_load_wall_bit_masking_sprites(game);
}

void	ft_add_sprite_to_list(t_game *game, void *frame)
{
	t_sprite_node	*new_node;

	new_node = (t_sprite_node *)malloc(sizeof(t_sprite_node));
	if (!new_node)
		ft_print_error("Add sprite to list fail", game);
	new_node->frame = frame;
	new_node->next = game->node;
	game->node = new_node;
}

void	ft_load_sprite_frame(void **frame, t_game *game, const char *path,
		const char *error_message)
{
	int	width;
	int	height;

	*frame = mlx_xpm_file_to_image(game->mlx, (char *)path, &width, &height);
	if (*frame == NULL)
		ft_print_error((char *)error_message, game);
	ft_add_sprite_to_list(game, *frame);
}

void	ft_load_animation_sprites(t_animation *animation, t_game *game,
		const char **paths, const char **error_messages)
{
	ft_load_sprite_frame(&(animation->frame_0), game, paths[0x0],
		error_messages[0x0]);
	ft_load_sprite_frame(&(animation->frame_1), game, paths[0x1],
		error_messages[0x1]);
	ft_load_sprite_frame(&(animation->frame_2), game, paths[0x2],
		error_messages[0x2]);
	animation->current = animation->frame_0;
	if (animation->current == NULL)
		ft_print_error((char *)error_messages[0x0], game);
}
