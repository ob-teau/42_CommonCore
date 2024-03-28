/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:53:35 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 17:43:45 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

static char	*boucle2(char *s, t_minish *m, int i, char r)
{
	if (s[i] && (s[i] == '<' || s[i] == '>'))
	{
		r = s[i];
		if (s[i + 1] == r)
			i++;
		if (s[i + 1] == '\0')
		{
			printf("syntax error\n");
			return (NULL);
		}
		while (s[++i])
		{
			if (s[i] == ' ')
				i++;
			if (s[i] == '<' || s[i] == '>' || s[i] == '\0')
			{
				printf("syntax error\n");
				return (NULL);
			}
			if (s[i] != ' ' || s[i] != '<' || s[i] != '>')
				break ;
		}
	}
	m->si = i;
	return (s);
}

static char	*check_boucle(char *s, t_minish *m)
{
	int		i;
	char	r;

	r = '\0';
	i = 0;
	while (s && s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			m->q = s[i];
			i++;
			while (s[i] && s[i] != m->q)
				i++;
			if (s[i] && s[i + 1])
				i++;
		}
		s = boucle2(s, m, i, r);
		if (!s)
			return (NULL);
		i = m->si;
		if (s[i])
			i++;
	}
	return (s);
}

int	check_quote(char *s, t_minish *m, int i)
{
	int		quo;

	quo = 0;
	while (s[i] == ' ')
		i++;
	if (s && ((s[i] && s[i] == '"' && s[i + 1] && s[i + 1] == '"')
			|| (s[i] && s[i] == '\'' && s[i + 1] && s[i + 1] == '\'')))
		return (-1);
	s = check_boucle(s, m);
	if (s == NULL)
		return (-1);
	i = -1;
	while (s && s[++i])
	{
		if ((s[i] == '\'' || s[i] == '\"') && quo == 0)
		{
			m->q = s[i];
			quo++;
		}
		else if (quo != 0 && s[i] == m->q)
			quo--;
	}
	if (quo == 1)
		return (-1);
	return (0);
}
