/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:30:55 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/14 18:10:10 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct philo
{
	int				id;
	pthread_t		*philosopher;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*time;
	pthread_mutex_t	*print;
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
	unsigned long	first_time;
}	t_all;

unsigned long	ft_atoi(const char *str);
void			print_eat(t_all *all);
void			print_sleep(t_all *all);
void			print_fork(t_all *all);
void			print_think(t_all *all);
unsigned long	get_time(void);
void			print_die(t_all *all);
void			ft_usleep(unsigned long time);
int				parcing(char **av, int x);
int				checkifate(t_all **all);
unsigned long	get_time(void);
void			thread2(t_all *all);
int				parcing2(char **av);

#endif