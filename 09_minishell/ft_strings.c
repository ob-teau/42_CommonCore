/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:42:48 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 14:50:23 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

static char	*ft_string3(char *s, t_minish *m)
{
	int	j;
	int	i;
	int	x;

	x = -1;
	m->cell_nb = m->pip + 1;
	m->c = malloc(sizeof(t_cell) * m->cell_nb);
	if (!m->c)
		return (free(s), NULL);
	j = -1;
	i = 0;
	while (++x < m->cell_nb)
	{
		m->c[x].s = ft_split_quote(&s[i], ' ', m);
		get_tabs(&m->c[x]);
		while (s[i] != '\0')
			i++;
		i++;
	}
	return (s);
}

static char	*ft_string22(char *s, t_minish *m)
{
	if (s[m->si] && s[m->si] == '|')
	{
		m->sj = m->si + 1;
		while (s[m->sj] && (s[m->sj] == ' ' || s[m->sj] == '|'))
			m->sj++;
		if (!s[m->sj])
		{
			printf("syntax error\n");
			return (free(s), NULL);
		}
		m->pip++;
		s[m->si] = '\0';
		m->si++;
	}
	if (s[m->si])
		m->si++;
	return (s);
}

static char	*ft_string2(char *s, t_minish *m)
{
	char	q;

	m->si = 0;
	m->sj = -1;
	while (s && s[m->si])
	{
		if (s[m->si] && (s[m->si] == '"' || s[m->si] == '\''))
		{
			q = s[m->si];
			m->si++;
			while (s[m->si] && s[m->si] != q)
				m->si++;
			m->si++;
		}
		s = ft_string22(s, m);
	}
	return (s);
}

char	*ft_strings(char *s, t_minish *m, int i)
{
	int		sz;

	sz = ft_strlen(s);
	if (sz == 0)
		return (free(s), NULL);
	s = ft_dollar(s, m);
	while (s && s[++i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] && s[i] == '|')
		{
			printf("syntax error\n");
			return (free(s), NULL);
		}
		else if (!s[i])
			return (free(s), NULL);
		else
			break ;
	}
	s = ft_string2(s, m);
	s = ft_string3(s, m);
	return (s);
}
