/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:55:22 by orakib            #+#    #+#             */
/*   Updated: 2023/03/23 09:38:40 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_ph *p, int type)
{
	pthread_mutex_lock(&p->printm);
	if (type == 1)
		printf("%ld %d has taken a fork\n", gettime() - p->start_time, p->index);
	else if (type == 2)
		printf("%ld %d is eating\n", gettime() - p->start_time, p->index);
	else if (type == 3)
		printf("%ld %d is sleeping\n", gettime() - p->start_time, p->index);
	else if (type == 4)
		printf("%ld %d is thinking\n", gettime() - p->start_time, p->index);
	else if (type == 5)
		printf("%ld %d died\n", gettime() - p->start_time, p->index);
	pthread_mutex_unlock(&p->printm);
}
