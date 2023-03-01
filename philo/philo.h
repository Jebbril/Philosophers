/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:21:30 by orakib            #+#    #+#             */
/*   Updated: 2023/03/01 14:27:39 by orakib           ###   ########.fr       */
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

typedef struct s_var
{
	int				*args;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	int				s;
	int				i;
	int				j;
}	t_var;

int		*parsing(int ac, char **av);
long	ft_atoi(const char *str);
void	free_exit(t_var *v);

#endif