/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:44:48 by phantasiae        #+#    #+#             */
/*   Updated: 2024/01/08 22:30:21 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_philo *philo)
{
	printstuff(philo, THINK);
}

void	honkshoo(t_philo *philo)
{
	printstuff(philo, SLEEP);
	ft_usleep(philo->data->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[0]]);
	printstuff(philo, TAKE_FORK);
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[1]]);
	printstuff(philo, TAKE_FORK);
	printstuff(philo, EAT);
	ft_usleep(philo->data->time_to_eat);
	philo->lastmeal = timern();
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[0]]);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[1]]);
	philo->mealcount++;
}
