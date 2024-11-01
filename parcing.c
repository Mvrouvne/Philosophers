/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:45:55 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/17 00:41:35 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parcing2(char **av)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (ft_atoi(av[2]) == -1 || ft_atoi(av[3]) == -1
		|| ft_atoi(av[4]) == -1 || (av[5] && ft_atoi(av[5]) == -1)
		|| (av[5] && ft_atoi(av[5]) == 0) || ft_atoi(av[1]) == 0)
	{
		printf("Error\n");
		return (1);
	}
	x = 0;
	while (av[x])
	{
		if (av[x][0] == '\0')
		{
			printf("Error\n");
			return (1);
		}
		x++;
	}
	return (0);
}

int	parcing(char **av, int x)
{
	int	y;

	x = 1;
	while (av[x])
	{
		y = 0;
		while (av[x][y])
		{
			if (av[x][y] == '+' && y == 0)
				y++;
			if (av[x][y] == '-' || av[x][y] == '+')
			{
				printf("Error\n");
				return (1);
			}
			else if (!(av[x][y] >= '0' && av[x][y] <= '9'))
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
