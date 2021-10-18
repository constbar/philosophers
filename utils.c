#include "philo.h"

int	ft_isnm(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}

void	ft_wait_time(uint64_t time)
{
	uint64_t	start;

	start = ft_diff_time(0);
	while (ft_diff_time(0) - start < time)
		usleep(100);
}

uint64_t	ft_diff_time(uint64_t start)
{
	struct timeval	tv;
	uint64_t		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - start;
	return (time);
}

void	ft_print_state(t_phil *p, char *state)
{
	if (!p->is_dead)
	{
		pthread_mutex_lock(p->print);
		printf("%llu ms %d %s\n", ft_diff_time(p->start_sim), p->id, state);
		pthread_mutex_unlock(p->print);
	}
}

int	ft_atoi(const char *str)
{
	int					i;
	int					f;
	unsigned long int	r;

	i = 0;
	r = 0;
	f = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			f = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
		if (r > 2147483647 && f == 1)
			return (-1);
		if (r > 2147483648 && f == -1)
			return (0);
	}
	return (r * f);
}
