/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:43:20 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/04 03:33:31 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	 main()
{
	struct timeval start;
	struct timeval end;
	int x = gettimeofday(&start, NULL);
	// long long int	x = 0;
	// sleep(2);
	printf("HEEREE\n");
	// while (x < 10000)
	// {
	// 	printf("Incrementing %lld\n", x);
	// 	x++;
	// }
	gettimeofday(&end, NULL);
	long elapsed = (start.tv_sec * 1000) + (start.tv_usec / 1000) - (start.tv_sec * 1000) + (start.tv_usec / 1000);
	printf("time is %ld ms\n", elapsed);
	printf("x = %d \n", start.tv_usec);
	// gettimeofday(&start, NULL);
	// long long x = 0;
	// while (x < 100000)
	// {
	// 	printf("Incrementing %lld\n", x);
	// 	x++;
	// }
	// gettimeofday(&end, NULL);
	// long elapsed2 = (end.tv_usec - start.tv_usec) / 1000;
	// printf("time is %ld ms 2\n", elapsed2);
}