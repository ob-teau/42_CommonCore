/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:53:44 by alice             #+#    #+#             */
/*   Updated: 2022/04/02 11:23:15 by alice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	gettime(t_all *a)
{
	gettimeofday(&a->tmv, NULL);
	return ((a->tmv.tv_sec * 1000) + (a->tmv.tv_usec / 1000));
}

int	ft_atoi(char *s)
{
	int	i;
	unsigned long	res;

	res = 0;
	i = -1;
	if (s[i + 1] == '+')
		i++;
	while ((s && s[++i]) && (s[i] >= '0' && s[i] <= '9'))
		res = (res * 10) + (s[i] - 48);
	if (i == 0 || s[i] != '\0' || res > INT_MAX  || res == 0 || i > 11)
		return (-1);
	return (res);
}

int	waiting(t_philo *p, long long b, int c)
{
	while ((gettime(p->a) - b) < c)
	{
		pthread_mutex_lock(&p->nd);
		if (p->end)
		{
			pthread_mutex_unlock(&p->nd);
			return (-1);
		}
		pthread_mutex_unlock(&p->nd);
		usleep(100);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_all a;

	a.i = -1;
	if (ac < 5 || ac > 6)
		return (print_exit("./invalid argument number\n", 0, 0, &a));
	while (*++av && ++a.i < 6)
	{
		a.tab[a.i] = ft_atoi(*av);
		if (a.tab[a.i] < 1 && a.i != 4)
			return (print_exit("./invalid argument\n", 0, 0, &a));
	}
	if (a.i < 4 || a.tab[4] < 1)
		a.tab[4] = 0;
	a.x = init_threads(&a);
	if (a.x)
		return (print_exit("./malloc error\n", 0, a.x, &a));
	a.i = -1;
	a.start = gettime(&a);
	while (++a.i < a.tab[0])
	{
		if (pthread_create(&(a.phi[a.i].t_id), NULL, ft_routine,\
		(void *)&a.phi[a.i]))
			return (print_exit("./thread creation error\n", 1, 2, &a));
	}
	return (loop_checker(&a));
}
