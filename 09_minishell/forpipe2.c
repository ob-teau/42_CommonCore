/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forpipe2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:27:19 by acoinus           #+#    #+#             */
/*   Updated: 2022/05/27 14:03:13 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void	ft_check_path_suite(t_minish *m, int x, char **cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	if (m->cell_nb > 1)
		ft_pipe(m, x);
	ft_redir_files(&m->c[x]);
	if (access(cmd[0], X_OK) == 0)
		execve(cmd[0], cmd, m->sauv_env);
	while (m->path && m->path[i])
	{
		tmp = ft_strjoin(m->path[i], "/");
		m->newpath = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(m->newpath, X_OK) == 0)
			execve(m->newpath, cmd, m->sauv_env);
		i++;
	}
	exit(127);
}

void	ft_check_path(t_minish *m, char **cmd, int x)
{
	int	forkreturn;
	int	status;

	status = 0;
	if (m->cell_nb > 1 && x < m->cell_nb - 1)
		pipe(m->c[x].pipe);
	forkreturn = fork();
	if (forkreturn < 0)
		return ;
	else if (forkreturn == 0)
		ft_check_path_suite(m, x, cmd);
	if (forkreturn > 0)
	{
		g_glob = 1;
		waitpid(forkreturn, &status, WEXITSTATUS(status));
		m->ret = status / 256;
		g_glob = 0;
		if (m->cell_nb > 1 && x < m->cell_nb - 1)
			close (m->c[x].pipe[1]);
		if (x > 0)
			close(m->c[x - 1].pipe[0]);
		close_fd_redir(m->c[x]);
	}
}

int	pip_in_built(t_minish *m, int x, int idx)
{
	if (!idx)
		return (0);
	if (m->cell_nb > 1 && x < m->cell_nb - 1)
		pipe(m->c[x].pipe);
	if (m->cell_nb > 1)
	{
		m->std_out = dup(STDOUT_FILENO);
		m->std_in = dup(STDIN_FILENO);
		ft_pipe_builtin(m, x);
	}
	return (0);
}

void	ft_exec(t_minish *m, int x)
{
	char	**cmd;

	cmd = m->c[x].s;
	if (!check_access(m, cmd))
	{
		write(1, cmd[0], ft_strlen(cmd[0]));
		if (!m->path)
		{
			m->ret = 127;
			write(1, ": No such file or directory", 27);
		}
		else
		{
			m->ret = 127;
			write(1, ": command not found", 19);
		}
		return ;
	}
	ft_check_path(m, cmd, x);
}
