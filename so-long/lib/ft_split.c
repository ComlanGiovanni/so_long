/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:20:02 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 14:24:53 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_str(char *str, char c)
{
	int		i;
	int		count;
	int		new_word;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		new_word = 0;
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			new_word = 1;
			i++;
		}
		if (new_word == 1)
			count++;
	}
	return (count);
}

int	ft_allocate_memory(char **strs, char *str, char c)
{
	int		i;
	int		nb_letter;
	int		count_word;

	i = 0;
	count_word = 0;
	while (str[i] != '\0')
	{
		nb_letter = 0;
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			nb_letter++;
			i++;
		}
		if (nb_letter > 0)
		{
			strs[count_word] = malloc(sizeof(char) * (nb_letter + 1));
			if (str == NULL)
				return (0);
			count_word++;
		}
	}
	return (1);
}

void	ft_fill_strs(char **strs, char *str, char c)
{
	int		i;
	int		nb_letter;
	int		count_word;

	i = 0;
	count_word = 0;
	while (str[i] != '\0')
	{
		nb_letter = 0;
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			strs[count_word][nb_letter] = str[i];
			nb_letter++;
			i++;
		}
		if (nb_letter > 0)
		{
			strs[count_word][nb_letter] = '\0';
			count_word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str;
	int		nbr_word;

	if (!s)
		return (NULL);
	str = (char *)s;
	nbr_word = ft_count_str(str, c);
	strs = malloc(sizeof(char **) * (nbr_word + 1));
	if (strs == NULL)
		return (0);
	strs[nbr_word] = NULL;
	if (!ft_allocate_memory(strs, str, c))
		return (0);
	ft_fill_strs(strs, str, c);
	return (strs);
}
