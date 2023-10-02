/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:23:22 by phantasiae        #+#    #+#             */
/*   Updated: 2023/09/28 18:19:11 by rfontes-         ###   ########.fr       */
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

//gotta be <12 because if it is smaller than int_max when it's at 10 digits it would not enter in the next loop check and be classified as under int_max
int	ft_atol(const char *s, long negative)
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
	while (++i < argc)
	{
		if (!isnum(argv[i]))
		{
			error("numbers only");
			return (0);
		}
		if (i == 1 && (ft_atol(argv[i]) < 1))
		{
			error("at least 1 philo");
			return (0);
		}
		if (ft_atol(argv[i]) < 0)
		{
			error("time between 0 and int_max pls");
			return (9);
		}
	}
	return (1);
}
