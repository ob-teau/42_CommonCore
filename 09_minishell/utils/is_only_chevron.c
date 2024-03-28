/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_chevron.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:49:30 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 17:35:43 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	is_only_chevron(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != '<' && str[i] != '>')
			return (0);
	return (1);
}

int	is_fake_ft(char *inpt)
{
	if (!ft_strcmp(inpt, "../") || !ft_strcmp(inpt, "./")
		|| !ft_strcmp(inpt, "..") || !ft_strcmp(inpt, ".")
		|| !ft_strcmp(inpt, "/"))
		return (0);
	return (1);
}
