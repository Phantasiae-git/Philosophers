/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:14:11 by rfontes-          #+#    #+#             */
/*   Updated: 2023/09/21 11:30:32 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*philo(void)
{
	static t_philo	philo;

	return (&philo);
}

void error(char *msg)
{
	printf("%s", msg);
	exit(0);
}