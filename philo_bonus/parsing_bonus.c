/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebril <jebril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:09:26 by jebril            #+#    #+#             */
/*   Updated: 2023/03/28 13:09:43 by jebril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		if (ft_atoi(av[i + 1]) > 2147483647
			|| ft_atoi(av[i + 1]) == 0 || !av[i + 1][0])
		{
			free(ret);
			exit(EXIT_FAILURE);
		}
		ret[i] = ft_atoi(av[i + 1]);
	}
	ret[i] = 0;
	return (ret);
}
