/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:58:01 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/24 23:13:40 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_start.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	free(mlx);
	printf("MLX Successfully Loaded\n");
}
