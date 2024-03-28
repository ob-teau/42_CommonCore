/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:32:25 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 15:07:56 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void	handler(int keysim)
{
	if (g_glob == 0)
	{
		if (keysim == SIGQUIT)
		{
			write(1, "\b\b  \b\b", 6);
		}
		if (keysim == SIGINT)
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	if (g_glob == 1)
	{
		if (keysim == SIGQUIT)
			write(1, "quit (core dumped)", 18);
	}
}

void	ft_sig(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}
