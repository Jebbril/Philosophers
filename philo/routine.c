/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:54 by orakib            #+#    #+#             */
/*   Updated: 2023/03/12 18:48:31 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_ph	*philos;

	philos = arg;
	if (philos->index % 2 != 0)
		usleep(1000);
	pthread_mutex_lock(&philos->f[philos->index - 1]);
	printf("%ld philo number %d grabbed his left fork\n",gettime() - philos->start_time, philos->index);
	pthread_mutex_lock(&philos->f[philos->index % philos->nb_ph]);
	printf("%ld philo number %d grabbed his right fork\n",gettime() - philos->start_time, philos->index);
	printf("%ld %d is eating\n", gettime() - philos->start_time, philos->index);
	sleep(1);
	printf("%ld %d done eating\n", gettime() - philos->start_time, philos->index);
	pthread_mutex_unlock(&philos->f[philos->index - 1]);
	pthread_mutex_unlock(&philos->f[philos->index % philos->nb_ph]);
	return (NULL);
}
