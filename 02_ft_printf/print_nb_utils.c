/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:40:25 by alice             #+#    #+#             */
/*   Updated: 2021/09/02 15:50:51 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, t_info *info)
{
	if (!str)
		return (1);
	write(1, str, ft_strlen(str));
	info->res += ft_strlen(str);
	return (1);
}

char	*ft_baseset(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

char	*nb_string(int nb_len, unsigned long long nb, t_info *info)
{
	char	*s;
	int		i;

	i = 1;
	s = (char *)malloc(sizeof(char) * nb_len + 1);
	if (nb == 0)
		s[i - 1] = '0';
	while (nb)
	{
		s[nb_len - i] = ft_baseset(info->type)[nb % info->nbr_base];
		nb /= info->nbr_base;
		i++;
	}
	s[nb_len] = '\0';
	return (s);
}

int	ft_nblen(unsigned long long nb, t_info *info)
{
	int	i;

	if (nb == 0)
	{
		i = 1;
		return (i);
	}
	i = 0;
	while (nb != 0)
	{
		i++;
		nb /= info->nbr_base;
	}
	return (i);
}
