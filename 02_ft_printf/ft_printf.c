/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:10:40 by acoinus           #+#    #+#             */
/*   Updated: 2021/09/02 15:27:42 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_info *info)
{
	if ((write(1, &c, 1)) != 0)
		info->res++;
	return (1);
}

void	init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->type = 0;
	info->sign = 1;
	info->nbr_base = 10;
	info->is_width = 0;
	info->is_prec = 0;
}

void	parse_flag(const char *content, t_info *info, va_list ap)
{
	if (content[info->i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (content[info->i] == '-')
		info->minus = 1;
	else if (content[info->i] == '.')
		info->prec = 0;
	else if (ft_isdigit(content[info->i]) || content[info->i] == '*')
		check_width_prec(content, info, ap);
	if (info->prec < 0)
		info->prec = -1;
}

void	init_parsing(va_list ap, const char *content, t_info *info)
{
	info->i = 0;
	info->res = 0;
	while (content[info->i] != '\0')
	{
		while (content[info->i] != '%' && content[info->i] != '\0')
			ft_putchar(content[info->i++], info);
		if (content[info->i] == '%')
		{
			init_info(info);
			while (content[++info->i] != '\0' \
					&& !(ft_strchr(TYPE, content[info->i], info)))
				parse_flag(content, info, ap);
			info->type = content[info->i++];
			if ((info->minus == 1 || info->prec > -1))
				info->zero = 0;
			parse_type(ap, info);
		}
	}
}

int	ft_printf(const char *content, ...)
{
	va_list	ap;
	t_info	*info;

	info = malloc(sizeof(t_info) * 1);
	if (info == NULL)
		return (0);
	va_start(ap, content);
	init_parsing(ap, content, info);
	va_end(ap);
	free(info);
	return (info->res);
}
