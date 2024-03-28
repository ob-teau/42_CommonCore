/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prec_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:22:58 by acoinus           #+#    #+#             */
/*   Updated: 2021/09/02 15:29:29 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_type(va_list ap, t_info *info)
{
	if (info->type == '%')
		print_c_percent('%', info);
	else if (info->type == 'c')
		print_c_percent(va_arg(ap, int), info);
	else if (info->type == 's')
		print_s(va_arg(ap, char *), info);
	else if (info->type == 'd' || info->type == 'i')
		print_nb(va_arg(ap, int), info);
	else if (info->type == 'x' || info->type == 'X' || info->type == 'u')
		print_nb(va_arg(ap, unsigned int), info);
	else if (info->type == 'p')
		print_nb(va_arg(ap, unsigned long long), info);
}

void	check_width_prec(const char *content, t_info *info, va_list ap)
{
	if (ft_isdigit(content[info->i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + content[info->i] - '0';
		else
			info->prec = info->prec * 10 + content[info->i] - '0';
	}
	else if (content[info->i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width = -info->width;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
}
