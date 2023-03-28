/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebril <jebril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:36 by orakib            #+#    #+#             */
/*   Updated: 2023/03/28 14:49:43 by jebril           ###   ########.fr       */
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

typedef struct s_var
{
	int			*args;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*end;
	sem_t		*enough_meals;
	int			nb_philo;
	int			philo_ind;
	long		time_todie;
	long		time_toeat;
	long		time_tosleep;
	int			nb_timetoeat;
	int			nb_timeeaten;
	long		start_time;
	pthread_t	monitor;
}	t_var;

long	gettime(void);
void	ft_usleep(long time_in_ms);
int		*parsing(int ac, char **av);
long	ft_atoi(const char *str);

#endif