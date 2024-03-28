/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:04:00 by acoinus           #+#    #+#             */
/*   Updated: 2022/02/11 11:56:48 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	join(t_info *f, char *s, int n)
{
printf("\njoin\n");
	char *tmp;
	int	i = 0;

	tmp = f->line;
printf("join1 \n");
	f->line = malloc(sizeof(char) * (ft_strlen(f->line) + n + 1));
	if (!f->line)
		return (-1);
	while (f->line[i])
		i++;
	f->i_line = i, i = 0;
	while (tmp[i])
	{
		f->line[f->i_line] = tmp[i];
		++i, ++f->i_line;
	}
	i = 0;
	while (s[i] && i <= n)
	{
		f->line[f->i_line] = s[i];
		++i, ++f->i_line;
	}
	if (tmp)
		free(tmp);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i = 0;
	
	while (s && s[i])
		i++;
	return (i);
}

void	b_zero(char *s, int n)
{
	int	i = 0;

	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return;
}

int check_n(t_info *f, char *s, char *rest)
{
	int	i = 0;
	int	j = 0;

printf("\ncheck_n\n");
	while (s[i] && s[i] != '\n')
	{
printf("[%c] ", s[i]);
		i++;
	}
printf("\n");
	if (join(*&f, s, i))
		return (-1);
	if (s[i] == '\n')
	{
		i++;
		while (s[i])
		{
			rest[j] = s[i];
			++j, ++i;
		}
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE + 1];
	t_info		f;

	f = (t_info){0};
	f.fd = fd;
printf("1\n");
	if (rest[f.i])
	{
printf("rest\n");
		f.line = malloc(sizeof(char) * ft_strlen(rest) + 1);
		if (!f.line)
			return NULL;
		while (rest[f.i])
		{
			f.line[f.i_line] = rest[f.i];
			f.i_line++;
			++f.i;
		}
		f.i = 0;
	}
printf("2\n");
	b_zero(&*rest, BUFFER_SIZE + 1);
	f.x_r = read(fd, f.save, BUFFER_SIZE);
printf("save = [%s]\n", f.save);
	while ((f.x_n = check_n(&f, f.save, &*rest)) != 1 && f.x_r != 0)
	{
		if (f.x_n == -1)
		{
			if (f.line)
				free(f.line);
			return (NULL);
		}
		b_zero(f.save, BUFFER_SIZE + 1);
		f.x_r = read(fd, f.save, BUFFER_SIZE);
	}
	if (!f.line)
		free(f.line);
	return (f.line);
}

int	main(int ac, char **av)
{
	int	fd;
	char	*line = NULL;

	if (ac < 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	printf("line = [%s]", get_next_line(fd));
	if (line)
	free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line = [%s]\n", line);
		if (line)
			free(line);
	}
	printf("end\n");
	return (0);
}
