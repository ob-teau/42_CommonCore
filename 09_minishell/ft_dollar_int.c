/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:48:00 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 14:00:24 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int	find_first_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$')
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
		}
		if (str[i])
			i++;
		if (str[i] == '$' && (!str[i + 1] || str[i + 1] == ' '))
			i++;
		if (i > 0 && str[i - 1] && str[i - 1] == '"'
			&& str[i] == '$' && str[i + 1] == '"')
			i++;
	}
	if (i == ft_strlen(str) || i == 0)
		return (-1);
	return (i);
}

static char	*ft_strdup_n(char *str, int n)
{
	int		i;
	int		j;
	int		src;
	char	*result;

	src = ft_strlen(str) - n;
	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * (src + 1));
	if (!result)
		return (NULL);
	result[src] = '\0';
	while (i < n)
		i++;
	while (str[i])
	{
		result[j] = str[i];
		i++;
		j++;
	}
	return (result);
}

char	*ft_var_ret(char *name, t_minish *m)
{
	char	*result;
	char	*varet;
	char	*sname;

	varet = ft_itoa(m->ret);
	sname = ft_strdup_n(name, 1);
	result = ft_strjoin_lib(varet, sname);
	if (result == NULL)
		return (free(varet), free(sname), NULL);
	free(varet);
	free(sname);
	return (result);
}
