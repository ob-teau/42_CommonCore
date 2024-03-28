/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:53:02 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/26 23:56:27 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

static void	ft_putstr_fd4(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			write(fd, &s[i++], 1);
}

static int	is_flag4(char *s, int flag)
{
	int	pos;

	pos = 0;
	if (s[pos] == '-' && s[pos + 1])
	{
		pos++;
		while (s[pos] == flag)
			pos++;
		if (s[pos] == '\0')
			return (1);
	}
	return (0);
}

int	builtin_echo(char **cmd, t_minish *m)
{
	int	n_flag;
	int	i;

	n_flag = 0;
	i = 1;
	m->ret = 0;
	while (cmd[i] && (is_flag4(cmd[i], 'n') == 1))
	{
		n_flag = 1;
		i++;
	}
	while (cmd[i])
	{
		ft_putstr_fd4(cmd[i], 1);
		if (cmd[i])
			ft_putstr_fd4(" ", 1);
		i++;
	}
	if (n_flag == 0)
		ft_putstr_fd4("\n", 1);
	return (0);
}
