/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:42:54 by alice             #+#    #+#             */
/*   Updated: 2022/04/02 11:42:11 by alice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	loop_end(t_all *a)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&a->print);
	a->lock++;
	pthread_mutex_unlock(&a->print);
	while (++i < a->tab[0])
	{
		pthread_mutex_lock(&a->phi[i].nd);
		a->phi[i].end++;
		pthread_mutex_unlock(&a->phi[i].nd);
	} 
	return (print_exit("", 1, 2, a));
}

int	loop_checker(t_all *a)
{
	int	i;

	usleep(15000);
	while (1)
	{
		if (a->tab[4] && a->eat_nb >= a->tab[0])
		{
			return (loop_end(a));
		}
		i = -1;
		while (++i < a->tab[0])
		{
			pthread_mutex_lock(&a->phi[i].mtx_strt);
			if ((gettime(a) - a->phi[i].eat_start) > a->tab[1])
			{
				pthread_mutex_unlock(&a->phi[i].mtx_strt);
				print_lock("died", &a->phi[i], a);
				return (loop_end(a));
			}
			pthread_mutex_unlock(&a->phi[i].mtx_strt);
		}
	}
	return (print_exit("", 1, 2, a));
}

void	print_lock(char *s, t_philo *p, t_all *a)
{
	long long	event;

	pthread_mutex_lock(&a->print);
	if (!a->lock)
	{
		event = gettime(a) - a->start;
		printf("%lld %d %s\n", event, p->id, s);
	}
	pthread_mutex_unlock(&a->print);
	return ;
}

int	print_exit(char *s, int j, int fr, t_all *a)
{
	int	i;

	i = -1;
	while (s && s[++i])
		write(1, &s[i], 1);
	i = -1;
	if (j)
		while (++i < a->tab[0])
			pthread_join(a->phi[i].t_id, NULL);
	if (fr)
	{
		if (fr == 2)
			if (a->forks)
				free(a->forks);
		if (a->phi)
			free(a->phi);
	}
	return (0);
}
