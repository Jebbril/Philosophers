/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:29:43 by orakib            #+#    #+#             */
/*   Updated: 2023/02/28 13:59:37 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_exit(t_var *v)
{
	if (v->args)
		free(v->args);
	if (v->philos)
		free(v->philos);
	if (v->forks)
		free(v->forks);
	exit(EXIT_FAILURE);
}
