/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:55:54 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/10 02:02:03 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread2(t_all *all)
{
	while (1)
	{
		pthread_mutex_lock(all->left_fork);
		print_fork(all);
		pthread_mutex_lock(all->right_fork);
		print_fork(all);
		print_eat(all);
		pthread_mutex_lock(all->time);
		all->eating = get_time();
		pthread_mutex_unlock(all->time);
		pthread_mutex_lock(all->print);
		all->ate++;
		pthread_mutex_unlock(all->print);
		ft_usleep(all->tt_eat);
		pthread_mutex_unlock(all->left_fork);
		pthread_mutex_unlock(all->right_fork);
		print_sleep(all);
		ft_usleep(all->tt_sleep);
		print_think(all);
	}
}
