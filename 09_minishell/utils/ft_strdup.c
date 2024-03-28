/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:49:39 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 13:38:23 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		src;
	char	*result;

	src = ft_strlen(str);
	i = 0;
	result = (char *)malloc(sizeof(char) * (src + 1));
	if (!result)
		return (NULL);
	while (str && str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
