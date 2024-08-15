#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define WIDTH 30
#define HEIGHT 11

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void	initialize_map(int fd)
{
	int		i;
	char	line[WIDTH + 2];

	i = 0;
	while (i < WIDTH)
		line[i++] = '1';
	line[WIDTH] = '\n';
	line[WIDTH + 1] = '\0';
	i = 0;
	while (i++ < HEIGHT)
		ft_putstr_fd(line, fd);
}

void	get_random_directions(int *directions)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < 4)
	{
		directions[i] = i;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = rand() % (i + 1);
		tmp = directions[i];
		directions[i] = directions[j];
		directions[j] = tmp;
		i++;
	}
}

void	carve_passage(int fd, int x, int y)
{
	int		directions[4];
	int		i;
	int		nx;
	int		ny;
	int		wallx;
	int		wally;
	char	line[WIDTH + 1];

	get_random_directions(directions);
	i = 0;
	while (i < 4)
	{
		nx = x;
		ny = y;
		if (directions[i] == 0)
			ny -= 2;
		else if (directions[i] == 1)
			ny += 2;
		else if (directions[i] == 2)
			nx += 2;
		else if (directions[i] == 3)
			nx -= 2;
		wallx = (x + nx) / 2;
		wally = (y + ny) / 2;
		if (ny > 0 && ny < HEIGHT && nx > 0 && nx < WIDTH)
		{
			lseek(fd, ny * (WIDTH + 1), SEEK_SET);
			read(fd, line, WIDTH);
			if (line[nx] == '1')
			{
				line[nx] = '0';
				lseek(fd, ny * (WIDTH + 1), SEEK_SET);
				write(fd, line, WIDTH);
				lseek(fd, y * (WIDTH + 1), SEEK_SET);
				read(fd, line, WIDTH);
				line[x] = '0';
				lseek(fd, y * (WIDTH + 1), SEEK_SET);
				write(fd, line, WIDTH);
				lseek(fd, wally * (WIDTH + 1), SEEK_SET);
				read(fd, line, WIDTH);
				line[wallx] = '0';
				lseek(fd, wally * (WIDTH + 1), SEEK_SET);
				write(fd, line, WIDTH);
				carve_passage(fd, nx, ny);
			}
		}
		i++;
	}
}

void	place_char(int fd, char c)
{
	int		x;
	int		y;
	char	line[WIDTH + 1];

	while (1)
	{
		x = rand() % (WIDTH - 2) + 1;
		y = rand() % (HEIGHT - 2) + 1;
		lseek(fd, y * (WIDTH + 1), SEEK_SET);
		read(fd, line, WIDTH);
		if (line[x] == '0')
		{
			line[x] = c;
			lseek(fd, y * (WIDTH + 1), SEEK_SET);
			write(fd, line, WIDTH);
			break ;
		}
	}
}

int	main(void)
{
	int	fd;
	int	startx;
	int	starty;
	int	i;

	srand(time(NULL));
	fd = open("map.ber", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		return (1);
	initialize_map(fd);
	startx = (rand() % (WIDTH / 2)) * 2 + 1;
	starty = (rand() % (HEIGHT / 2)) * 2 + 1;
	carve_passage(fd, startx, starty);
	place_char(fd, 'P');
	place_char(fd, 'E');
	i = 0;
	while (i++ < 20)
		place_char(fd, 'C');
	close(fd);
	return (0);
}
