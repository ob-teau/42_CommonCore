/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forpipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:23:50 by acoinus           #+#    #+#             */
/*   Updated: 2022/05/27 11:24:52 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void	ft_pipe(t_minish *m, int x)
{
	if (m->cell_nb == 1)
		return ;
	if (x < m->cell_nb - 1)
	{
		dup2(m->c[x].pipe[1], STDOUT_FILENO);
		close(m->c[x].pipe[0]);
		close(m->c[x].pipe[1]);
	}
	if (x > 0)
	{
		dup2(m->c[x - 1].pipe[0], STDIN_FILENO);
		close(m->c[x - 1].pipe[0]);
	}
}

void	ft_pipe_builtin(t_minish *m, int x)
{
	if (m->cell_nb == 1)
		return ;
	if (x < m->cell_nb - 1)
	{
		dup2(m->c[x].pipe[1], STDOUT_FILENO);
		close(m->c[x].pipe[1]);
	}
	if (x > 0)
	{
		dup2(m->c[x - 1].pipe[0], STDIN_FILENO);
		close(m->c[x - 1].pipe[0]);
	}
}

int	check_access(t_minish *m, char **cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	if (access(cmd[0], X_OK) == 0)
		return (1);
	while (m->path && m->path[i])
	{
		tmp = ft_strjoin(m->path[i], "/");
		m->newpath = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(m->newpath, X_OK) == 0)
		{
			free(m->newpath);
			m->newpath = NULL;
			return (1);
		}
		i++;
		free(m->newpath);
		m->newpath = NULL;
	}
	return (0);
}

void	ft_redir_files(t_cell *c)
{
	if (c->ent)
	{
		dup2(c->ent, STDIN_FILENO);
		close(c->ent);
	}
	else if (c->dent)
	{
		dup2(c->dent, STDIN_FILENO);
		close(c->dent);
	}
	if (c->sor)
	{
		dup2(c->sor, STDOUT_FILENO);
		close(c->sor);
	}
	else if (c->dsor)
	{
		dup2(c->dsor, STDOUT_FILENO);
		close(c->dsor);
	}
}

void	close_fd_redir(t_cell c)
{
	if (c.ent)
		close(c.ent);
	if (c.dent)
		close(c.dent);
	if (c.sor)
		close(c.sor);
	if (c.dsor)
		close(c.dsor);
}
