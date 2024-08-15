/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_a_star_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:24:29 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 01:39:50 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_free_a_star_lists_nodes_elements(t_a_star_node **list, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		if (list[index])
		{
			free(list[index]);
			list[index] = NULL;
		}
		index++;
	}
	free(list);
}

void	ft_free_a_star_lists_nodes(t_a_star_node **open_list, \
	int open_count, t_a_star_node **closed_list, int closed_count)
{
	ft_free_a_star_lists_nodes_elements(open_list, open_count);
	ft_free_a_star_lists_nodes_elements(closed_list, closed_count);
}
