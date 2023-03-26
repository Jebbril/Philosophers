/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:36 by orakib            #+#    #+#             */
/*   Updated: 2023/03/26 12:11:54 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H

# define PHILO_BONUS_H

# include "sys/time.h"
# include "pthread.h"
# include "stdlib.h"
# include "stdio.h"
# include "string.h"
# include "unistd.h"

long	gettime(void);
void	ft_usleep(long time_in_ms);

#endif