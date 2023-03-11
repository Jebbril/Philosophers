/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:17:43 by orakib            #+#    #+#             */
/*   Updated: 2023/03/11 18:26:41 by orakib           ###   ########.fr       */
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
