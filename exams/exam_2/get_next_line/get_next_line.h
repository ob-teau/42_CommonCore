/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:36:50 by acoinus           #+#    #+#             */
/*   Updated: 2022/02/11 10:49:32 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct	s_info
{
	char	*line;
	char	save[BUFFER_SIZE + 1];
	int	fd;
	int	i_line;
	int	i;
	int	x_r;
	int	x_n;
}	t_info;

int	ft_strlen(char *s);

#endif
