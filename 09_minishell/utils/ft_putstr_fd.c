/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:12:13 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/23 16:05:33 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i] && s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putstr_fd_n(char *s, int n, int fd)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i] && i <= n)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putstr_fd_aftern(char *s, int n, int fd)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (i <= n)
		i++;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
