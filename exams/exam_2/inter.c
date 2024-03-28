/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:52:45 by acoinus           #+#    #+#             */
/*   Updated: 2022/02/11 15:07:44 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
int	main(int ac, char **av)
{
	int	i;
	int	tab[260];

	i = 0;
	if (ac == 3)
	{
		while (i < 260)
			tab[i++] = 0;
		while (*av[2])
			tab[(int)*av[2]++] = 1;
		while (*av[1])
		{
			if (tab[(int)*av[1]] == 1)
			{
				tab[(int)*av[1]] = 0;
				write(1, av[1], 1);
			}
			++av[1];
		}
	}
	write(1, "\n",1);
	return (0);
}
*/
int	main(int ac, char **av)
{
	char	tab[260];
	int	i = 0;

	if (ac == 3)
	{
		while (i < 260)
			tab[i++] = 0;
		while (*av[2])
			tab[(int)*av[2]++] = 1;
		while (*av[1])
		{
			if (tab[(int)*av[1]] == 1)
			{
				tab[(int)*av[1]] = 0;
				write(1, av[1], 1);
			}
			++av[1];
		}
	}
	write(1, "\n", 1);
	return (0);
}
