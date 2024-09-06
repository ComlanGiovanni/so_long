/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:30:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:28:19 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_check_map(t_game *game)
{
	ft_check_valid_char(game);
	ft_check_rectangular(game);
	ft_check_sealed(game);
	ft_init_game_info(game);
	ft_get_info_map(game);
	ft_check_playability(game);
	ft_check_map_finishable(game);
}

void	ft_map_fit_screen(t_game *game)
{
	game->screen.x = 0x0;
	game->screen.y = 0x0;
	mlx_get_screen_size(game->mlx, &game->screen.x, &game->screen.y);
	if (game->map.size.x > 59 || game->map.size.y > 32)
		ft_print_error(MAP_TOO_BIG, game);
}

/**
 * @brief
 *
 * we get the len of the map and the extension
 * 	/path/to/map.ber  and .ber
 *
 * if we have less than .ber ex .be we found a bad extension
 * so we return SUCCESS			flemme de changer cest linverse....
 * then we get the cursor at *
 * 				 /path/to/map.ber
 * 			then we compare with .ber if there is not equal
 * 	we return SUCCESS because we found bad extenstion
 * 	   then inc the pointer of both
 *
 * @param map_name
 * @param extension
 * @return int
 */
int	ft_check_extension(char *map_name, char *extension)
{
	int	len_map_name;
	int	len_extension;

	len_map_name = ft_strlen(map_name);
	len_extension = ft_strlen(extension);
	if (len_map_name <= len_extension)
		return (EXIT_SUCCESS);
	map_name += len_map_name - len_extension;
	while (*map_name)
	{
		if (*map_name != *extension)
			return (EXIT_SUCCESS);
		map_name++;
		extension++;
	}
	return (EXIT_FAILURE);
}

void	ft_check_env(char **envp)
{
	int	idx;

	if (!*envp)
	{
		write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
		write(STDERR_FILENO, NO_ENV_ERROR, ft_strlen(NO_ENV_ERROR));
		exit(EXIT_FAILURE);
	}
	idx = FALSE;
	while (envp[idx])
	{
		if (ft_strncmp(DISPLAY, envp[idx], ft_strlen(DISPLAY)) == FALSE)
			return ;
		else
			idx++;
	}
	write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(STDERR_FILENO, NO_DISP_ERROR, ft_strlen(NO_DISP_ERROR));
	exit(EXIT_FAILURE);
}
