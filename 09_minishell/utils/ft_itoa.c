/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:31:11 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/26 19:12:15 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

static size_t	ft_lenght(long int nb)
{
	size_t	l;

	l = 0;
	if (nb > -1 && nb <= 0)
	{
		l++;
		return (l);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		l++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	size_t		l;
	char		*str;
	long int	nb;

	nb = n;
	l = ft_lenght((long int)n);
	str = (char *)malloc(sizeof(char) * l + 1);
	if (!str)
		return (0);
	str[l] = '\0';
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	l--;
	while (nb >= 10)
	{
		str[l] = nb % 10 + '0';
		nb = nb / 10;
		l--;
	}
	str[l] = nb % 10 + '0';
	return (str);
}
