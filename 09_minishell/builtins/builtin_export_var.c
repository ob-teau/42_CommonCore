/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:01:23 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/26 23:42:53 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

static int	line_to_add(char *cmd)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '=')
			count++;
		i++;
	}
	if (count == 0)
		return (0);
	else
		return (0);
}

static int	swap_env(t_minish *m)
{
	int	i;

	i = -1;
	ft_free_only_env(m);
	m->sauv_env = (char **)malloc(sizeof(char *) * (m->size_env + 1));
	if (!m->sauv_env)
	{
		m->ret = 1;
		ft_free_menv(m);
		return (-1);
	}
	i = -1;
	if (m->m_env)
	{
		while (m->m_env[++i])
			m->sauv_env[i] = ft_strdup(m->m_env[i]);
	}
	else if (!m->m_env)
	{	
		ft_free_env(m);
		return (-1);
	}
	m->sauv_env[i] = NULL;
	ft_free_menv(m);
	return (0);
}

static int	add_in_env(char **cmd, t_minish *m, int *line, int j)
{
	int	i;
	int	k;
	int	l;

	i = 0;
	k = 0;
	m->size_env = m->size_env + m->size;
	l = add_new_variable(m, line, j, i);
	while (cmd[i] && cmd[i] != NULL)
	{
		while (line[k] && k < j)
		{
			if (i == line[k])
				m->m_env[l++] = ft_strdup(cmd[i]);
			k++;
		}
		k = 0;
		i++;
	}
	m->m_env[l] = NULL;
	if (swap_env(m) == -1)
		return (-1);
	return (0);
}

static int	builtin_export_var2(char **cmd, t_minish *m, int *line, int j)
{
	int	i;

	i = 1;
	while (cmd[i] && cmd[i] != NULL)
	{
		if (cmd[i][0] == 95 || ((cmd[i][0] >= 65 && cmd[i][0] <= 90)
					|| (cmd[i][0] >= 97 && cmd[i][0] <= 122)))
		{
			line[j] = i;
			i++;
			j++;
			m->size++;
		}
		else if (line_to_add(cmd[i]) == 0)
		{
			ft_putstr_fd("export: '", 1);
			ft_putstr_fd(cmd[i], 1);
			ft_putstr_fd("': not a valid identifier", 1);
			ft_putchar_fd('\n', 1);
			i++;
			m->ret = 1;
		}
	}
	return (j);
}

int	builtin_export_var(char **cmd, t_minish *m, int i, int j)
{
	int	line[100];

	while (i < 100)
		line[i++] = '\0';
	m->ret = 0;
	i = 1;
	while (cmd[i] && cmd[i] != NULL && (cmd[i][0] < '0' || cmd[i][0] > '9'))
	{
		if (builtin_exp_replace(cmd[i], m) <= 0)
		{
			line[j] = builtin_exp_replace(cmd[i], m);
			i++;
			j++;
			m->size_env--;
		}
		else if (builtin_exp_replace(cmd[i], m) == 1)
			i++;
	}
	j = builtin_export_var2(cmd, m, line, j);
	if (j > 0)
		if (add_in_env(cmd, m, line, j) == -1)
			return (1);
	m->size = 0;
	return (0);
}	
