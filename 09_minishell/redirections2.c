/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:16:27 by acoinus           #+#    #+#             */
/*   Updated: 2022/05/27 14:39:28 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int	get_redir_type(char *str)
{
	if (str[0] == '>' && str[1] != '>')
		return (1);
	if (str[0] == '>' && str[1] == '>')
		return (2);
	if (str[0] == '<' && str[1] != '<')
		return (3);
	if (str[0] == '<' && str[1] == '<')
		return (4);
	return (0);
}

int	create_files(t_cell *c)
{
	int	fd;
	int	i;

	i = -1;
	fd = 0;
	if (!c->red)
		return (1);
	while (c->red && c->red[++i])
	{
		if (c->red[i] && get_redir_type(c->red[i]) == 1)
		{
			fd = open(&c->red[i][1], O_WRONLY | O_CREAT, 0644);
			if (fd < 0)
				return (write(2, "Failure to create file\n", 23), 0);
			close(fd);
		}
		else if (c->red[i] && get_redir_type(c->red[i]) == 2)
		{
			fd = open(&c->red[i][2], O_WRONLY | O_CREAT, 0644);
			if (fd < 0)
				return (write(2, "Failure to create file\n", 23), 0);
			close(fd);
		}
	}
	return (1);
}

int	heredoc(char *str)
{
	char	*inpt;
	int		fd[2];

	pipe(fd);
	while (1)
	{
		inpt = readline("\nheredoc> ");
		if (!ft_strcmp(inpt, str))
			return (close(fd[1]), fd[0]);
		if (!inpt)
			return (write(2, "warning : end-of-file\n",
					ft_strlen("warning : end-of-file\n")), close(fd[1]), fd[0]);
		write(fd[1], inpt, ft_strlen(inpt));
		write(fd[1], "\n", 1);
		free(inpt);
	}
}

int	fill_fds(t_cell *c)
{
	int	i;
	int	check_dsor;

	check_dsor = 0;
	init_redir(c);
	fds_heredoc(c);
	i = 0;
	while (c->red && c->red[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (get_redir_type(c->red[i]) == 1 && !c->sor && !c->dsor)
			c->sor = open(&c->red[i][1], O_WRONLY | O_TRUNC, 0644);
		if (get_redir_type(c->red[i]) == 2 && !c->dsor && !c->sor)
			c->dsor = open(&c->red[i][2], O_WRONLY | O_APPEND, 0644);
		if (get_redir_type(c->red[i]) == 3 && !c->ent && !check_dsor)
			c->ent = open(&c->red[i][1], O_RDONLY, 0644);
		if (get_redir_type(c->red[i]) == 4)
			check_dsor++;
		i--;
	}
	return (1);
}
