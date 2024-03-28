/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:16:40 by alice             #+#    #+#             */
/*   Updated: 2021/09/02 16:08:49 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nb3(unsigned long long nb, char *nb_s, t_info *info)
{
	if (info->type == 'p')
	{
		ft_putchar('0', info);
		ft_putchar('x', info);
	}
	if ((info->type == 'd' || info->type == 'i') && info->sign == -1)
		ft_putchar('-', info);
	while (info->is_prec-- > 0 || (info->is_width-- >= 0 \
		&& info->zero == 1))
		ft_putchar('0', info);
	if (!(info->prec == 0 && nb == 0))
		ft_putstr(nb_s, info);
	while (info->minus == 1 && info->is_width-- >= 0)
		ft_putchar(' ', info);
}

void	print_nb2(unsigned long long nb, char *nb_s, int nb_len, t_info *info)
{
	info->is_prec = info->prec - nb_len;
	info->is_width = info->width - nb_len;
	if (info->is_width > 0 && info->is_prec > 0)
		info->is_width -= info->is_prec;
	if (info->type == 'p')
		info->is_width -= 2;
	if ((info->type == 'd' || info->type == 'i') && info->sign == -1)
		info->is_width -= 1;
	if (info->prec == 0 && nb == 0)
		info->is_width += 1;
	while (info->minus == 0 && info->is_width-- > 0 \
		&& !(info->is_width > 0 && info->zero == 1))
	{
		if (info->zero == 1 && info->sign != -1)
			ft_putchar('0', info);
		else
			ft_putchar(' ', info);
	}
	print_nb3(nb, nb_s, info);
}

void	print_nb(unsigned long long nb, t_info *info)
{
	int		nb_len;
	char	*nb_s;

	nb_s = NULL;
	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nb < 0)
	{
		info->sign = -1;
		nb = -nb;
	}
	nb_len = ft_nblen(nb, info);
	if (info->prec < nb_len && info->prec < 0)
		info->prec = -1;
	nb_s = nb_string(nb_len, nb, info);
	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		nb_len = ft_strlen(nb_s);
	if (info->width < info->prec)
		info->width = 0;
	print_nb2(nb, nb_s, nb_len, info);
	free(nb_s);
}
