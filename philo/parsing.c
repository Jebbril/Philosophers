/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:57:33 by orakib            #+#    #+#             */
/*   Updated: 2023/03/06 13:00:43 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (!check_number(av[i]))
			return (0);
	return (1);
}

int	*parsing(int ac, char **av)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * ac);
	if (!ret)
		exit(EXIT_FAILURE);
	i = -1;
	if (!check_arguments(ac, av))
	{
		free(ret);
		exit(EXIT_FAILURE);
	}
	while (++i < (ac - 1))
	{
		if (ft_atoi(av[i + 1]) > 2147483647)
		{
			free(ret);
			exit(EXIT_FAILURE);
		}
		ret[i] = ft_atoi(av[i + 1]);
	}
	ret[i] = 0;
	return (ret);
}
