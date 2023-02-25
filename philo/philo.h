/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:21:30 by orakib            #+#    #+#             */
/*   Updated: 2023/02/25 16:38:24 by orakib           ###   ########.fr       */
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

int		*parsing(int ac, char **av);
long	ft_atoi(const char *str);

#endif