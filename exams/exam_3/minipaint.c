#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		W;
int		H;
char	BG;
char	**tab;

typedef struct Draw
{
	char		r;
	float	x;
	float	y;
	float	rad;
	char	c;
}Draw;

int	end(FILE *fd, int err)
{
	if (err == 2 && (err = 1))
		write (1, "Error: Operation file corrupted\n", 32);
	else if (err == 1)
		write (1, "Error: argument\n", 16);
	else
	{
		for (int i = 0; i < H; i++)
		{
			write(1, tab[i], W);
			write(1, "\n", 1);
		}
	}
		if (fd)
			fclose(fd);
		if (tab)
		{
			for (int j = 0; j < H; j++)
			{	free(tab[j]);
			}
			free(tab);
		}
	return (err);
}

int	main(int ac, char **av)
{
	FILE	*fd;
	float	crl;
	int		res;
	Draw	d;

	fd = NULL;
	if (ac != 2)
		return (end(fd, 1));
	if ((fd = fopen(av[1], "r")))
	{
		if ((res = fscanf(fd, "%d %d %c", &W, &H, &BG)) == 3)
		{
			if (W > 0 && W <= 300 && H > 0 && H <= 300)
			{
				tab = malloc(sizeof(char *) * H);
				for (int i = 0; i < H; i++)
				{
					tab[i] = malloc(sizeof(char) * W);
					memset(tab[i], BG, W);
				}
				while (1)
				{
					res = fscanf(fd, "\n%c %f %f %f %c", &d.r, &d.x, &d.y, &d.rad, &d.c);
					if (res == EOF)
						return (end(fd, 0));
					else if (res != 5 || d.rad <= 0 || (d.r != 'C' && d.r != 'c'))
						break;
					for (int line = 0; line < H; line++)
					{
						for (int col = 0; col < W; col++)
						{
							crl = sqrtf(powf(line - d.y, 2.0) + powf(col - d.x, 2.0));
							if (crl <=  d.rad)
							{
								if ((d.r == 'C') || (d.r == 'c' && d.rad - crl < 1.0f))
									tab[line][col] = d.c;
							}
						}
					}
				}
			}
		}
	}
	return (end(fd, 2));
}
