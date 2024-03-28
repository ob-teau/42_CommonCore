/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:56:21 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 10:22:58 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	ft_strncmp2(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	if (i == n && s1[i] == '=')
		return (0);
	return (-1);
}

int	ft_strncmp3(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	if (i == n && s1[i] == '\0')
		return (0);
	if (i == n && s1[i] == '=')
		return (0);
	return (-1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;
	size_t			cmp;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	cmp = 0;
	if (n == 0)
		return (0);
	while (cmp < n)
	{
		if (d1[cmp] == '\0')
			return ((int)d1[cmp] - (int)d2[cmp]);
		if (d1[cmp] != d2[cmp])
			return ((int)d1[cmp] - (int)d2[cmp]);
		cmp++;
	}
	return (0);
}
