/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:27:34 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/10 02:01:47 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_die(t_all *all)
{
	pthread_mutex_lock(all->print);
	printf("%ld ms %d died\n", get_time() - all->start_time, all->id);
}

void	print_think(t_all *all)
{
	pthread_mutex_lock(all->print);
	printf("%ld ms %d is thinking\n", get_time() - all->start_time, all->id);
	pthread_mutex_unlock(all->print);
}

void	print_fork(t_all *all)
{
	pthread_mutex_lock(all->print);
	printf("%ld ms %d has taken a fork\n", get_time() \
		- all->start_time, all->id);
	pthread_mutex_unlock(all->print);
}

void	print_sleep(t_all *all)
{
	pthread_mutex_lock(all->print);
	printf("%ld ms %d is sleeping\n", get_time() - all->start_time, all->id);
	pthread_mutex_unlock(all->print);
}

void	print_eat(t_all *all)
{
	pthread_mutex_lock(all->print);
	printf("%ld ms %d is eating\n", get_time() - all->start_time, all->id);
	pthread_mutex_unlock(all->print);
}
