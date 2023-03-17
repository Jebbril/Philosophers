/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:13:57 by orakib            #+#    #+#             */
/*   Updated: 2023/03/17 20:37:28 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_var *v)
{
	int	i;

	i = -1;
	while (1)
	{
		while (++i < v->args[0])
		{
			if (v->philos[i].nboftimes_eaten > v->philos[i].nboftimes_toeat)
			{
				printf("%ld %d died\n", gettime() - v->philos[i].start_time, v->philos[i].index);
				free_exit(v);
			}
		}
		i = -1;
	}
}
