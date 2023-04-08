/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:17:43 by orakib            #+#    #+#             */
/*   Updated: 2023/04/08 04:26:04 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(void)
{
	long			time;
	struct timeval	current;

	time = 0;
	gettimeofday(&current, NULL);
	time = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long time_in_ms)
{
	long	start_time;

	start_time = 0;
	start_time = gettime();
	while ((gettime() - start_time) < time_in_ms)
		usleep(100);
}
