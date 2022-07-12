/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:27:34 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/12 22:31:09 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(char *s1)
{
    int		idx;
	char	*dest;

	idx = 0;
	dest = (char *)malloc(ft_strlen_1((char *)s1) * sizeof(char) + 1);
	if (dest)
	{
		while (s1[idx] != '\n')
		{
			dest[idx] = s1[idx];
			idx++;
		}
		dest[idx] = '\0';
		return (dest);
	}
	else
		return (NULL);
}

char	*ft_(char *s1, char *s2)
{

}
