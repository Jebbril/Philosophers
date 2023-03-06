/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:51:21 by orakib            #+#    #+#             */
/*   Updated: 2023/03/06 17:31:43 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_forks(t_var *v)
{
	int	i;

	v->forks = malloc(sizeof(pthread_mutex_t) * v->args[0]);
	i = -1;
	while (++i < v->args[0])
	{
		v->s = pthread_mutex_init(&v->forks[i], NULL);
		if (v->s != 0)
			free_exit(v);
	}
}

void	putdown_forks(t_var *v, int i)
{
	v->philos[i].left = v->forks[i];
	if (i < v->args[0] - 1)
		v->philos[i].right = v->forks[i + 1];
	else
		v->philos[i].right = v->forks[0];
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
		putdown_forks(v, i);
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
		usleep(5);
	}
	i = -1;
	while (++i < v->args[0])
	{
		v->s = pthread_join(v->philos[i].thread, NULL);
		if (v->s != 0)
			free_exit(v);
	}
}

int	main(int ac, char **av)
{
	t_var	v;

	v.forks = NULL;
	v.philos = NULL;
	if (ac < 5 || ac > 6)
		exit(EXIT_FAILURE);
	v.args = parsing(ac, av);
	make_forks(&v);
	init_philos(&v);
	init_threads(&v);
	free_exit(&v);
}
