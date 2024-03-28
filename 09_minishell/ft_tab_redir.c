/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:59:49 by acoinus           #+#    #+#             */
/*   Updated: 2022/05/27 13:51:23 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

/*int	is_only_chevron(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != '<' && str[i] != '>')
			return (0);
	return (1);
}*/

void	fill_cmd(char **new_cmd, char **cmd)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (i > 0)
		{
			if (cmd[i][0] != '>' && cmd[i][0] != '<'
					&& !is_only_chevron(cmd[i - 1]))
				new_cmd[j++] = ft_strdup(cmd[i]);
		}
		else
			if (cmd[i][0] != '>' && cmd[i][0] != '<')
				new_cmd[j++] = ft_strdup(cmd[i]);
		i++;
	}
}

char	**get_cmd(char **cmd)
{
	char	**new_cmd;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (cmd[i])
	{
		if (i > 0)
		{
			if (cmd[i][0] != '>' && cmd[i][0] != '<'
					&& !is_only_chevron(cmd[i - 1]))
				c++;
		}
		else
			if (cmd[i][0] != '>' && cmd[i][0] != '<')
				c++;
		i++;
	}
	new_cmd = (char **)malloc(sizeof(char *) * (c + 1));
	if (!new_cmd)
		return (write(2, "Failed malloc\n", 14), NULL);
	new_cmd[c] = NULL;
	fill_cmd(new_cmd, cmd);
	return (new_cmd);
}

void	fill_redir(char **new_redir, char **cmd)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i][0] == '<' || cmd[i][0] == '>')
		{
			if (is_only_chevron(cmd[i]))
			{
				new_redir[j] = ft_strdup(cmd[i]);
				i++;
				new_redir[j] = ft_strcatf(new_redir[j], cmd[i], 1);
				j++;
			}
			else
				new_redir[j++] = ft_strdup(cmd[i]);
		}
		i++;
	}
}

char	**get_redir(char **cmd)
{
	char	**new_redir;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (cmd[i])
	{
		if (cmd[i][0] == '<' || cmd[i][0] == '>')
			c++;
		i++;
	}
	if (c == 0)
		return (NULL);
	new_redir = (char **)malloc(sizeof(char *) * (c + 1));
	if (!new_redir)
		return (write(2, "Failed malloc\n", 14), NULL);
	new_redir[c] = NULL;
	fill_redir(new_redir, cmd);
	return (new_redir);
}

void	get_tabs(t_cell *c)
{
	char	**cmd;
	int		i;

	i = 0;
	cmd = get_cmd(c->s);
	c->red = get_redir(c->s);
	while (c->s[i])
	{
		free(c->s[i]);
		c->s[i] = NULL;
		i++;
	}
	free(c->s);
	c->s = cmd;
}
