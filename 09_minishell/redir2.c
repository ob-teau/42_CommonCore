/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:14:15 by acoinus           #+#    #+#             */
/*   Updated: 2022/05/27 16:06:03 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

static void	exit_exec_fds(t_minish *m, int i, int std_out, int std_in)
{
	if (ft_strcmp("exit", m->c[i].s[0]) == 0)
	{
		if (m->cell_nb > 1)
			pip_in_built(m, i, 0);
		else
			ft_exit(m->c[i].s, m);
	}
	else
	{
		if (m->c[i].red)
		{
			close(std_out);
			close(std_in);
		}
		ft_exec(m, i);
	}
}

void	cd_export_unset(t_minish *m, int i, int std_out, int std_in)
{
	if (ft_strcmp("cd", m->c[i].s[0]) == 0)
	{
		if (m->cell_nb > 1)
			pip_in_built(m, i, 0);
		else
			builtin_cd(m->c[i].s, m);
	}
	else if (ft_strcmp("export", m->c[i].s[0]) == 0)
	{
		if (m->cell_nb > 1)
			pip_in_built(m, i, 0);
		else
			builtin_export(m->c[i].s, m);
	}
	else if (ft_strcmp("unset", m->c[i].s[0]) == 0)
	{
		if (m->cell_nb > 1)
			pip_in_built(m, i, 0);
		else
			builtin_unset(m->c[i].s, m, 1, 0);
	}
	else
		exit_exec_fds(m, i, std_out, std_in);
}
