/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:14:51 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 01:20:35 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

/**
 * @brief
 *
 * If the error value is >= 1
 * 	print Error in standard error
 * else 0 -1 etc
 * 	just exit the code
 *
 * EXIT_SUCCESS = 0
 * EXIT_FAILURE = 1;
 *
 * STDIN_FILENO    Standard input value, stdin. Its value is 0.
 * STDOUT_FILENO   Standard output value, stdout. Its value is 1.
 * STDERR_FILENO   Standard error value, stderr. Its value is 2.
 *
 * @param error_code
 * @return int
 */
void	ft_print_error(char *error_msg, t_game *game)
{
	ft_free_all(game);
	ft_printf("%s%s", ERROR_MSG, error_msg);
	exit(EXIT_FAILURE);
}

void	ft_print_no_arg(void)
{
	ft_printf("%s%s", ERROR_MSG, USAGE_MSG);
	exit(EXIT_FAILURE);
}

void	ft_free_and_print(char **map, t_game *game, char *str)
{
	ft_clean_grid_map(map, game->height);
	ft_print_error(str, game);
}

void	ft_print_error_empty_and_free(char *error_msg, t_game *game)
{
	ft_free_sprites_list(&game->node, game->mlx);
	ft_free_mlx(game);
	ft_printf("%s%s", ERROR_MSG, error_msg);
	exit(EXIT_FAILURE);
}
