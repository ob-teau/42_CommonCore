/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:44:52 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/26 23:46:27 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

static int	line_to_erase(char *cmd, t_minish *m)
{
	int	sizecmd;
	int	j;

	sizecmd = 0;
	j = 0;
	while (cmd[sizecmd] != '\0')
		sizecmd++;
	while (m->sauv_env[j] && (ft_strncmp3(m->sauv_env[j], cmd, sizecmd) != 0))
		j++;
	if (!m->sauv_env[j])
		return (-1);
	return (j);
}

static int	swap_env(t_minish *m)
{
	int	i;

	i = 0;
	while (m->sauv_env[i])
	{
		free(m->sauv_env[i]);
		m->sauv_env[i] = NULL;
		i++;
	}
	free(m->sauv_env);
	m->sauv_env = (char **)malloc(sizeof(char *) * (m->size_env + 1));
	if (!m->sauv_env)
	{
		m->ret = 1;
		return (-1);
	}
	i = -1;
	if (m->m_env)
	{
		while (m->m_env[++i] != NULL)
			m->sauv_env[i] = ft_strdup(m->m_env[i]);
	}
	m->sauv_env[i] = NULL;
	ft_free_menv(m);
	return (0);
}

static void	var_found_check(t_minish *m, int *line, int size, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->sauv_env[i] != NULL)
	{
		while (line[j] >= 0 && j <= size)
		{
			if (i == line[j])
				i++;
			j++;
		}
		if (m->sauv_env[i] != NULL)
		{
			m->m_env[k] = ft_strdup(m->sauv_env[i]);
			i++;
			k++;
			j = 0;
		}
	}
	m->m_env[k] = NULL;
}

static int	var_found(t_minish *m, int *line, int size, int k)
{
	m->size_env = m->size_env - (size);
	m->m_env = (char **)malloc(sizeof(char *) * (m->size_env + 1));
	if (!m->m_env)
	{
		m->ret = 1;
		return (-1);
	}
	m->m_env[m->size_env] = NULL;
	var_found_check(m, line, size, k);
	if (swap_env(m) == -1)
		return (-1);
	return (0);
}

int	builtin_unset(char **cmd, t_minish *m, int i, int j)
{
	int	line[500];

	m->ret = 0;
	i = 0;
	while (i < 500)
		line[i++] = '\0';
	i = 1;
	while (cmd[i] && cmd[i] != NULL)
	{
		if (line_to_erase(cmd[i], m) >= 0)
		{
			line[j] = line_to_erase(cmd[i], m);
			i++;
			j++;
		}
		else if (line_to_erase(cmd[i], m) == -1)
		{
			builtin_unset_error(cmd[i], m);
			i++;
		}
	}
	if (j != 0)
		if (var_found(m, line, j, 0) == -1)
			return (1);
	return (0);
}
