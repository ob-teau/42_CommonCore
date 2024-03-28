/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <acoinus@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:28:10 by user42            #+#    #+#             */
/*   Updated: 2022/05/27 11:01:05 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

static int	ft_nb_str(char const *s1, char c)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (s1 && !s1[0])
		return (0);
	while (s1[i])
	{
		while (s1[i] && s1[i] == c)
			i++;
		if (!s1[i])
			break ;
		n++;
		while (s1[i] && s1[i] != c)
			i++;
	}
	return (n);
}

static char	**ft_free(char const **tab, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)tab[j]);
	}
	free(tab);
	return (NULL);
}

static char	**ft_rempli_suite(t_minish *m, char const *s, char **tab)
{
	char	cquo;

	while (s[m->idx[0]] != '\0' && s[m->idx[0]] != ' ')
	{
		if (s[m->idx[0]] == '\'' || s[m->idx[0]] == '"')
		{
			cquo = s[m->idx[0]++];
			while (s[m->idx[0]] != cquo)
				tab[m->idx[1]][m->idx[2]++] = s[m->idx[0]++];
			if (s[m->idx[0]] == cquo)
				m->idx[0]++;
		}
		else
			tab[m->idx[1]][m->idx[2]++] = s[m->idx[0]++];
	}
	return (tab);
}

static char	**ft_rempli(char const *s, char **tab, int n_str, t_minish *m)
{
	m->idx[0] = 0;
	m->idx[1] = 0;
	while (s[m->idx[0]] != '\0' && m->idx[1] < n_str)
	{
		m->idx[2] = 0;
		while (s[m->idx[0]] == ' ')
			m->idx[0]++;
		if (!s[m->idx[0]])
			break ;
		tab[m->idx[1]] = (char *)malloc(sizeof(char)
				* ft_nb_char(s, ' ', m->idx[0]) + 1);
		if (tab[m->idx[1]] == NULL)
			return (ft_free((char const **)tab, m->idx[1]));
		tab[m->idx[1]][ft_nb_char(s, ' ', m->idx[0])] = 0;
		tab = ft_rempli_suite(m, s, tab);
		tab[m->idx[1]][m->idx[2]] = '\0';
		m->idx[1]++;
	}
	tab[m->idx[1]] = NULL;
	return (tab);
}

char	**ft_split_quote(char const *s, char c, t_minish *m)
{
	char			**tab;
	unsigned int	n_str;

	if (s == NULL)
		return (NULL);
	n_str = ft_nb_str(s, c);
	tab = (char **)malloc(sizeof(char *) * (n_str + 1));
	if (!tab)
		return (NULL);
	tab[n_str] = NULL;
	return (ft_rempli(s, tab, n_str, m));
}
