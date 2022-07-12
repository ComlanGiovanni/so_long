/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:20:02 by gcomlan           #+#    #+#             */
/*   Updated: 2022/05/25 23:04:12 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_str(char const *s, char c)
{
	int	idx;
	int	nbr;

	idx = 0;
	nbr = 0;
	while (s[idx] != 0)
	{
		if (s[idx] != c && (s[idx + 1] == c || s[idx + 1] == 0))
			nbr++;
		idx++;
	}
	return (nbr);
}

static int	split_words(char **res, char const *s, char c, int word)
{
	int		start;
	int		end;

	end = 0;
	start = 0;
	while (s[end])
	{
		if (s[end] == c || s[end] == 0)
			start = end + 1;
		if (s[end] != c && (s[end + 1] == c || s[end + 1] == 0))
		{
			res[word] = malloc(sizeof(char) * (end - start + 2));
			if (!res[word])
			{
				while (word++)
					free(res[word]);
				return (0);
			}
			ft_strlcpy(res[word], (s + start), end - start + 2);
			word++;
		}
		end++;
	}
	res[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_count_str(s, c) + 1));
	if (!res)
		return (NULL);
	if (!split_words(res, s, c, 0))
		return (NULL);
	return (res);
}
