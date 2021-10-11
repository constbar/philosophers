#include "philo.h"

static void	ft_take(t_phil *p)
{
	ft_print_state(p, "is thinking");
	pthread_mutex_lock(p->l_fork);
	ft_print_state(p, "has taken a fork");
	pthread_mutex_lock(p->r_fork);
	ft_print_state(p, "has taken a fork");
}

static void	ft_eat(t_phil *p)
{
	p->lst_eat = ft_diff_time(0);
	ft_print_state(p, "is eating");
	ft_wait_time(p->m->time_of_eat);
}

static void	ft_put(t_phil *p)
{
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(p->r_fork);
}

static void	ft_slp(t_phil *p)
{
	ft_print_state(p, "is sleeping");
	ft_wait_time(p->m->time_of_slp);
	if (p->num_eat != -1)
		p->num_eat--;
	if (p->num_eat == 0)
		p->st = -1;
}

void	*ft_actions(void *st)
{
	t_phil	*clon;

	clon = (t_phil *)st;
	if (clon->ev == 1)
	{
		ft_wait_time(100);
		clon->ev = 0;
	}
	while (21)
	{
		ft_take(clon);
		ft_eat(clon);
		ft_put(clon);
		ft_slp(clon);
	}
}
