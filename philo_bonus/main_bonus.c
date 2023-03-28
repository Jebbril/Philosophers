/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebril <jebril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:08:12 by jebril            #+#    #+#             */
/*   Updated: 2023/03/28 14:51:19 by jebril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_args(t_var *v)
{
	v->philo_ind = 0;
	v->nb_philo = v->args[0];
	v->time_todie = v->args[1];
	v->time_toeat = v->args[2];
	v->time_tosleep = v->args[3];
	if (v->args[4])
		v->nb_timetoeat = v->args[4];
	else
		v->nb_timetoeat = -1;
	v->nb_timeeaten = 0;
}

int	main(int ac, char **av)
{
	t_var	v;

	if (ac < 5 || ac > 6)
		exit(EXIT_FAILURE);
	v.args = parsing(ac, av);
	init_args(&v);
}
