/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:14:11 by rfontes-          #+#    #+#             */
/*   Updated: 2023/09/29 16:33:36 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*philo(void)
{
	static t_philo	philo;

	return (&philo);
}

void printstuf

void error(char *msg)
{
	if()
	printf("%s", msg);
	return;
}

int	timern(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}