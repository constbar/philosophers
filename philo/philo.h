#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_phil
{
	int					id;
	int					ev;
	int					st;
	int					num_eat;
	int					is_dead;
	uint64_t			lst_eat;
	uint64_t			start_sim;
	pthread_t			thread;
	struct s_main_st	*m;
	pthread_mutex_t		*print;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;

}				t_phil;

typedef struct s_main_st
{
	int					num_philos;
	int					must_to_eat;
	uint64_t			start_time;
	uint64_t			time_of_die;
	uint64_t			time_of_eat;
	uint64_t			time_of_slp;
	t_phil				*philos;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
}				t_main_st;

int				ft_isnm(char *str);
void			*ft_actions(void *st);
int				ft_atoi(const char *str);
int				ft_init_forks(t_main_st *m);
int				ft_malloc_philos(t_main_st *m);
void			ft_wait_time(uint64_t time);
uint64_t		ft_diff_time(uint64_t start);
void			ft_print_state(t_phil *p, char *state);
int				ft_parsing(t_main_st *m, char **str, int argc);
#endif