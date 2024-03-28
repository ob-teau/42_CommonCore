/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:37:28 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 00:00:19 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

static int	size_variable(char *lenv)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (lenv && lenv[i] != '\0' && lenv[i] != '=')
	{
		size++;
		i++;
	}
	ft_putstr_fd_n(lenv, size, 1);
	if (lenv && lenv[i] != '\0')
	{
		write(1, "\"", 1);
		ft_putstr_fd_aftern(lenv, size, 1);
		write(1, "\"", 1);
	}
	return (size);
}

int	set_m_env(t_minish *m)
{
	int	i;

	i = 0;
	if (m->m_env)
		ft_free_menv(m);
	m->m_env = (char **)(malloc(sizeof(char *) * (m->size_env + 1)));
	if (!m->m_env)
	{
		m->ret = 1;
		return (1);
	}
	m->m_env[m->size_env] = NULL;
	i = 0;
	if (m->sauv_env)
	{
		while (m->sauv_env[i])
		{
			m->m_env[i] = ft_strdup(m->sauv_env[i]);
			i++;
		}
	}
	return (0);
}

static void	env_export(t_minish *m)
{
	int	i;

	i = 0;
	while (m->m_env && m->m_env[i] != NULL && i < m->size_env - 2)
	{
		ft_putstr_fd("export ", 1);
		size_variable(m->m_env[i]);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putstr_fd("export ", 1);
	size_variable(m->m_env[i]);
	m->ret = 0;
	i = 0;
	while (m->m_env[i])
	{
		free(m->m_env[i]);
		m->m_env[i] = NULL;
		i++;
	}
	free(m->m_env);
	m->m_env = NULL;
}

static void	alpha_env(t_minish *m)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	swap = NULL;
	while (m->m_env[i])
	{
		j = i + 1;
		while (m->m_env[j])
		{
			if (ft_strcmp2(m->m_env[i], m->m_env[j]) > 0)
			{
				swap = m->m_env[i];
				m->m_env[i] = m->m_env[j];
				m->m_env[j] = swap;
			}
			j++;
		}
		i++;
	}
	env_export(m);
}

int	builtin_export(char **cmd, t_minish *m)
{
	int	i;

	i = 0;
	m->ret = 0;
	m->size = 0;
	if (cmd[0] && cmd[1] == NULL)
	{
		if (set_m_env(m) == -1)
			return (1);
		alpha_env(m);
		return (0);
	}
	else
	{
		if (builtin_export_var(cmd, m, 1, 0) == -1)
		{
			m->ret = 1;
			return (1);
		}
	}
	return (0);
}
