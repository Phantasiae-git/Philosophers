/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:23:22 by phantasiae        #+#    #+#             */
/*   Updated: 2023/09/21 11:39:40 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	isnum(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

int	ft_atol(const char *s, long negative)
{
	long	res;
	int		i;

	i = -1;
	res = 0;
	while (i < 11 && (s[++i] && (s[i] >= '0' && s[i] <= '9')))
		res = res * 10 + (s[i] - '0');
	if (res > INT_MAX)
		return (INT_MAX);
	return ((int)res);
}

int	parsing(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (!isnum(argv[i]))
		{
			error("numbers only");
			return (0);
		}
		if (i == 1 && (res < 1 || ft_atol(argv[i]) > 200))
		{
			error("at least 1 philo");
			return (0);
		}
		if (ft_atol(argv[i]) == INT_MAX)
		{
			error("smaller timeframe pls");
			return (9);
		}
	}
	return (1);
}
