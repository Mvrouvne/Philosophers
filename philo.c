/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:30:45 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/05 00:38:57 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
void	*thread(void *arg)
{
	t_all *all;
	all = (t_all*)arg;
	int	left;

	// get_time();
	gettimeofday(&all->start, NULL);
	all->start_time  = (all->start.tv_sec * 1000) + (all->start.tv_usec / 1000);
	while (1)
	{
		gettimeofday(&all->end, NULL);
		all->end_time = (all->end.tv_sec * 1000) + (all->end.tv_usec / 1000);
		pthread_mutex_lock(all->left_fork);
		print_fork(all);
		pthread_mutex_lock(all->right_fork);
		print_fork(all);
		// printf("%ld ms %d is eating\n", get_time() - all->start_time, all->id);
		print_eat(all);
		// printf("tt_eat = %d\n", all->tt_eat);
		usleep(all->tt_eat * 1000);
		pthread_mutex_unlock(all->left_fork);
		pthread_mutex_unlock(all->right_fork);
		print_sleep(all);
		usleep(all->tt_eat * 1000);
	
		// break ;
	}
	return NULL;
}

int main(int ac, char **av)
{
	t_all	**all;
	int		x;

	if (ac == 4 || ac == 5)
	{
		all = malloc(sizeof(t_all*) * ft_atoi(av[1]));
		x = 0;
		ac = 0;
		while(x < ft_atoi(av[1]))
		{
			all[x] = malloc(sizeof(t_all));
			x++;
		}
		x = 0;
		(*all)->num = ft_atoi(av[1]);
		if ((*all)->num == 1)
		{
			printf("%d died\n", (*all)->num);
			exit(0);
		}
		while(x < (*all)->num)
		{
			all[x]->left_fork = malloc(sizeof(pthread_mutex_t));
			pthread_mutex_init(all[x]->left_fork, NULL);
			x++;	
		}
		x = 0;
		while (x < (*all)->num)
		{
			all[x]->right_fork = all[(x + 1) % (*all)->num]->left_fork;
			x++;
		}
		x = 0;
		while (x < (*all)->num)
		{
			all[x]->tt_die = ft_atoi(av[2]);
			all[x]->tt_eat = ft_atoi(av[3]);
			if (ac == 5)
				all[x]->tt_sleep = ft_atoi(av[4]);
			all[x]->id = x + 1;
			all[x]->philosopher = malloc(sizeof(pthread_t));
			if (pthread_create(all[x]->philosopher, NULL, &thread, &*all[x]))
				exit(1);
			// printf("%ld ms %d is thinking\n", (*all)->end_time - (*all)->start_time, (*all)->id);
			// usleep(10000);
			x++;
		}
		x = 0;
		while (x < (*all)->num)
		{
			if (pthread_join(*all[x]->philosopher, NULL))
				exit(1);
			x++;
		}
		pthread_mutex_destroy((*all)->left_fork);
	}
	printf("4 Arguments required! (6 optional)");
}
