#include "philo.h"

int	ft_init_forks(t_main_st *m)
{
	int	i;

	i = 0;
	m->forks = malloc(sizeof(pthread_mutex_t) * m->num_philos);
	if (!m->forks)
	{
		printf("init forks problems\n");
		return (1);
	}
	while (i < m->num_philos)
	{
		pthread_mutex_init(&m->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&m->print, NULL);
	return (0);
}

static void	ft_init_philos(t_main_st *m)
{
	int	i;

	i = 0;
	while (i < m->num_philos)
	{
		m->philos[i].id = i + 1;
		if (m->philos[i].id % 2 == 0)
			m->philos[i].ev = 1;
		else
			m->philos[i].ev = 0;
		m->philos[i].is_dead = 0;
		m->philos[i].lst_eat = 0;
		if (m->must_to_eat)
		{
			m->philos[i].num_eat = m->must_to_eat;
			m->philos[i].st = 0;
		}
		else
			m->philos[i].num_eat = -1;
		m->philos[i].l_fork = &m->forks[i];
		m->philos[i].r_fork = &m->forks[(i + 1) % m->num_philos];
		m->philos[i].m = m;
		m->philos[i].print = &m->print;
		i++;
	}
}

int	ft_malloc_philos(t_main_st *m)
{
	m->philos = malloc(sizeof(t_phil) * m->num_philos);
	if (!m->philos)
	{
		printf("init philos problems\n");
		return (1);
	}
	ft_init_philos(m);
	return (0);
}

int	ft_parsing(t_main_st *m, char **s, int argc)
{
	m->must_to_eat = 0;
	if (!ft_isnm(s[1]) || !ft_isnm(s[2]) || !ft_isnm(s[3]) || !ft_isnm(s[4]))
		return (0);
	m->num_philos = ft_atoi(s[1]);
	if (m->num_philos < 1 || m->num_philos > 200)
		return (0);
	m->time_of_die = ft_atoi(s[2]);
	if (m->time_of_die < 60)
		return (0);
	m->time_of_eat = ft_atoi(s[3]);
	if (m->time_of_eat < 60)
		return (0);
	m->time_of_slp = ft_atoi(s[4]);
	if (m->time_of_slp < 60)
		return (0);
	if (s[5])
	{
		if (!ft_isnm(s[5]))
			return (0);
		m->must_to_eat = ft_atoi(s[5]);
		if (m->must_to_eat < 1)
			return (0);
	}
	m->philos = NULL;
	return (1);
}
