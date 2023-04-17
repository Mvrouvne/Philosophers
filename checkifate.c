/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkifate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:57:13 by machaiba          #+#    #+#             */
/*   Updated: 2023/04/17 01:43:45 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkifate(t_all **all)
{
	int	count;
	int	x;

	x = 0;
	count = 0;
	while (x < (*all)->num)
	{
		if (all[x]->ate >= (*all)->n_eating)
			count++;
		x++;
	}
	if (count == (*all)->num)
		return (1);
	else
		return (0);
}
