/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:51:21 by orakib            #+#    #+#             */
/*   Updated: 2023/03/25 12:02:33 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_forks(t_var *v)
{
	int	i;

	v->forks = malloc(sizeof(pthread_mutex_t) * v->args[0]);
	if (!v->forks)
		free_exit(v);
	i = -1;
	while (++i < v->args[0])
	{
		v->s = pthread_mutex_init(&v->forks[i], NULL);
		if (v->s != 0)
			free_exit(v);
	}
}

void	pd_mutexes(t_var *v)
{
	v->pdmtx = malloc(sizeof(pthread_mutex_t) * 3);
	if (!v->pdmtx)
		free_exit(v);
	v->s = pthread_mutex_init(&v->pdmtx[0], NULL);
	if (v->s != 0)
		free_exit(v);
	v->s = pthread_mutex_init(&v->pdmtx[1], NULL);
	if (v->s != 0)
		free_exit(v);
	v->s = pthread_mutex_init(&v->pdmtx[2], NULL);
	if (v->s != 0)
		free_exit(v);
}

void	init_philos(t_var *v)
{
	int	i;

	i = -1;
	v->philos = malloc(sizeof(t_ph) * v->args[0]);
	if (!v->philos)
		free_exit(v);
	while (++i < v->args[0])
	{
		v->philos[i].index = i + 1;
		v->philos[i].time_todie = v->args[1];
		v->philos[i].time_toeat = v->args[2];
		v->philos[i].time_tosleep = v->args[3];
		if (v->args[4])
			v->philos[i].nboftimes_toeat = v->args[4];
		else
			v->philos[i].nboftimes_toeat = -1;
		v->philos[i].nboftimes_eaten = 0;
		v->philos[i].last_meal = gettime();
		v->philos[i].f = v->forks;
		v->philos[i].start_time = v->start_time;
		v->philos[i].nb_ph = v->args[0];
		v->philos[i].deathm = &v->pdmtx[0];
		v->philos[i].printm = &v->pdmtx[1];
		v->philos[i].fullm = &v->pdmtx[2];
	}
}

void	init_threads(t_var *v)
{
	int	i;

	i = -1;
	while (++i < v->args[0])
	{
		v->s = pthread_create(&v->philos[i].thread,
				NULL, routine, &v->philos[i]);
		if (v->s != 0)
			free_exit(v);
	}
	i = -1;
	while (++i < v->args[0])
	{
		v->s = pthread_detach(v->philos[i].thread);
		if (v->s != 0)
			free_exit(v);
	}
}

int	main(int ac, char **av)
{
	t_var			v;

	v.forks = NULL;
	v.philos = NULL;
	if (ac < 5 || ac > 6)
		exit(EXIT_FAILURE);
	v.args = parsing(ac, av);
	make_forks(&v);
	pd_mutexes(&v);
	v.start_time = gettime();
	init_philos(&v);
	init_threads(&v);
	monitor(&v);
	ft_usleep(1);
	free_exit(&v);
}
