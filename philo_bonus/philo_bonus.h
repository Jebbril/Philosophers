/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:36 by orakib            #+#    #+#             */
/*   Updated: 2023/04/02 13:15:36 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H

# define PHILO_BONUS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_var
{
	int			*args;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*end;
	sem_t		*enough_meals;
	sem_t		*death;
	int			nb_philo;
	int			philo_ind;
	long		time_todie;
	long		time_toeat;
	long		time_tosleep;
	long		last_meal;
	int			nb_timetoeat;
	int			nb_timeeaten;
	long		start_time;
	pthread_t	monitor;
	pid_t		*philo_pid;
}	t_var;

long	gettime(void);
void	ft_usleep(long time_in_ms);
int		*parsing(int ac, char **av);
long	ft_atoi(const char *str);
void	init_monitor(t_var *v);
void	*ft_monitor(void *param);
void	ft_routine(t_var *v);

#endif