/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:51:21 by orakib            #+#    #+#             */
/*   Updated: 2023/03/01 14:34:44 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func(void *arg)
{
	
}

void	init_mutexes(t_var *v)
{
	v->i = -1;
	while (++v->i < v->args[0])
	{
		v->s = pthread_mutex_init(&v->forks[v->i], NULL);
		if (v->s != 0)
			free_exit(v);
	}
}

void	create_threads(t_var *v)
{
	v->philos = malloc(sizeof(pthread_t) * v->args[0]);
	if (!v->philos)
		free_exit(v);
	v->forks = malloc(sizeof(pthread_mutex_t) * v->args[0]);
	if (!v->forks)
		free_exit(v);
	init_mutexes(v);
	v->i = -1;
	while (++v->i < v->args[0])
	{
		v->s = pthread_create(&v->philos[v->i], NULL, func, NULL);
		if (v->s != 0)
			free_exit(v);
	}
	v->j = -1;
	while (++v->j < v->args[0])
	{
		v->s = pthread_join(v->philos[v->j], NULL);
		if (v->s != 0)
			free_exit(v);
	}
}

int	main(int ac, char **av)
{
	t_var	v;

	if (ac < 5 || ac > 6)
		exit(EXIT_FAILURE);
	v.args = parsing(ac, av);
	create_threads(&v);
	free_exit(&v);
}
