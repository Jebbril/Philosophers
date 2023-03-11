/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:54 by orakib            #+#    #+#             */
/*   Updated: 2023/03/11 18:49:27 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_ph	*philos;

	philos = arg;
	if (philos->index % 2 == 0)
		usleep(50000);
	pthread_mutex_lock(&philos->left);
	printf("%ld philo number %d grabbed his left fork\n",gettime() - philos->start_time, philos->index);
	pthread_mutex_lock(&philos->right);
	printf("%ld philo number %d grabbed his right fork\n",gettime() - philos->start_time, philos->index);
	usleep(200000);
	printf("%ld %d done eating\n", gettime() - philos->start_time, philos->index);
	// pthread_mutex_unlock(&philos->left);
	// pthread_mutex_unlock(&philos->right);
	return (NULL);
}
