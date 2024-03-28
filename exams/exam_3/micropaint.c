#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		H;
int		W;
char	BG;
char	**TAB;

typedef struct	Draw
{
	char	r;
	float	x;
	float	y;
	float	x2;
	float	y2;
	float	w;
	float	h;
	char	c;
}Draw;

int	fill(int col, int lin, Draw d)
{
	if ((col - d.x < 1.0f) || (d.x2 - col < 1.0f) ||
		(lin - d.y < 1.0f) || (d.y2 - lin < 1.0f))
		return (1);
	return (0);
}

int	end(FILE *fd, int err)
{
	if (err == 2 && (err = 1))
		write(1, "Error: operation file corrupted\n", 32);
	else if (err == 1)
		write(1, "Error: argument\n", 16);
	else
	{
		for (int i = 0; i < H; i++)
		{
		write(1, TAB[i], W);
		write(1, "\n", 1);
		}
	}
	if (fd)
		fclose(fd);
	if (TAB)
	{	
		for (int i = 0; i < H; i++)
			free(TAB[i]);
		free(TAB);
	}
	return (err);
}

int	main(int ac, char **av)
{
	FILE	*fd;
	int		res;
	Draw	d;

	fd = NULL;
	if (ac != 2)
		return (end(fd, 1));
	if (fd = fopen(av[1], "r"))
	{
		if ((res = fscanf(fd, "%d %d %c", &W, &H, &BG)) == 3)
		{
			if (W > 0 && W <= 300 && H > 0 && H <= 300)
			{
				TAB = malloc(sizeof(char *) * H);
				for (int i = 0; i < H; i++)
				{
					TAB[i] = malloc(sizeof(char) * W);
					memset(TAB[i], BG, W);
				}
			}
			while (1)
			{
				res = fscanf(fd, "\n%c %f %f %f %f %c", &d.r, &d.x, &d.y, &d.w, &d.h, &d.c);
				if (res == EOF)
					return (end(fd, 0));
				if (res != 6 || d.w <= 0 || d.h <= 0 || (d.r != 'r' && d.r != 'R'))
					break;
				d.x2 = d.x + d.w;
				d.y2 = d.y + d.h;
				for (int ligne = 0; ligne < H; ligne++)
				{
					for (int col = 0; col < W; col++)
					{
						if (ligne >= d.y && ligne <= d.y2 && col >= d.x && col <= d.x2)
						{
							if ((d.r == 'R') || (d.r == 'r' && fill(col, ligne, d)))
								TAB[ligne][col] = d.c;
						}
					}
				}
			}
		}
	}
	return (end(fd, 2));
}
