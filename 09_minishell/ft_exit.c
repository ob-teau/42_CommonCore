/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:51:19 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 17:08:37 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

static int	ft_spaces(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && (s[i] == ' ' || (s[i] > 8 && s[i] <= 13)))
		i++;
	return (i);
}

static int	ft_atoi(const char *str)
{
	size_t	i;
	long	sign;
	long	n;

	sign = 1;
	n = 0;
	i = ft_spaces(str);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		n = n * 10 + str[i] - '0';
		if (n > 2147483647 && sign == 1)
			return (-1);
		if (n > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (sign * n);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_exit_print(t_minish *m)
{
	int	ret;

	write(1, "exit: numeric argument required\n", 32);
	m->ret = 2;
	ret = m->ret;
	ft_free_env(m);
	ft_fre(m);
	rl_clear_history();
	exit(ret);
}

int	ft_exit(char **tab, t_minish *m)
{
	int	i;

	i = -1;
	while (tab[0] && tab[1] && tab[1][++i])
		if (ft_isdigit(tab[1][i]) == 0)
			ft_exit_print(m);
	if (tab[0] && tab[1] && tab[2])
	{
		write(1, "exit: too many arguments\n", 25);
		m->ret = 1;
		return (-1);
	}
	if (tab[0] && tab[1])
	{
		m->ret = ft_atoi(tab[1]);
		ft_free_env(m);
		ft_fre(m);
		write(1, "exit\n", 5);
		rl_clear_history();
		exit(m->ret);
	}
	ft_free_env(m);
	ft_fre(m);
	rl_clear_history();
	exit(0);
}
