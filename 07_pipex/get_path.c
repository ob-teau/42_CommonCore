/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:25:05 by acoinus           #+#    #+#             */
/*   Updated: 2022/01/13 11:18:19 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_msg(int x)
{
	if (x == -1)
		write(1, "command not found\n", 18);
	return (1);
}

int	ft_free(t_info *f, int x)
{
	int	i;

	i = -1;
	while (f->p[++i])
		free(f->p[i]);
	free(f->p);
	i = -1;
	if (f->cd1)
	{
		while (f->cd1[++i])
			free(f->cd1[i]);
		free(f->cd1);
	}
	i = -1;
	if (f->cd2)
	{
		while (f->cd2[++i])
			free(f->cd2[i]);
		free(f->cd2);
	}
	return (x);
}

int	path_check(char *s_cd, char **cd, t_info *f)
{
	char	*tmp;

	s_cd = ft_strjoin(f->p[f->i], cd[0]);
	if (s_cd == NULL)
		return (1);
	if (!access(s_cd, F_OK) || !access(s_cd, X_OK))
	{
		free(s_cd);
		tmp = cd[0];
		cd[0] = ft_strjoin(f->p[f->i], tmp);
		free(tmp);
		return (0);
	}
	free(s_cd);
	return (-1);
}

int	get_path(t_info *f)
{
	int	x;

	f->cd1 = ft_split(f->av[2], ' ');
	f->cd2 = ft_split(f->av[3], ' ');
	if (f->cd1 == NULL || f->cd2 == NULL)
		return (1);
	f->i = -1;
	x = -1;
	while (f->p[++f->i] && x == -1)
		x = path_check(f->s_cd1, f->cd1, f);
	if (x == 1 || x == -1)
		return (error_msg(x));
	f->i = -1;
	x = -1;
	while (f->p[++f->i] && x == -1)
		x = path_check(f->s_cd2, f->cd2, f);
	if (x == 1 || x == -1)
		return (error_msg(x));
	return (0);
}
