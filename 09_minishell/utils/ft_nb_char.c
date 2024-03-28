/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:14:02 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 10:25:13 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	ft_nb_char(char const *s, char c, int i)
{
	int		len;
	char	cquo;

	len = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			cquo = s[i];
			i++;
			while (s[i] != cquo)
			{
				i++;
				len++;
			}
			if (s[i] == cquo)
				i++;
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
