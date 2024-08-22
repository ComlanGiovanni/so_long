/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:12:49 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/22 15:09:59 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

/**
 * @brief
 *
 * 		Gamers can feel when developers are passionate about their games.
 * 				They can s
 * smell it like a dog smells fear.
 * 			Don't be afraid to hold onto your unique vision:
 * 		Just be aware that it may not turn out exactly how you envisioned.
 *
 * 							-[Scott Rogers]-
 *  		> norminette bonus_* inc_* src_* lib main_*
 *
 * @param argc
 * @param argv
 * @param envp
 * @return int
 */
int	main(int argc, char *argv[], char **envp)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		ft_print_no_arg();
	else
	{
		ft_check_env(envp);
		game = ft_calloc(sizeof(t_game), sizeof(t_game));
		if (game == NULL)
			ft_print_error(MALLOC_GAME_ERROR, game);
		ft_init_game(game, argv[1]);
		ft_mlx_hook_loop(game);
	}
	return (EXIT_SUCCESS);
}
/*

make re bonus && valgrind --leak-check=full
--show-leak-kinds=all --track-fds=yes --show-reachable=yes
--track-origins=yes ./so_long_bonus maps/Level\ Design\ Bonus/level_0.ber 2>&1
| tee valgrind.log

https://audiotrimmer.com/
https://encycolorpedia.fr/619ad2
https://rtouti.github.io/graphics/perlin-noise-algorithm
https://www.vertopal.com/
https://en.wikipedia.org/wiki/Quintic_function
https://fr.wikipedia.org/wiki/Algorithme_A*
https://ezgif.com/sprite-cutter?err=expired
https://babaiswiki.fandom.com/wiki/Category:Nouns
https://www.spriters-resource.com/pc_computer/babaisyou/sheet/172039/
https://fr.wikipedia.org/wiki/Bruit_de_Perlin#:~:text
=Le%20bruit%20de%20Perlin%20est%20une%20texture%20proc%C3%A9dur
ale%20primitive%2C%20c,am%C3%A9liorer%20le%20r%C3%A9alisme%20des%20infographies.
https://fr.wikipedia.org/wiki/Distance_de_Manhattan
https://fr.wikipedia.org/wiki/Interpolation_lin%C3%A9aire
https://www.freefileconvert.com/file/ag-qaoaqG-RO
Sélecteur de couleur de couleur
*/
