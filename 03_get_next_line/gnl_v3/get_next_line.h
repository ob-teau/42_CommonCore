/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:07:22 by iderighe          #+#    #+#             */
/*   Updated: 2021/06/04 14:43:09 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_check_n(char *str);
char	*ft_saver(char *str);
char	*ft_strcut(char *str);
int		ft_strlen(char *s);
int		ft_strn(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
