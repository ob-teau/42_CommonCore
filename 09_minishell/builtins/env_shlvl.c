/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:49:17 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/26 19:32:07 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

static int	ft_atoi(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		if ((i == 9 && str[i] >= '8') || i > 9)
			return (-2);
		i++;
	}
	if (str[i])
		return (-2);
	return (result);
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
		return (0);
	result[src] = '\0';
	while (j < n)
		j++;
	while (str[j] != '\0')
	{
		result[i] = str[j];
		i++;
		j++;
	}
	return (result);
}

static char	*line_to_find(char *cmd, t_minish *m)
{
	int		sizecmd;
	int		j;
	char	*result;

	sizecmd = 0;
	j = 0;
	result = NULL;
	while (cmd[sizecmd] != '\0')
		sizecmd++;
	while (m->sauv_env[j] && (ft_strncmp2(m->sauv_env[j], cmd, sizecmd) != 0))
		j++;
	if (!m->sauv_env[j])
		return (NULL);
	result = ft_strdup_n(m->sauv_env[j], 6);
	return (result);
}

static int	env_shlvl_2(char **shlvl, char *tofind, char *str2, t_minish *m)
{
	if (str2 == NULL)
		str2 = ft_strdup("1");
	free(tofind);
	tofind = ft_strdup("SHLVL=");
	shlvl[1] = ft_strjoin_lib(tofind, str2);
	if (shlvl[1] == NULL)
		return (free(str2), -1);
	builtin_export(shlvl, m);
	free(str2);
	free(tofind);
	free(shlvl[0]);
	free(shlvl[1]);
	return (0);
}

int	env_shlvl(t_minish *m)
{
	char	*(shlvl[3]);
	int		lvl;
	char	*tofind;
	char	*find;
	char	*str2;

	shlvl[0] = ft_strdup("export");
	shlvl[1] = NULL;
	shlvl[2] = NULL;
	tofind = ft_strdup("SHLVL");
	str2 = NULL;
	find = NULL;
	lvl = 0;
	find = line_to_find(tofind, m);
	if (find == NULL)
		lvl = 1;
	else
	{
		lvl = ft_atoi(find);
		free(find);
		lvl++;
	}
	str2 = ft_itoa(lvl);
	return (env_shlvl_2(shlvl, tofind, str2, m));
}
