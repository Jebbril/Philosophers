/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:13:57 by orakib            #+#    #+#             */
/*   Updated: 2023/03/23 13:27:08 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_var *v)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < v->args[0])
		{
			pthread_mutex_lock(&v->philos[i].deathm);
			if (gettime() - v->philos[i].last_meal > v->philos[i].time_todie)
			{
				print_msg(&v->philos[i], 5);
				return ;
			}
			pthread_mutex_unlock(&v->philos[i].deathm);
			pthread_mutex_lock(&v->philos[i].fullm);
			if (v->philos[i].nboftimes_eaten > v->philos[i].nboftimes_toeat
				&& v->philos[i].nboftimes_toeat != -1)
				return ;
			pthread_mutex_unlock(&v->philos[i].fullm);
		}
	}
}
