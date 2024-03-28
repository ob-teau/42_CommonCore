#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"


typedef struct	s_philo
{
	int				end;
	int				id;
	int				p_enb; // philo eat number
	pthread_t		t_id;
	struct s_all	*a;
	long long		eat_start;
	long long		slp_start;
	long long		pstart;
	pthread_mutex_t	mtx_strt;
	pthread_mutex_t	nd;
}	t_philo;

typedef struct	s_all
{
	int	eat_nb;
	int	tab[5]; // pnb | ttd | tte | tts | enb
	int	i;
	int	x;
	int	lock;
	long long		start;
	struct timeval	tmv;
	struct s_philo	*phi;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	enb_mtx;
}	t_all;

/****************************MAIN***************************/

int	waiting(t_philo *p, long long b, int c);
void	pasta(t_philo *p);
int	loop_checker(t_all *a);
void	*ft_routine(void *arg);
int init_threads(t_all *a);

/***************************UTILS**************************/

int		loop_end(t_all *a);
void	print_lock(char *s, t_philo *p, t_all *a);
int	loop_checker(t_all *a);
long long	gettime(t_all *a);
int	ft_atoi(char *s);
int	print_exit(char *s, int j, int fr, t_all *a);

#endif
