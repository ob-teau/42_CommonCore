/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:44:14 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 00:11:19 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

//a gerer avant si arg apres env, ne fait rien ?

static int	ft_strrchr(char *str, char d)
{
	size_t			i;

	i = ft_strlen(str);
	if (d == '\0')
		return (0);
	while (i > 0 && str[--i])
	{
		if (str[i] == d)
			return (1);
	}
	return (0);
}

static int	print_error(char **cmd, t_minish *m)
{
	write(1, "env: '", 6);
	ft_putstr_fd(cmd[1], 1);
	printf("': No such file or directory\n");
	m->ret = 127;
	return (127);
}

int	builtin_env(char **cmd, t_minish *m)
{
	int	i;

	i = 0;
	if (cmd[1] != NULL)
		return (print_error(cmd, m));
	while (m->sauv_env && m->sauv_env[i] != NULL && i < m->size_env)
	{	
		if (ft_strrchr(m->sauv_env[i], '=') == 0)
			i++;
		else
		{
			ft_putstr_fd(m->sauv_env[i], 1);
			if (i < (m->size_env))
				ft_putchar_fd('\n', 1);
			i++;
		}
	}
	if (m->sauv_env[i] != NULL && ft_strrchr(m->sauv_env[i], '=') == 1)
		ft_putstr_fd(m->sauv_env[i], 1);
	m->ret = 0;
	return (0);
}
