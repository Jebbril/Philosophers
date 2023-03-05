/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:51:21 by orakib            #+#    #+#             */
/*   Updated: 2023/03/05 18:08:46 by orakib           ###   ########.fr       */
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
	int i = -1;
	while (++i < v.args[0])
		printf("index : %d\t time to die : %d\t time to eat : %d\t time to sleep : %d\t nb of times to eat : %d\n", v.philos[i].index, v.philos[i].time_todie, v.philos[i].time_toeat, v.philos[i].time_tosleep, v.philos[i].nboftimes_toeat);
	free_exit(&v);
}
