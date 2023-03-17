/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:54 by orakib            #+#    #+#             */
/*   Updated: 2023/03/17 20:23:35 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eat(t_ph *p)
{
	pthread_mutex_lock(&p->f[p->index - 1]);
	printf("%ld %d has taken a fork\n", gettime() - p->start_time, p->index);
	pthread_mutex_lock(&p->f[p->index % p->nb_ph]);
	printf("%ld %d has taken a fork\n", gettime() - p->start_time, p->index);
	printf("%ld %d is eating\n", gettime() - p->start_time, p->index);
	ft_usleep(p->time_toeat);
	pthread_mutex_unlock(&p->f[p->index % p->nb_ph]);
	pthread_mutex_unlock(&p->f[p->index - 1]);
}

void	p_sleep(t_ph *p)
{
	printf("%ld %d is sleeping\n", gettime() - p->start_time, p->index);
	ft_usleep(p->time_tosleep);
}

void	p_think(t_ph *p)
{
	p->last_meal = gettime();
	printf("%ld %d is thinking\n", gettime() - p->start_time, p->index);
}

void	*routine(void *arg)
{
	t_ph	*philos;

	philos = arg;
	if (philos->index % 2 != 0)
		ft_usleep(5);
	while (1)
	{
		p_eat(philos);
		p_sleep(philos);
		p_think(philos);
		philos->nboftimes_eaten++;
	}
	return (NULL);
}
