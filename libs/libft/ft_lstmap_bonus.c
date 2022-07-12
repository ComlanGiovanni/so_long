/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:35:37 by gcomlan           #+#    #+#             */
/*   Updated: 2022/05/24 14:36:55 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*c_list;
	t_list	*c_elem;

	c_list = NULL;
	while (lst)
	{
		c_elem = ft_lstnew(f(lst->content));
		if (!c_elem)
		{
			ft_lstclear(&c_list, del);
			return (NULL);
		}
		ft_lstadd_back(&c_list, c_elem);
		lst = lst->next;
	}
	return (c_list);
}
