/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:49:11 by acoinus           #+#    #+#             */
/*   Updated: 2022/01/13 11:20:05 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
//# include "libft/libft.h"

typedef struct s_info
{
	char	**av;
	char	**ev;
	char	**p;
	int		i;
	char	**cd1;
	char	**cd2;
	char	*s_cd1;
	char	*s_cd2;
	int		pip_fd[2];
	int		pid[2];
	int		fd_old[2];
}	t_info;

int		get_path(t_info *f);
int		ft_free(t_info *f, int x);
char	**split_add(char *s, char c);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif
