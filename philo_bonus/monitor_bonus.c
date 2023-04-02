/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:23:10 by orakib            #+#    #+#             */
/*   Updated: 2023/04/02 13:32:11 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_monitor(void *param)
{
	t_var	*v;

	v = param;
	while (1)
	{
		sem_wait(v->death);
		if (gettime() - v->last_meal > v->time_todie)
		{
			sem_wait(v->print);
			printf("%ld %d died\n", gettime() - v->start_time, v->philo_ind);
			sem_post(v->end);
		}
		sem_post(v->death);
		sem_wait(v->enough_meals);
		if (v->nb_timeeaten > v->nb_timetoeat && v->nb_timetoeat != -1)
		{
			sem_wait(v->print);
			sem_post(v->end);
		}
		sem_post(v->enough_meals);
	}
	return (NULL);
}

void	init_monitor(t_var *v)
{
	v->last_meal = gettime();
	pthread_create(&v->monitor, NULL, &ft_monitor, v);
	pthread_detach(v->monitor);
}
