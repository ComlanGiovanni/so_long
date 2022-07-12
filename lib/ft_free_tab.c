/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:33:20 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/26 22:42:13 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab)
{
	int	idx;

	idx = 0;
	if (tab == NULL)
		return ;
	while (tab[idx])
	{
		free(tab[idx]);
		idx++;
	}
	free(tab);
}
