/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_border_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:26:23 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 21:27:06 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_borders_animation(t_game *game)
{
	ft_grass_animation(&game->grass.animation);
	ft_tree_animation(&game->tree.animation);
	ft_trees_animation(&game->trees.animation);
	ft_reed_animation(&game->reed.animation);
	ft_husks_animation(&game->husks.animation);
	ft_fungus_animation(&game->fungus.animation);
	ft_fungi_animation(&game->fungi.animation);
	ft_flower_animation(&game->flower.animation);
	ft_algae_animation(&game->algae.animation);
	ft_water_animation(&game->water.animation);
	ft_crab_animation(&game->crab.animation);
	ft_foliage_animation(&game->foliage.animation);
	ft_bog_animation(&game->bog.animation);
	ft_snail_animation(&game->snail.animation);
	ft_pillar_animation(&game->pillar.animation);
	ft_hedge_animation(&game->hedge.animation);
}
