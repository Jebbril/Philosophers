/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:13:57 by orakib            #+#    #+#             */
/*   Updated: 2023/03/19 17:44:19 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_var *v)
{
	int	i;

	i = -1;
	(void)v;
	ft_usleep(v->args[1]);
	while (1)
	{
		while (++i < v->args[0])
		{
			pthread_mutex_lock(&v->philos[i].deathm);
			if (gettime() - v->philos[i].last_meal > v->args[1])
			{
				printf("%ld %d died\n", gettime() - v->philos[i].start_time, v->philos[i].index);
				free_exit(v);
			}
			pthread_mutex_unlock(&v->philos[i].deathm);
		}
	}
}
