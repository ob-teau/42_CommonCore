/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:27:10 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 17:03:17 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

static void	ft_fre2(t_minish *m)
{
	int	i;

	i = 0;
	if (m->path)
	{
		while (m->path[i])
		{
			free(m->path[i]);
			m->path[i] = NULL;
			i++;
		}
		free(m->path);
		m->path = NULL;
	}
	if (m->newpath)
		free(m->newpath);
}

void	ft_fre(t_minish *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->cell_nb)
	{
		j = -1;
		while (m->c[i].s && m->c[i].s[++j])
			free(m->c[i].s[j]);
		if (m->c[i].s)
			free(m->c[i].s);
		j = -1;
		while (m->c[i].red && m->c[i].red[++j])
			free(m->c[i].red[j]);
		if (m->c[i].red)
			free(m->c[i].red);
	}
	if (m->cell_nb > 0)
		free(m->c);
	i = 0;
	ft_fre2(m);
	return ;
}
