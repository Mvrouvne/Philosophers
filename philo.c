/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:30:45 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/17 01:47:17 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *arg)
{
	t_all	*all;

	all = (t_all *)arg;
	all->ate = 0;
	pthread_mutex_lock(all->time);
	all->start_time = all->first_time;
	pthread_mutex_unlock(all->time);
	thread2(all);
	return (NULL);
}

int	main_work3(t_all **all, int ac, int x)
{
	while (1)
	{
		x = 0;
		while (x < (*all)->num)
		{
			pthread_mutex_lock((*all)->time);
			if (ac == 6)
			{
				pthread_mutex_lock((*all)->print);
				if (checkifate(all))
					return (1);
				pthread_mutex_unlock((*all)->print);
			}
			if (get_time() - all[x]->eating >= (*all)->tt_die)
			{
				print_die(all[x]);
				return (1);
			}
			x++;
			pthread_mutex_unlock((*all)->time);
		}
	}
	return (0);
}

int	main_work2(t_all **all, int ac, char **av)
{
	pthread_mutex_t	*print;
	pthread_mutex_t	*time;
	int				x;

	print = malloc(sizeof(pthread_mutex_t));
	time = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(time, NULL);
	pthread_mutex_init(print, NULL);
	x = 0;
	while (x < (*all)->num)
	{
		if (ac == 6)
			all[x]->n_eating = ft_atoi(av[5]);
		all[x]->id = x + 1;
		all[x]->philosopher = malloc(sizeof(pthread_t));
		all[x]->eating = get_time();
		all[x]->print = print;
		all[x]->time = time;
		if (pthread_create(all[x]->philosopher, NULL, &thread, &*all[x]))
			return (1);
		usleep(100);
		x++;
	}
	return (0);
}

int	main_work1(t_all **all, char **av)
{
	int	x;

	x = 0;
	(*all)->num = ft_atoi(av[1]);
	while (x < (*all)->num)
	{
		all[x]->tt_die = ft_atoi(av[2]);
		all[x]->tt_eat = ft_atoi(av[3]);
		all[x]->tt_sleep = ft_atoi(av[4]);
		all[x]->left_fork = malloc(sizeof(pthread_mutex_t));
		if (!(all[x]->left_fork))
			return (1);
		all[x]->first_time = get_time();
		if (pthread_mutex_init(all[x]->left_fork, NULL))
			return (1);
		x++;
	}
	x = 0;
	while (x < (*all)->num)
	{
		all[x]->right_fork = all[(x + 1) % (*all)->num]->left_fork;
		x++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_all	**all;
	int		x;

	if (ac == 5 || ac == 6)
	{
		x = 1;
		if (parcing(av, x) || parcing2(av))
			return (0);
		all = malloc(sizeof(t_all *) * ft_atoi(av[1]));
		if (!all)
			return (1);
		x = 0;
		while (x < ft_atoi(av[1]))
			all[x++] = malloc(sizeof(t_all));
		if (main_work1(all, av) || main_work2(all, ac, av)
			|| main_work3(all, ac, x))
		{
			free(all);
			return (1);
		}
	}
	else
		printf("4 Arguments required! (6 optional)");
}
