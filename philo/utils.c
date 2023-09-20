/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:14:11 by rfontes-          #+#    #+#             */
/*   Updated: 2023/09/20 13:58:48 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*philo(void)
{
	static t_philo	philo;

	return (&philo);
}

long	ft_atol(const char *str, long negative)
{
	int		i;
	long	res;
	long	res1;

	i = 0;
	res = 0;
	res1 = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		res1 = res * 10 + (str[i] - '0');
		if (res1 < res)
			return ((long)2147483648);
		res = res1;
		i++;
	}
	if (str[i] != '\0')
		return ((long)2147483648);
	else
		return (res * negative);
}