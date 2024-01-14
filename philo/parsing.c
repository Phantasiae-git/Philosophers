/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:23:22 by phantasiae        #+#    #+#             */
/*   Updated: 2024/01/12 19:25:33 by rfontes-         ###   ########.fr       */
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

int	ft_atol(const char *s)
{
	long	res;
	int		i;

	i = -1;
	res = 0;
	while (++i < 12 && (s[i] && (s[i] >= '0' && s[i] <= '9')))
		res = res * 10 + (s[i] - '0');
	if (res > INT_MAX)
		return (-1);
	return ((int)res);
}

int	parsing(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)argc;
	while (argv[++i])
	{
		if (!isnum(argv[i]))
		{
			printf("error: numbers only (and positive ones)");
			return (0);
		}
		if (i == 1 && (ft_atol(argv[i]) < 1))
		{
			printf("error: at least 1 philo");
			return (0);
		}
		if (ft_atol(argv[i]) < 0)
		{
			printf("error: time between 0 and int_max pls");
			return (0);
		}
	}
	return (1);
}
