/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:47:36 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 10:23:35 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	ft_strcmp2(const char *s1, const char *s2)
{
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*d1;
	unsigned char	*d2;
	size_t			cmp;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	cmp = 0;
	while (d1[cmp] && d2[cmp])
	{
		if (d1[cmp] != d2[cmp])
			return ((int)d1[cmp] - (int)d2[cmp]);
		cmp++;
	}
	if (d1[cmp] || d2[cmp])
		return ((int)d1[cmp] - (int)d2[cmp]);
	return (0);
}
