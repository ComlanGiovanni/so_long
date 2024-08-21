/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:29:36 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/21 22:31:42 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//ANIMATED LIFE ICON LOAD AND PALY ANIMATION
//ANIMATED LIFE ICON LOAD AND PALY ANIMATION
//ANIMATED LIFE ICON LOAD AND PALY ANIMATION
//ANIMATED LIFE ICON LOAD AND PALY ANIMATION
//ANIMATED LIFE ICON LOAD AND PALY ANIMATION

void	ft_init_struct_img(void *img_ptr, t_img *img, t_img_size img_size)
{
	img->data = mlx_get_data_addr(img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	img->width = img_size.width;
	img->height = img_size.height;
}

int	ft_get_pixel_color(t_img *img, int x, int y)//t_point
{
	int		bpp;
	char	*pixel;

	if ((x < 0x0) || (x >= img->width) || (y < 0x0) || (y >= img->height))
		return (0x0);
	bpp = img->bpp / 0x8;
	pixel = (img->data + ((y * img->size_line) + (x * bpp)));
	return (*(int *)pixel);
}

static void	ft_display_direction_string(t_game *game)
{
	char	*direction;
	t_point	direction_pos;

	direction_pos.x = 0x5;
	direction_pos.y = game->window.height - 50;//t_point in game hud struct
	direction = NULL;
	if (game->player.movement.direction == 'u')
		direction = UP_DIRECTION;
	else if (game->player.movement.direction == 'd')
		direction = DOW_DIRECTION;
	else if (game->player.movement.direction == 'l')
		direction = LEFT_DIRECTION;
	else if (game->player.movement.direction == 'r')
		direction = RIGHT_DIRECTION;
	ft_display_string_sprites(game, direction, direction_pos);
}

/**
 * @brief
 *
 * 	we display a itoa o step storage on the win and free it the end
 * 	we print all info in color define in the define header
 * 	we can make a fct for the print of up down life right but iam lazy
 * 	so in fct of the char in game->player.direction we print the
 * 	full word in color
 *
 * //mlx_string_put(game->mlx, game->win, 5, game->height - 10,
 * //YELLOW, "Press [Esc]-key to Rage-Quit");
 *
	//game->hud.str_storage = ft_itoa(game->player.storage);

	mlx_string_put(game->mlx, game->win, game->hud.fps.x + 80, game->hud.fps.y,
			RED, "//");
 *
 * @param game
 */
void	ft_print_info_on_window(t_game *game)
{
	game->hud.str_step = ft_itoa(game->player.step);
	game->hud.str_fps = ft_itoa(game->fps.fps);
	game->hud.str_key_remain = ft_itoa(game->map.info.nbr_key
			- game->player.storage);
	ft_display_life_on_windows(game);
	ft_display_string_sprites(game, STEP_INDICATOR, game->hud.step);
	ft_display_digits_sprites(game, game->hud.str_step,
			(t_point){game->hud.step.x + 130, game->hud.step.y});//t_point in game hud struct
	ft_display_string_sprites(game, FPS_INDICATOR, game->hud.fps);
	ft_display_digits_sprites(game, game->hud.str_fps, (t_point){game->hud.fps.x
			+ 100, game->hud.fps.y});//t_point in game hud struct
	ft_display_string_sprites(game, KEYS_INDICATOR, game->hud.keys);
	ft_display_digits_sprites(game, game->hud.str_key_remain,
			(t_point){game->hud.keys.x + 130, game->hud.keys.y});//t_point in game hud struct
	ft_display_direction_string(game);
	ft_free_step_and_storage(game);
}

/**
 * @brief
 *
 * 	this fct simply display the number of life of the player
 * 		whe loop by the life.player.map, and print the small love.icon
 * 				10x10 at the x y and we also reset
 * 			the x position to 0 to print at the next line y
 *
 * is not great display because for 100 life we dont manage to print all
 * 		for DLC we can stack every heath
 *
 * 	//t_point for less line put in struct
 * //regarde pour la tranparance lalpha
 * @param game
 */
void	ft_display_life_on_windows(t_game *game)
{
	int	idx;
	int	icons_per_row;
	int	icon_spacing;
	int x; //t_point in struct
	int y; //t_point in struct
	idx = 0x0;
	x = 0x5;
	y = 0x5;
	icons_per_row = 0x3;
	icon_spacing = 0x5;

	while (idx < game->player.life && idx < 500)
	{
		ft_display_transparent_image(game, game->love.icon, (t_point){x, y},
				(t_img_size){32, 32});
		idx++;
		if ((idx % icons_per_row) == 0x0)
		{
			x = 0x5;
			y += 32 + icon_spacing;
		}
		else
			x += 32 + icon_spacing;
	}
}
