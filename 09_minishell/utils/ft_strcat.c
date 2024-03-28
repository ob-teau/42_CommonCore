/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:14:43 by acoinus           #+#    #+#             */
/*   Updated: 2022/05/27 17:41:33 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	free_strcat(char *str1, char *str2, int f)
{
	if (f == 1)
		free(str1);
	if (f == 2)
		free(str2);
	if (f == 3)
	{
		free(str1);
		free(str2);
	}
}

char	*ft_strcatf(char *str1, char *str2, int f)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str)
		return (free_strcat(str1, str2, f), NULL);
	str[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	i = 0;
	j = 0;
	while (str1[i])
		str[j++] = str1[i++];
	i = 0;
	while (str2[i])
		str[j++] = str2[i++];
	free_strcat(str1, str2, f);
	return (str);
}
