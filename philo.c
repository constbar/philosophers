#include "philo.h"

static int	ft_death_status(t_main_st *m)
{
	int	i;

	i = 0;
	while (i < m->num_philos)
	{
		if (m->philos[i].st != -1)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_death_cheker(t_main_st *m)
{
	int	i;

	while (21)
	{
		i = 0;
		while (i < m->num_philos)
		{
			if (m->philos[i].num_eat != 0 && (ft_diff_time(0)
					- m->philos[i].lst_eat) >= m->time_of_die)
			{
				m->philos[i].is_dead = 1;
				pthread_mutex_lock(m->philos[i].print);
				printf("%llu ms %d died\n", (ft_diff_time(m->start_time)),
					m->philos[i].id);
				return ;
			}
			else if (!ft_death_status(m))
			{
				return ;
			}
			i++;
		}
		usleep(1);
	}
}

static void	ft_start(t_main_st *m)
{
	int	i;

	i = 0;
	m->start_time = ft_diff_time(0);
	while (i < m->num_philos)
	{
		m->philos[i].start_sim = ft_diff_time(0);
		m->philos[i].lst_eat = ft_diff_time(0);
		if (pthread_create(&m->philos[i].thread, NULL,
				ft_actions, &m->philos[i]) != 0)
			return ;
		i++;
	}
	ft_death_cheker(m);
	i = 0;
	while (i < m->num_philos)
	{
		pthread_detach(m->philos[i].thread);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	t_main_st	m;

	if (argc < 5 || argc > 6)
	{
		printf("incorrect num of vars\n");
		return (1);
	}
	if (!ft_parsing(&m, argv, argc))
	{
		printf("errors with vars in parsing\n");
		return (1);
	}
	if (ft_init_forks(&m))
		return (1);
	if (ft_malloc_philos(&m))
		return (1);
	ft_start(&m);
	i = -1;
	while (++i < m.num_philos)
		pthread_mutex_destroy(m.forks);
	pthread_mutex_destroy(&m.print);
	free(m.forks);
	free(m.philos);
	return (0);
}
