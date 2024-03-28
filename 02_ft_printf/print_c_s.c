/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:40:30 by acoinus           #+#    #+#             */
/*   Updated: 2021/09/01 16:10:56 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(char *s, t_info *info)
{
	int		is_width;
	int		i;

	i = 0;
	is_width = 0;
	if (s == NULL)
		s = "(null)";
	if (info->prec == -1 || (int)ft_strlen(s) < info->prec)
		info->prec = ft_strlen(s);
	if (info->width <= info->prec)
		info->width = info->prec;
	is_width = info->width - info->prec;
	if (info->minus == 1)
	{
		while (s[i] && i < info->prec)
			ft_putchar(s[i++], info);
	}
	while (is_width-- > 0)
		ft_putchar(' ', info);
	if (info->minus == 0)
	{
		while (s[i] && i < info->prec)
			ft_putchar(s[i++], info);
	}
}

void	print_c_percent(int c, t_info *info)
{
	int	len;

	len = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		ft_putchar(c, info);
	while (++len < info->width)
	{
		if (info->zero == 1)
			ft_putchar('0', info);
		if (info->zero == 0)
			ft_putchar(' ', info);
	}
	if (info->minus == 0)
		ft_putchar(c, info);
}
