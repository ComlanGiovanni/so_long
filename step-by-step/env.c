/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:58:43 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/17 16:42:32 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t					idx;
	int						res;
	unsigned char			*t1;
	unsigned char			*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	idx = 0;
	res = 0;
	if (n == 0)
		return (0);
	while (t1[idx] != '\0' && t2[idx] != '\0' && idx < n)
	{
		if (t1[idx] != t2[idx])
			return (t1[idx] - t2[idx]);
		idx++;
	}
	if (idx < n)
		res = t1[idx] - t2[idx];
	else
		res = 0;
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size++] != '\0')
		;
	return (size - 1);
}


int	ft_check_env(char **env)
{
	int	idx;

	if (!*env)
        printf("no env\n");
		//return (EXIT_FAILURE);
	idx = 0;
	while (env[idx])
	{
		if (ft_strncmp("DISPLAY", env[idx], ft_strlen("DISPLAY")) == 0)
            printf("display\n");
			//return (EXIT_SUCCESS);
        else
            printf("no display\n");
		idx++;
	}
	return (EXIT_FAILURE);
}

void ft_print_env(char **envp)
{
    for (char **env = envp; *env != 0; env++)
    {
        char *thisEnv = *env;
        printf("%s\n", thisEnv);    
  }
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    //ft_print_env(envp);
    ft_check_env(envp);
    return (EXIT_SUCCESS);
}
