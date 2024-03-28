/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:24:39 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 13:39:17 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int	init_env(t_minish *m, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	m->size_env = i;
	m->sauv_env = (char **)malloc(sizeof(char *) * (m->size_env + 1));
	if (!m->sauv_env)
	{
		errno = 12;
		return (ft_perror("malloc crash", -1));
	}
	m->sauv_env[m->size_env] = NULL;
	i = -1;
	while (env[++i] && env[i] != NULL)
		m->sauv_env[i] = ft_strdup(env[i]);
	m->ret = 0;
	if (env_shlvl(m) == -1)
		return (-1);
	return (0);
}

void	init(t_minish *m)
{
	m->pip = 0;
	m->cell_nb = 0;
	m->path = NULL;
	m->newpath = 0;
	m->std_in = 0;
	m->std_out = 0;
}

int	ft_perror(char *s, int x)
{	
	perror(s);
	errno = 0;
	return (x);
}

void	ft_free_env(t_minish *m)
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
	i = 0;
	ft_free_menv(m);
}

void	ft_free_menv(t_minish *m)
{
	int	i;

	i = 0;
	if (m->m_env)
	{	
		while (m->m_env[i])
		{
			free(m->m_env[i]);
			m->m_env[i] = NULL;
			i++;
		}
		free(m->m_env);
		m->m_env = NULL;
	}
}
