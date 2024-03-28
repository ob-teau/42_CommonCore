/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:22:58 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/26 23:45:15 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

static int	get_pwd(char **cmd, char **oldpwd, t_minish *m)
{	
	if (chdir(cmd[1]) != 0)
	{
		return (ft_perror("cd", 1));
	}
	oldpwd[0] = NULL;
	oldpwd[0] = getcwd(NULL, 256);
	if (oldpwd[0] == NULL)
		return (-1);
	oldpwd[1] = ft_strjoin_lib("PWD=", oldpwd[0]);
	builtin_export(oldpwd, m);
	free(oldpwd[1]);
	free(oldpwd[0]);
	return (0);
}

int	builtin_cd(char **cmd, t_minish *m)
{
	char	*oldpwd[3];

	oldpwd[0] = NULL;
	oldpwd[2] = NULL;
	oldpwd[0] = getcwd(NULL, 256);
	if (oldpwd[0] == NULL)
		return (1);
	oldpwd[1] = ft_strjoin_lib("OLDPWD=", oldpwd[0]);
	builtin_export(oldpwd, m);
	free(oldpwd[0]);
	free(oldpwd[1]);
	if (!cmd[1])
	{
		errno = 2;
		return (1);
	}
	if (cmd[2])
	{
		printf("cd: too many arguments\n");
		return (1);
	}
	if (get_pwd(cmd, oldpwd, m) == -1)
		return (1);
	return (0);
}
