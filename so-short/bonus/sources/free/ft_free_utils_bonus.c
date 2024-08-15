/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:34:26 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 01:38:15 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_free_pawns_array(t_game *game)
{
	if (game->pawn.pawns_array)
	{
		free(game->pawn.pawns_array);
		game->pawn.pawns_array = NULL;
	}
}

void	ft_free_sprites_list(t_sprite_node **head, void *mlx)
{
	t_sprite_node	*current;
	t_sprite_node	*next;

	current = *head;
	while (current)
	{
		if (current->frame)
		{
			mlx_destroy_image(mlx, current->frame);
			current->frame = NULL;
		}
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

void	ft_free_step_and_storage(t_game *game)
{
	if (game->hud.str_step != NULL)
		free(game->hud.str_step);
	if (game->hud.str_fps != NULL)
		free(game->hud.str_fps);
	if (game->hud.str_key_remain != NULL)
		free(game->hud.str_key_remain);
}
