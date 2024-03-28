/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:29:33 by alice             #+#    #+#             */
/*   Updated: 2021/09/02 15:31:16 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int	ft_strchr(const char *s, int c, t_info *info)
{
	int		i;
	char	find;

	find = (unsigned char) c;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == find)
		{
			info->type = find;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*d;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	d = (char *)malloc(sizeof(char) * len + 1);
	if (!d)
		return (NULL);
	else
	{
		i = 0;
		while (s[i])
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	return (d);
}

char	*ft_strjoin(char *s1, char *s2, int free_str)
{
	char	*res;
	int		i;
	int		j;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (0);
	i = -1;
	while (++i < len_s1)
		res[i] = s1[i];
	if (free_str == 1)
		free(s1);
	j = 0;
	while (j < len_s2)
		res[i++] = s2[j++];
	if (free_str == 2)
		free(s2);
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
