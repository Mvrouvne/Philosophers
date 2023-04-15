/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:02:09 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/15 06:51:47 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <semaphore.h>

typedef struct philo
{
	int				id;
	pthread_t		*philosopher;
	sem_t			*left_fork;
	sem_t			*right_fork;
	sem_t			*time;
	sem_t			*print;
	unsigned long	num;
	struct timeval	start;
	struct timeval	end;
	long			start_time;
	long			end_time;
	unsigned long	tt_die;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned long	n_eating;
	unsigned long	eating;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	unsigned long	ate;
}	t_all;

unsigned long	ft_atoi(const char *str);
void			ft_usleep(unsigned long time);
unsigned long	get_time(void);
int				parcing(char **av, int x);
int				parcing2(char **av);

#endif