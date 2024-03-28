/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:19:29 by acoinus           #+#    #+#             */
/*   Updated: 2022/05/27 14:42:25 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void	fds_heredoc(t_cell *c)
{
	int	i;

	i = -1;
	while (c->red && c->red[++i])
	{
		if (get_redir_type(c->red[i]) == 4)
		{
			if (c->dent)
				close(c->dent);
			c->dent = heredoc(&c->red[i][2]);
		}
	}
}

void	init_redir(t_cell *c)
{
	c->ent = 0;
	c->dent = 0;
	c->sor = 0;
	c->dsor = 0;
}

int	get_fds(t_minish *m)
{
	int	i;

	i = -1;
	while (++i < m->cell_nb)
	{
		if (&m->c[i] == NULL)
			return (1);
		if (!create_files(&m->c[i]))
			return (0);
		if (!fill_fds(&m->c[i]))
			return (0);
	}
	return (1);
}
