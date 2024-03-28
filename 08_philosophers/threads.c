/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:34:13 by alice             #+#    #+#             */
/*   Updated: 2022/04/02 11:22:03 by alice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	pasta(t_philo *p)
{
	pthread_mutex_lock(&p->a->forks[p->id - 1]);
	print_lock("has taken a fork", p, p->a);
	pthread_mutex_lock(&p->nd);
	if ((p->end || p->a->tab[0] == 1) && !pthread_mutex_unlock(&p->nd))
	{
		pthread_mutex_unlock(&p->a->forks[p->id - 1]);
		return;
	}
	pthread_mutex_unlock(&p->nd);
	pthread_mutex_lock(&p->a->forks[p->id % p->a->tab[0]]);
	print_lock("has taken a fork", p, p->a);
	if (++p->p_enb == p->a->tab[4])
		p->a->eat_nb++;
	pthread_mutex_lock(&p->mtx_strt);
	p->eat_start = gettime(p->a);
	pthread_mutex_unlock(&p->mtx_strt);
	print_lock("is eating", p, p->a);
	waiting(p, p->eat_start, p->a->tab[2]);
	pthread_mutex_unlock(&p->a->forks[p->id % p->a->tab[0]]);
	pthread_mutex_unlock(&p->a->forks[p->id - 1]);
}

void	*ft_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	p->pstart = gettime(p->a);
	pthread_mutex_lock(&p->mtx_strt);
	p->eat_start = gettime(p->a);
	pthread_mutex_unlock(&p->mtx_strt);
	p->p_enb = 0;
	if (p->id % 2 && p->a->tab[0] != 1)
		waiting(p, p->pstart, p->a->tab[2]);
	while (1)
	{
		pasta(&*p);
		pthread_mutex_lock(&p->nd);
		if ((p->end || p->a->tab[0] == 1) && !pthread_mutex_unlock(&p->nd))
			break;
		pthread_mutex_unlock(&p->nd);
		p->slp_start = gettime(p->a);
		print_lock("is sleeping", p, p->a);
		waiting(p, p->slp_start, p->a->tab[3]);
		print_lock("is thinking", p, p->a);
	}
	return (NULL);
}

int	init_threads(t_all *a)
{
	a->phi = malloc(sizeof(t_philo) * a->tab[0]);
	if (!a->phi)
		return (1);
	a->forks = malloc(sizeof(pthread_mutex_t) * a->tab[0]);
	if (!a->forks)
		return (2);
	a->i = -1;
	while (++a->i < a->tab[0])
	{
		a->phi[a->i].id = a->i + 1;
		a->phi[a->i].p_enb = 0;
		a->phi[a->i].a = a;
		a->phi[a->i].end = 0;
		a->phi[a->i].eat_start = gettime(a);
		a->phi[a->i].slp_start = gettime(a);
		pthread_mutex_init(&a->phi[a->i].nd, NULL);
		pthread_mutex_init(&a->phi[a->i].mtx_strt, NULL);
		pthread_mutex_init(&a->forks[a->i], NULL);
	}
	pthread_mutex_init(&a->enb_mtx, NULL);
	pthread_mutex_init(&a->print, NULL);
	a->lock = 0;
	a->eat_nb = 0;
	return (0);
}

