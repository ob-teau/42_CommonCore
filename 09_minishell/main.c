/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:09:01 by cgranja           #+#    #+#             */
/*   Updated: 2022/05/27 17:35:52 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int	g_glob;

static int	main_no_inpt(t_minish *m, int ret)
{
	ret = m->ret;
	write(1, "exit\n", 5);
	return (ret);
}

static int	main_boucle(t_minish *m, char *inpt, int ret)
{
	while (1)
	{
		init(m);
		inpt = readline("\n┴┬┴┤ʘ‿ʘ)╯\n--------minishell\n> ");
		add_history(inpt);
		if (!inpt)
			return (main_no_inpt(m, ret));
		if (check_quote(inpt, m, 0) == -1 || !is_fake_ft(inpt))
		{
			ft_free_inpt(inpt);
			continue ;
		}
		if (!inpt)
		{
			perror("./");
			continue ;
		}
		inpt = ft_strings(inpt, m, -1);
		free(inpt);
		if (inpt)
		{
			ft_built(m, 0);
			ft_fre(m);
		}
	}
}

int	main(int ac, char **av, char **env)
{
	t_minish	m;
	char		*inpt;
	int			ret;

	inpt = NULL;
	ret = 0;
	g_glob = 0;
	av = NULL;
	if (ac != 1)
	{
		errno = 2;
		return (ft_perror("minishell", 1));
	}
	init(&m);
	init_env(&m, env);
	ft_sig();
	m.ret = main_boucle(&m, inpt, ret);
	rl_clear_history();
	ret = m.ret;
	ft_free_env(&m);
	ft_fre(&m);
	return (ret);
}
