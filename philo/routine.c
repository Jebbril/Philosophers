/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:54 by orakib            #+#    #+#             */
/*   Updated: 2023/03/18 13:18:17 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eat(t_ph *p)
{
	pthread_mutex_lock(&p->f[p->index - 1]);
	print_msg(p, 1);
	pthread_mutex_lock(&p->f[p->index % p->nb_ph]);
	print_msg(p, 1);
	print_msg(p, 2);
	ft_usleep(p->time_toeat);
	pthread_mutex_unlock(&p->f[p->index % p->nb_ph]);
	pthread_mutex_unlock(&p->f[p->index - 1]);
	p->nboftimes_eaten++;
}

void	p_sleep(t_ph *p)
{
	print_msg(p, 3);
	ft_usleep(p->time_tosleep);
}

void	p_think(t_ph *p)
{
	p->last_meal = gettime();
	print_msg(p, 4);
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
	}
	return (NULL);
}
