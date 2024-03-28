/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:00:19 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 09:43:48 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

static char	*get_name_var(char *str, int x)
{
	char	*name;
	int		i;

	i = 0;
	while (str[x + i + 1] && str[x + i + 1] != ' ' && str[x + i + 1] != '"'
		&& str[x + i + 1] != '|' && str[x + i + 1] != '\''
		&& str[x + i + 1] != '$')
		i++;
	name = malloc(sizeof(char) * i + 1);
	if (!name)
		return (NULL);
	name[i] = 0;
	i = 0;
	while (str[x + i + 1] && str[x + i + 1] != ' ' && str[x + i + 1] != '"'
		&& str[x + i + 1] != '|' && str[x + i + 1] != '\''
		&& str[x + i + 1] != '$')
	{
		name[i] = str[x + i + 1];
		i++;
	}
	return (name);
}

static char	*get_expand(char *name, t_minish *m)
{
	char	*str;
	int		i;

	i = -1;
	if (name[0] == '?')
	{	
		return (ft_var_ret(name, m));
	}
	while (m->sauv_env[++i])
		if (!ft_strncmp(name, m->sauv_env[i], ft_strlen(name)))
			break ;
	if (!m->sauv_env[i])
	{
		str = malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	str = ft_strdup(&m->sauv_env[i][ft_strlen(name) + 1]);
	return (str);
}

static char	*get_str2(char *inpt, char *expand, char *name, char *str)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	x = find_first_dollar(inpt);
	while (++i < x)
		str[i] = inpt[i];
	j = 0;
	while (expand[j])
	{
		str[i] = expand[j];
		i++;
		j++;
	}
	while (inpt[x + ft_strlen(name) + 1])
	{
		str[i] = inpt[x + ft_strlen(name) + 1];
		i++;
		x++;
	}
	free(name);
	name = NULL;
	return (str);
}

static char	*get_str(char *inpt, t_minish *m)
{
	char	*name;
	char	*expand;
	char	*str;

	name = get_name_var(inpt, find_first_dollar(inpt));
	expand = get_expand(name, m);
	str = malloc(sizeof(char) * (ft_strlen(inpt) - ft_strlen(name) - 1
				+ ft_strlen(expand) + 1));
	if (!str)
	{
		free(expand);
		return (free(name), write(2, "Malloc failure\n", 15), NULL);
	}
	str[ft_strlen(inpt) - ft_strlen(name) - 1 + ft_strlen(expand)] = '\0';
	str = get_str2(inpt, expand, name, str);
	free(expand);
	expand = NULL;
	free(inpt);
	return (str);
}

char	*ft_dollar(char *inpt, t_minish *m)
{
	char	*str;

	if (find_first_dollar(inpt) == -1)
		return (inpt);
	str = get_str(inpt, m);
	while (find_first_dollar(str) != -1)
	{
		str = get_str(str, m);
	}
	return (str);
}
