/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:30:55 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/17 01:42:47 by machaiba         ###   ########.fr       */
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
	int				num;
	struct timeval	start;
	struct timeval	end;
	unsigned long	start_time;
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

int				ft_atoi(const char *str);
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