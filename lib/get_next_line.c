/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:55:48 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/03 16:23:37 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Cette fonction check si fd et BUFFER_SIZE sont correct , if nope return NULL
stash aka reserve en fr stock le curseur (pointeur)
check aussi si la stash existe ou retourn NULL
*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = new_stash(stash);
	return (line);
}

/*
Cette fonction recupere le fd du fichier ouvert
et stock le BUFFER SIZE dans idx, si read echoue idx = -1 
on free et on return NULL
verifi que le malloc sest bien passer sinon NULL // malloc + 1 endofchar
On raoute un '\0' à la fin de la chaine lut, 
pour être sur d'avoir une chaine de caractères valide
*/

char	*get_stash(int fd, char *stash)
{
	char	*buff;
	int		idx;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	idx = 1;
	while (!str_chr(stash, '\n') && idx != 0)
	{
		idx = read(fd, buff, BUFFER_SIZE);
		if (idx == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[idx] = '\0';
		stash = str_join(stash, buff);
	}
	free(buff);
	return (stash);
}

/*
Cette fonction malloc un char * a la taille de la stash + 2 
parceaue dans get stash on sarrete avanet le retour a la ligne dans le line_len
et on ajoute le end of string \0
elle revoie donc sous forme de ligne la stash
*/

char	*get_line(char *stash)
{
	int		idx;
	char	*line;

	idx = 0;
	if (!stash[idx])
		return (NULL);
	line = (char *)malloc(sizeof(char) * (line_len(stash) + 2));
	if (!line)
		return (NULL);
	stash_cpy(line, stash);
	return (line);
}

/*
Cette fonction vide la stash de la ligne recup ddans line
*/

char	*new_stash(char *stash)
{
	int		idx;
	int		idx_new_stash;
	char	*new_stash;

	idx = 0;
	idx_new_stash = 0;
	while (stash[idx] && stash[idx] != '\n')
		idx++;
	if (!stash[idx])
	{
		free(stash);
		return (NULL);
	}
	new_stash = (char *)malloc(sizeof(char) * (str_len(stash) - idx + 1));
	if (!new_stash)
		return (NULL);
	idx++;
	while (stash[idx])
		new_stash[idx_new_stash++] = stash[idx++];
	new_stash[idx_new_stash] = '\0';
	free(stash);
	return (new_stash);
}

/*

gcc -Wall -Werror -Wextra -D BUFFER_SIZE=800
get_next_line.c get_next_line_utils.c &&

./a.out
valgrind ./a.out a.out
valgrind --leak-check=full --show-leak-kinds=all ./a.out .gitignore

-g3

> afile.txt

cat -e file.txt

*/
/*
#include <stdio.h>
#include <fcntl.h>

int    main(int argc , char **argv)
{
	(void)argc;
    char    *line;
    int        idx;
    int        fd;
	
    fd = open(argv[1], O_RDONLY);
    idx = 1;
	//argv for test
    while (idx < 9)
    {
        line = get_next_line(fd);
        printf("Line (%02d) > %s", idx, line);
        free(line);
        idx++;
    }
    close(fd);
    return (0);
}
*/
/*
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    int fd;
    int count;
    char *line;

    count = 1;
    line = NULL;
    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("\n==Ligne numero %d==\n|%s|", count, line);
            count++;
            free(line);
        }
        if (!line)
            printf("\nE\nO === EOF || Error ===\nF\n");
        close(fd);
    }
    return (0);
}
*/
/*
FOR MUTIPLE FILE
int    main(int argc , char **argv)
{
    char    	*line;
    int        idx;
    int        fd1;
    int        fd2;
    int        fd3;

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);
    fd3 = open(argv[3], O_RDONLY);
    idx = 1;
    while (idx < 15)
    {
        line = get_next_line(fd3);
        printf("Line (%02d) of argv[3] > %s", idx, line);
        free(line);
        line = get_next_line(fd1);
        printf("Line (%02d) of argv[1] > %s", idx, line);
        free(line);
        line = get_next_line(fd2);
        printf("Line (%02d) of argv[2] > %s", idx, line);
        free(line);
        idx++;
    }
    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}
*/