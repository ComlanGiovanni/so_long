/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:52:44 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/12 15:59:09 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int argc, char *argv[])
{
	int	idx;

	idx = 0;

	t_game	*game;
	/*
	./so_long [pass to map][map name].ber
	*/
	if (argc != 2)
        return ;
	else
	{
		game = malloc(sizeof(t_game));
		ft_init_game(game, argv[1]);
		return (EXIT_SUCCESS);
	}
}

/*
mlx loop to call all the time
mlx string put for bonus
*/