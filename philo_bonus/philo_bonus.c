/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:11:48 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/15 07:09:25 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
sem_t mutex;
void	*thread(void *arg)
{
	t_all	*all;

	all = (t_all *)arg;
	all->start_time = get_time();
	while (1)
	{
		printf("%lu ms %d is eating\n", get_time() - all->start_time, all->id);
		usleep(2000);
		printf("%lu ms %d is sleeping\n", get_time() - all->start_time, all->id);
		usleep(2000);
		
		break;
	}
	return (NULL);
}
void	routine(void)
{
	sem_wait(&mutex);
	printf("am here\n");
	// sleep(4);
	// printf("am here2\n");
	sem_post(&mutex);
}

int	main(int ac, char **av)
{
	t_all			**all;
	int *pid;
	unsigned long	x;
	ac = 0;
	// if (ac == 5 || ac == 6)
	// {
		x = 1;
		// if (parcing(av, x) || parcing2(av))
		// 	exit(1);
		all = malloc(sizeof(t_all *) * ft_atoi(av[1]));
		pid = malloc(sizeof(int) * ft_atoi(av[1]));
		if (!all || !pid)
			exit(1);
		x = 0;
		while (x < ft_atoi(av[1]))
		{
			all[x] = malloc(sizeof(t_all));
			x++;
		}
		x = 0;
		(*all)->num = ft_atoi(av[1]);
		x = 0;
		while (x < (*all)->num)
		{
			all[x]->id = x + 1;
			// all[x]->tt_die = ft_atoi(av[2]);
			// all[x]->tt_eat = ft_atoi(av[3]);
			// all[x]->tt_sleep = ft_atoi(av[4]);
			all[x]->left_fork = malloc(sizeof(sem_t));
			x++;
		}
		x = 0;
		sem_init(&mutex, 0, 1);
		while (x < (*all)->num)
		{
			pid[x] = fork();
			if (pid[x] == 0)
			{
				printf("child %d\n", x);
				// while (1)
				// {
				// 	printf("%d is eating\n", all[x]->id);
				// 	exit(0);
				// }
				routine();
			}
				sleep(2);
			x++;
		}
		while(wait(pid) != -1)
			wait(NULL);
		printf("Parent here\n");
		// if (id != 0)
			// printf("Finished\n");
	// }
}
