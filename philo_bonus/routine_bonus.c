/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:31:35 by orakib            #+#    #+#             */
/*   Updated: 2023/04/08 04:19:29 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	p_eat(t_var *v)
{
	sem_wait(v->forks);
	sem_wait(v->print);
	printf("%ld %d has taken a fork\n", gettime() - v->start_time, v->philo_ind);
	sem_post(v->print);
	sem_wait(v->forks);
	sem_wait(v->print);
	printf("%ld %d has taken a fork\n", gettime() - v->start_time, v->philo_ind);
	sem_post(v->print);
	sem_wait(v->death);
	printf("");
	v->last_meal = gettime();
	printf("");
	sem_post(v->death);
	sem_wait(v->print);
	printf("%ld %d is eating\n", gettime() - v->start_time, v->philo_ind);
	sem_post(v->print);
	ft_usleep(v->time_toeat);
	sem_post(v->forks);
	sem_post(v->forks);
	v->nb_timeeaten++;
}

void	p_sleep(t_var *v)
{
	sem_wait(v->print);
	printf("%ld %d is sleeping\n", gettime() - v->start_time, v->philo_ind);
	sem_post(v->print);
	ft_usleep(v->time_tosleep);
}

void	p_think(t_var *v)
{
	sem_wait(v->print);
	printf("%ld %d is thinking\n", gettime() - v->start_time, v->philo_ind);
	sem_post(v->print);
}

void	ft_routine(t_var *v)
{
	while (1)
	{
		p_eat(v);
		if (v->nb_timeeaten > v->nb_timetoeat && v->nb_timetoeat != -1)
		{
			sem_wait(v->print);
			sem_post(v->end);
		}
		p_sleep(v);
		p_think(v);
	}
}
