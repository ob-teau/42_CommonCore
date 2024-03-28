/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:20:28 by acoinus           #+#    #+#             */
/*   Updated: 2022/05/27 16:06:37 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

static void	env_fds(t_minish *m, int i, int std_out, int std_in)
{
	if (m->cell_nb > 1)
		pip_in_built(m, i, 3);
	ft_redir_files(&m->c[i]);
	builtin_env(m->c[i].s, m);
	if (m->c[i].red)
	{
		dup2(std_out, STDOUT_FILENO);
		close(std_out);
		dup2(std_in, STDIN_FILENO);
		close(std_in);
	}
	if (m->cell_nb > 1)
	{
		dup2(m->std_out, STDOUT_FILENO);
		close(m->std_out);
		dup2(m->std_in, STDIN_FILENO);
		close(m->std_in);
	}
}

static void	pwd_fds(t_minish *m, int i, int std_out, int std_in)
{
	if (m->cell_nb > 1)
		pip_in_built(m, i, 2);
	ft_redir_files(&m->c[i]);
	builtin_pwd(m);
	if (m->c[i].red)
	{
		dup2(std_out, STDOUT_FILENO);
		close(std_out);
		dup2(std_in, STDIN_FILENO);
		close(std_in);
	}
	if (m->cell_nb > 1)
	{
		dup2(m->std_out, STDOUT_FILENO);
		close(m->std_out);
		dup2(m->std_in, STDIN_FILENO);
		close(m->std_in);
	}
}

static void	echo_fds(t_minish *m, int i, int std_out, int std_in)
{
	if (m->cell_nb > 1)
		pip_in_built(m, i, 1);
	ft_redir_files(&m->c[i]);
	builtin_echo(m->c[i].s, m);
	if (m->c[i].red)
	{
		dup2(std_out, STDOUT_FILENO);
		close(std_out);
		dup2(std_in, STDIN_FILENO);
		close(std_in);
	}
	if (m->cell_nb > 1)
	{
		dup2(m->std_out, STDOUT_FILENO);
		close(m->std_out);
		dup2(m->std_in, STDIN_FILENO);
		close(m->std_in);
	}
}

void	ft_built(t_minish *m, int i)
{
	int		std[2];

	while (m->sauv_env[i] && ft_strncmp(m->sauv_env[i], "PATH=", 5))
		++i;
	if (m->sauv_env && m->sauv_env[i])
		m->path = ft_split(&m->sauv_env[i][5], ':');
	if (!get_fds(m))
		return ;
	i = -1;
	while (++i < m->cell_nb)
	{
		if (m->c[i].red)
		{
			std[1] = dup(STDOUT_FILENO);
			std[0] = dup(STDIN_FILENO);
		}
		if (ft_strcmp("echo", m->c[i].s[0]) == 0)
			echo_fds(m, i, std[1], std[0]);
		else if (ft_strcmp("pwd", m->c[i].s[0]) == 0)
			pwd_fds(m, i, std[1], std[0]);
		else if (ft_strcmp("env", m->c[i].s[0]) == 0)
			env_fds(m, i, std[1], std[0]);
		else
			cd_export_unset(m, i, std[1], std[0]);
	}
}
