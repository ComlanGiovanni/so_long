/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:21:08 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/01 14:25:46 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (nmemb && (nmemb * size / nmemb) != size)
		return (NULL);
	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	ft_bzero((char *)dest, nmemb * size);
	return ((char *)dest);
}
