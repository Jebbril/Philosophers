/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:10:31 by orakib            #+#    #+#             */
/*   Updated: 2023/03/26 12:10:45 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		usleep(time_in_ms / 10);
}