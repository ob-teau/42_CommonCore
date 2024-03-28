/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_replace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:01:40 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 00:16:48 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	ft_free_only_env(t_minish *m)
{
	int	i;

	i = 0;
	if (m->sauv_env)
	{
		while (m->sauv_env[i])
		{
			free(m->sauv_env[i]);
			m->sauv_env[i] = NULL;
			i++;
		}
		free(m->sauv_env);
		m->sauv_env = NULL;
	}
}

void	builtin_unset_error(char *cmd, t_minish *m)
{
	if (cmd[0] == 95 || ((cmd[0] >= 65 && cmd[0] <= 90)
			|| (cmd[0] >= 97 && cmd[0] <= 122)))
	{
		m->ret = 0;
	}
	else
	{
		ft_putstr_fd("unset: '", 1);
		ft_putstr_fd(cmd, 1);
		ft_putstr_fd("': not a valid identifier", 1);
		ft_putchar_fd('\n', 1);
		m->ret = 1;
	}
}

int	builtin_exp_replace(char *cmd, t_minish *m)
{
	int	sizecmd;
	int	j;

	sizecmd = 0;
	j = 0;
	while (cmd[sizecmd] && cmd[sizecmd] != '=')
		sizecmd++;
	while (m->sauv_env[j] && (ft_strncmp2(m->sauv_env[j], cmd, sizecmd) != 0))
	{
		j++;
	}	
	if (!m->sauv_env[j])
	{
		return (1);
	}
	return (-j);
}

int	add_new_variable(t_minish *m, int *line, int j, int i)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	m->m_env = (char **)malloc(sizeof(char *) * (m->size_env + 1));
	if (!m->m_env)
	{
		m->ret = 1;
		return (1);
	}
	m->m_env[m->size_env] = NULL;
	while (m->sauv_env[i])
	{
		while (line[k] && k < j)
		{
			if (-i == line[k])
				i++;
			k++;
		}
		if (m->sauv_env[i])
			m->m_env[l++] = ft_strdup(m->sauv_env[i++]);
		k = 0;
	}
	return (l);
}
