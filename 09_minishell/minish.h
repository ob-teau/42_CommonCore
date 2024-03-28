/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:09:17 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 17:36:57 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"

extern int	g_glob;

typedef struct s_minish
{
	int				ret;
	int				pip;
	int				cell_nb;
	char			**path;
	char			*newpath;
	char			**m_env;
	char			**sauv_env;
	int				size_env;
	int				size;
	int				l;
	int				std_out;
	int				std_in;
	int				idx[3];
	struct s_cell	*c;
	int				si;
	int				sj;
	char			q;
}	t_minish;

typedef struct s_cell
{
	int				ent;
	int				dent;
	int				sor;
	int				dsor;
	char			**s;
	char			**red;
	int				pipe[2];
}	t_cell;

void	ft_builtin(char **cmd);
void	print_tab(t_minish *m);
void	ft_fre(t_minish *m);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		check(char *s);
int		ft_strlen(char *str);
void	ft_built(t_minish *m, int i);
char	**ft_split_quote(char const *s, char c, t_minish *m);
char	**ft_split_pipe(char	const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_sig(void);
int		ft_exit(char **tab, t_minish *m);
int		ft_isalnum(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		init_env(t_minish *m, char **env);
void	init(t_minish *m);
int		ft_perror(char	*s, int x);
void	ft_free_env(t_minish *m);
void	ft_free_menv(t_minish *m);
char	**ft_split(char const *s, char c);
void	ft_fre(t_minish *m);
char	*ft_strings(char *s, t_minish *m, int i);
int		check_quote(char *s, t_minish *m, int i);
void	get_tabs(t_cell *c);

/*
 * *********************DOLLARS*******************************
 */

char	*ft_dollar(char *s, t_minish *m);
char	*ft_var_ret(char *name, t_minish *m);
int		find_first_dollar(char *str);

/*
 * **********************BUILTINS*********************************
 */

int		builtin_pwd(t_minish *m);
int		builtin_env(char **cmd, t_minish *m);
void	builtin_unset_error(char *cmd, t_minish *m);
int		builtin_unset(char **cmd, t_minish *m, int i, int j);
int		builtin_export(char **cmd, t_minish *m);
int		builtin_export_var(char **cmd, t_minish *m, int i, int j);
int		builtin_exp_replace(char *cmd, t_minish *m);
int		add_new_variable(t_minish *m, int *line, int j, int i);
int		builtin_echo(char **cmd, t_minish *m);
int		builtin_cd(char **cmd, t_minish *m);
int		env_shlvl(t_minish *m);
void	ft_free_only_env(t_minish *m);

/*
 * ************************UTILS************************************
 */

char	*ft_strdup(char *str);
char	*ft_strjoin_lib(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr_fd_n(char *s, int n, int fd);
void	ft_putstr_fd_aftern(char *s, int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		is_fake_ft(char *inpt);
int		ft_strncmp2(char *s1, char *s2, int n);
int		ft_strncmp3(char *s1, char *s2, int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strcmp2(const char *s1, const char *s2);
char	*ft_itoa(int n);
char	*ft_strcatf(char *str1, char *str2, int f);
int		ft_strlen(char *str);
int		ft_nb_char(char const *s, char c, int i);
void	ft_free_inpt(char *inpt);
int		is_only_chevron(char *str);

/*
 * *************************	PIPES****************************
*/

void	ft_pipe(t_minish *m, int x);
void	ft_pipe_builtin(t_minish *m, int x);
int		check_access(t_minish *m, char **cmd);
void	ft_redir_files(t_cell *c);
void	close_fd_redir(t_cell c);
void	ft_check_path(t_minish *m, char **cmd, int x);
int		pip_in_built(t_minish *m, int x, int idx);
void	ft_exec(t_minish *m, int x);
void	cd_export_unset(t_minish *m, int i, int std_out, int std_in);

/*
 * ************************REDIRECTIONS*************************
 */
int		get_redir_type(char *str);
int		create_files(t_cell *c);
int		heredoc(char *str);
int		fill_fds(t_cell *c);
int		get_fds(t_minish *m);
void	init_redir(t_cell *c);
void	fds_heredoc(t_cell *c);

#endif
