/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:21:30 by orakib            #+#    #+#             */
/*   Updated: 2023/03/12 18:24:05 by orakib           ###   ########.fr       */
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
	int				time_todie;
	int				time_toeat;
	int				time_tosleep;
	int				nboftimes_toeat;
	long			start_time;
	int				nb_ph;
}	t_ph;

typedef struct s_var
{
	int				*args;
	t_ph			*philos;
	pthread_mutex_t	*forks;
	long			start_time;
	int				s;
}	t_var;

int		*parsing(int ac, char **av);
long	ft_atoi(const char *str);
void	free_exit(t_var *v);
void	*routine(void *arg);
long	gettime(void);

#endif