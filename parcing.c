/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:45:55 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/10 01:56:28 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parcing(char **av)
{
	int	x;
	int	y;

	x = 1;
	while (av[x])
	{
		y = 0;
		while (av[x][y])
		{
			if (av[x][y] == '-' || av[x][y + 1] == '+')
			{
				printf("Error\n");
				return (1);
			}
			else if ((av[x][y] >= 'a' && av[x][y] <= 'z'))
			{
				printf("Error\n");
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
