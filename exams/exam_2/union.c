/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:54:03 by acoinus           #+#    #+#             */
/*   Updated: 2022/02/11 15:14:47 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
int main (int ac, char **av)
{
	int	tab[260];
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (i < 260)
			tab[i++] = 0;
		i = 0;
		while (++i < 3)
		{
			while (*av[i])
			{
				if (!tab[(int)*av[i]])
				{
					tab[(int)*av[i]] = 1;
					write(1, av[i], 1);
				}
				++av[i];
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}*/

int	main(int ac, char **av)
{
	int	tab[260];
	int	i = 0;

	if (ac == 3)
	{
		while (i < 260)
			tab[i++] = 0;
		i = 0;
		while (++i < 3)
		{
			while (*av[i])
			{
				if (!tab[(int)*av[i]])
					{
						tab[(int)*av[i]] = 1;
						write(1, av[i], 1);
					}
			++av[i];
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
