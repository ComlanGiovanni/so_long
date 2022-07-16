/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:34:24 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/16 11:19:17 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

#include <stdlib.h>
#include <stdio.h>

# define GAME_TITLE	        "Simple window"
# define HELLO_WORLD	    "HELLO WORLD"

# define BLUE 0x0000FF
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define BROWN 0x993300
# define WHITE 0xFFFFFF

typedef struct s_sprites {
	void	*wall_0;
	void	*wall_1;
	void	*wall_2;
	void	*current;
	int		anim_frames;
}		t_sprites;

typedef struct s_game
{
    t_sprites 			  sprite;
	void	 		   	  *mlx;
	void   				  *win;
    long long int		  width;
	long long int		  height;
}		t_game;

void	ft_draw_text(t_game *game)
{
	char	*str;

	//str = ft_itoa(game.moves);

    str = "24";
    mlx_string_put(game->mlx, game->win, 88, 99, 15921152, str);

    /*
	if (game.collects >= 0)
		mlx_string_put(game.mlx, game.window,
			game.wndw_size.x - IMG_SIZE / 2.3,
			IMG_SIZE - IMG_SIZE / 1.5,
			-1, str);
	else
		mlx_string_put(game.mlx, game.window,
			game.wndw_size.x - IMG_SIZE / 2.3,
			IMG_SIZE - IMG_SIZE / 1.5,
			15921152, str);
    */
	//free(str);
}*


void	ft_render(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.current, 100, 100);
	ft_draw_text(game);
}

void	ft_wall_animation(t_sprites *sprite)
{

    static int	frame;
	if (sprite->anim_frames == 0)
		return ;
	if (frame == sprite->anim_frames)
	{
		sprite->current = sprite->wall_0;
	}
	else if (frame >= sprite->anim_frames * 2)
	{
		sprite->current = sprite->wall_1;
		frame = 0;
	}
	frame += 1;
}

int	ft_update(t_game *game)
{
    //printf("ici\n");
	ft_wall_animation(&game->sprite);
	ft_render(game);
	return (1);
}

int	main(void)
{
    t_game	*game;
    int		  wid;
	int		  hei;

    game = malloc(sizeof(t_game));
    game->width = 720;
    game->height = 720;

    //wid = 10;
    //hei = 10;

    if ((game->mlx = mlx_init()) == NULL)
        return (EXIT_FAILURE);

    if ((game->win = mlx_new_window(game->mlx, game->height, game->width, GAME_TITLE)) == NULL)
        return (EXIT_FAILURE);

    if ((game->sprite.current = mlx_xpm_file_to_image(game->mlx, "wall_frame_0.xpm", &wid, &hei)) == NULL)
		return (EXIT_FAILURE);

    if ((game->sprite.wall_0 = mlx_xpm_file_to_image(game->mlx, "wall_frame_0.xpm", &wid, &hei)) == NULL)
		return (EXIT_FAILURE);
    
    if ((game->sprite.wall_1 = mlx_xpm_file_to_image(game->mlx, "wall_frame_1.xpm", &wid, &hei)) == NULL)
		return (EXIT_FAILURE);
    
    if ((game->sprite.wall_2 = mlx_xpm_file_to_image(game->mlx, "wall_frame_2.xpm", &wid, &hei)) == NULL)
		return (EXIT_FAILURE);

    game->sprite.anim_frames = 24;
    mlx_loop_hook(game->mlx, ft_update, game);
	mlx_loop(game->mlx);
}
