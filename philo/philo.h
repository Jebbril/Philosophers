/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:21:30 by orakib            #+#    #+#             */
/*   Updated: 2023/03/23 12:19:22 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include "sys/time.h"
# include "pthread.h"
# include "stdlib.h"
# include "stdio.h"
# include "string.h"
# include "unistd.h"

typedef struct s_ph
{
	int				index;
	pthread_t		thread;
	pthread_mutex_t	*f;
	pthread_mutex_t	printm;
	pthread_mutex_t	deathm;
	int				time_todie;
	int				time_toeat;
	int				time_tosleep;
	long			last_meal;
	int				nboftimes_eaten;
	int				nboftimes_toeat;
	long			start_time;
	int				nb_ph;
}	t_ph;

typedef struct s_var
{
	int				*args;
	t_ph			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*pdmtx;
	long			start_time;
	int				s;
}	t_var;

int		*parsing(int ac, char **av);
long	ft_atoi(const char *str);
void	free_exit(t_var *v);
void	*routine(void *arg);
long	gettime(void);
void	ft_usleep(long time_in_ms);
void	monitor(t_var *v);
void	print_msg(t_ph *p, int type);

#endif