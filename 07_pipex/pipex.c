/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:38:42 by acoinus           #+#    #+#             */
/*   Updated: 2022/01/13 11:17:30 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(t_info *f)
{
	if (access(f->av[4], F_OK) != 0
		|| (access(f->av[4], R_OK | W_OK) != 0 && !unlink(f->av[4])))
		f->fd_old[1] = open(f->av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		f->fd_old[1] = open(f->av[4], O_RDWR | O_TRUNC);
	dup2(f->pip_fd[0], 0);
	dup2(f->fd_old[1], 1);
	close(f->fd_old[1]);
	close(f->pip_fd[1]);
	close(f->pip_fd[0]);
	execve(f->cd2[0], f->cd2, f->ev);
}

int	ft_fork(t_info *f)
{
	f->pid[0] = fork();
	if (f->pid[0] < 0)
		return (1);
	if (f->pid[0] == 0)
	{
		f->fd_old[0] = open(f->av[1], O_RDONLY);
		dup2(f->fd_old[0], 0);
		dup2(f->pip_fd[1], 1);
		close(f->fd_old[0]);
		close(f->pip_fd[0]);
		close(f->pip_fd[1]);
		execve(f->cd1[0], f->cd1, f->ev);
	}
	f->pid[1] = fork();
	if (f->pid[1] < 0)
		return (1);
	if (f->pid[1] == 0)
		ft_child(f);
	close(f->pip_fd[0]);
	close(f->pip_fd[1]);
	waitpid(f->pid[0], NULL, 0);
	waitpid(f->pid[1], NULL, 0);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_info	f;

	f.av = av;
	f.ev = env;
	if (ac != 5 || access(av[1], F_OK) || access(av[1], R_OK | W_OK) || !env[0])
		return (1);
	f.i = -1;
	while (env[++f.i])
		if (env[f.i][0] == 'P' && env[f.i][1] == 'A' && env[f.i][2] == 'T'
		&& env[f.i][3] == 'H' && env[f.i][4] == '=')
			f.p = split_add(&env[f.i][5], ':');
	if (f.p == NULL)
		return (1);
	if (get_path(&f) || pipe(f.pip_fd) == -1 || ft_fork(&f))
		return (ft_free(&f, 1));
	return (ft_free(&f, 0));
}
