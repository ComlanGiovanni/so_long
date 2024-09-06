/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_buttons_assets_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:15:28 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:24:15 by gicomlan         ###   ########.fr       */
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

// ft_load_sprite_frame(&(game->menu.levels_button.img_clicked), game,
// 	PATH_ASSET"menu/levels/play_levels_clicked.xpm",
// 	PATH_ASSET"menu/levels/play_levels_clicked.xpm");
void	ft_load_play_levels_buttons_sprites(t_game *game)
{
	ft_load_sprite_frame(&(game->menu.levels_button.img_normal), game, \
		PATH_ASSET"menu/levels/play_levels.xpm",
		PATH_ASSET"menu/levels/play_levels.xpm");
	ft_load_sprite_frame(&(game->menu.levels_button.img_hover), game, \
		PATH_ASSET"menu/levels/play_levels_hover.xpm",
		PATH_ASSET"menu/levels/play_levels_hover.xpm");
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
