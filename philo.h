/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:30:55 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/05 00:37:13 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
#include <sys/time.h>

typedef struct philo
{
	int				id;
	pthread_t		*philosopher;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				num;
	struct timeval	start;
	struct timeval	end;
	long	start_time;
	long	end_time;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	n_eating;
}   t_all;

// typedef struct	philo2
// {
// 	struct timeval	start;
// 	struct timeval	end;
// 	long long	elapsed;
	
// }	t_time;

int	ft_atoi(const char *str);
void	print_eat(t_all *all);
void	print_sleep(t_all *all);
void	print_fork(t_all *all);
long	get_time(void);

#endif