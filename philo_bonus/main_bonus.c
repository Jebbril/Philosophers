/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:08:12 by jebril            #+#    #+#             */
/*   Updated: 2023/04/06 09:38:04 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all(t_var *v)
{
	int	i;

	i = 0;
	while (i < v->nb_philo)
	{
		kill(v->philo_pid[i], SIGKILL);
		i++;
	}
}

void	start_philos(t_var *v)
{
	int	i;

	i = 0;
	v->start_time = gettime();
	while (i < v->nb_philo)
	{
		v->philo_ind = i + 1;
		v->philo_pid[i] = fork();
		if (v->philo_pid[i] == -1)
		{
			while (--i >= 0)
				kill(v->philo_pid[i], SIGKILL);
			return ;
		}
		else if (v->philo_pid[i] == 0)
		{
			init_monitor(v);
			ft_routine(v);
		}
		i++;
	}
	sem_wait(v->end);
}

void	init_semaphores(t_var *v)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("end");
	sem_unlink("death");
	v->forks = sem_open("forks", O_CREAT | O_EXCL, 0777, v->nb_philo);
	v->print = sem_open("print", O_CREAT | O_EXCL, 0777, 1);
	v->end = sem_open("end", O_CREAT | O_EXCL, 0777, 0);
	v->death = sem_open("death", O_CREAT | O_EXCL, 0777, 1);
}

void	init_args(t_var *v)
{
	v->philo_ind = 1;
	v->nb_philo = v->args[0];
	v->time_todie = v->args[1];
	v->time_toeat = v->args[2];
	v->time_tosleep = v->args[3];
	if (v->args[4])
		v->nb_timetoeat = v->args[4];
	else
		v->nb_timetoeat = -1;
	v->nb_timeeaten = 0;
	v->philo_pid = malloc(sizeof(pid_t) * v->nb_philo);
	if (!v->philo_pid)
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_var	v;

	if (ac < 5 || ac > 6)
		exit(EXIT_FAILURE);
	v.args = parsing(ac, av);
	init_args(&v);
	init_semaphores(&v);
	start_philos(&v);
	kill_all(&v);
	free(v.philo_pid);
}
