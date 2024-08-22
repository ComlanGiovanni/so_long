/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:57:32 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 16:25:45 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_display_digits_sprites(t_game *game, char *digits_str,
		t_point position)
{
	void	*digit_images[0xa];
	int		index;

	index = 0x0;
	ft_init_digits_images(game, digit_images);
	while (digits_str[index] != '\0')
	{
		if (((digits_str[index] - '0') >= 0x0) \
			&& (digits_str[index] - '0') <= 0x9)
		{
			ft_display_transparent_image(game, \
				digit_images[(digits_str[index] - '0')], \
				(t_point){position.x, position.y}, \
				(t_img_size){ICON_SIZE, ICON_SIZE});
			position.x += 24;
		}
		index++;
	}
}

void	ft_display_string_sprites(t_game *game, char *alphabet_str, \
		t_point position)
{
	void	*letter_images[26];
	int		index;

	ft_init_even_letter_images(game, letter_images);
	ft_init_odd_letter_images(game, letter_images);
	index = 0x0;
	while (alphabet_str[index] != '\0')
	{
		if (alphabet_str[index] >= 'A' && alphabet_str[index] <= 'Z')
			ft_display_uppercase(game, alphabet_str[index], &position,
				letter_images);
		else if (alphabet_str[index] >= 'a' && alphabet_str[index] <= 'z')
			ft_display_lowercase(game, alphabet_str[index], &position,
				letter_images);
		index++;
	}
}

void	ft_display_uppercase(t_game *game, char character, t_point *position,
		void **letter_images)
{
	int	char_index;

	char_index = character - 'A';
	ft_display_transparent_image(game, letter_images[char_index], \
		(t_point){position->x, position->y}, \
			(t_img_size){ICON_SIZE, ICON_SIZE});
	position->x += ICON_SIZE;
}

void	ft_display_lowercase(t_game *game, char character, t_point *position,
		void **letter_images)
{
	int	char_index;

	char_index = character - 'a';
	ft_display_transparent_image(game, letter_images[char_index], \
		(t_point){position->x, position->y}, \
			(t_img_size){ICON_SIZE, ICON_SIZE});
	position->x += ICON_SIZE;
}

//t_point ?
void	ft_display_transparent_image(t_game *game, void *img_ptr, \
	t_point position, t_img_size img_size)
{
	t_img	img;
	int		x;
	int		y;
	int		color;

	ft_init_struct_img(img_ptr, &img, img_size);
	y = 0x0;
	while (y < img.height)
	{
		x = 0x0;
		while (x < img.width)
		{
			color = ft_get_pixel_color(&img, x, y);
			if ((color & 0xFF000000) != 0xFF000000)
				mlx_pixel_put(game->mlx, game->win, \
					position.x + x, position.y + y, color);
			x++;
		}
		y++;
	}
}
