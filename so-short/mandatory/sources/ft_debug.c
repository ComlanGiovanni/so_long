/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:34:16 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 00:02:05 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_mandatory.h"

void	ft_check_path_founding(char **map)
{
	ft_print_display_grid(map);
	usleep(100000);
	system("clear");
}

void	ft_print_display_grid(char **res)
{
	if (!res)
	{
		ft_putstr("NULL");
		return ;
	}
	while (*res)
	{
		ft_putstr(*res);
		ft_putstr("\n");
		res++;
	}
}

void	ft_display_start_end(t_point	start, t_point	end)
{
	ft_printf("Start x->%d y->%d\n", start.x, start.y);
	ft_printf("END x->%d y->%d\n", end.x, end.y);
}
