/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:10:08 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:22:10 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_buttons_sprites(t_game *game)
{
	ft_load_play_buttons_sprites(game);
	ft_load_play_levels_buttons_sprites(game);
	ft_load_exit_buttons_sprites(game);
	ft_load_restart_buttons_sprites(game);
	ft_load_resume_buttons_sprites(game);
	ft_load_return_main_menu_buttons_sprites(game);
	ft_init_buttons_is_hovered(game);
	ft_init_buttons_size(game);
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

//Macro
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
