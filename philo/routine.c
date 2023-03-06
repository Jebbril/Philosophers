/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:54 by orakib            #+#    #+#             */
/*   Updated: 2023/03/06 18:20:12 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_ph	*philos;

	philos = arg;
	if (philos->index % 2 == 0)
		usleep(5);
	pthread_mutex_lock(&philos->left);
	printf("philo number %d grabbed his left fork\n", philos->index);
	sleep(1);
	pthread_mutex_lock(&philos->right);
	printf("philo number %d grabbed his right fork\n", philos->index);
	pthread_mutex_unlock(&philos->left);
	pthread_mutex_unlock(&philos->right);
	printf("%d done eating\n\n", philos->index);
	return (NULL);
}
