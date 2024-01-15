/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:44:48 by phantasiae        #+#    #+#             */
/*   Updated: 2024/01/15 20:05:40 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_philo *philo)
{
	if (!status_check(philo->data))
		return ;
	printstuff(philo, THINK);
}

void	honkshoo(t_philo *philo)
{
	printstuff(philo, SLEEP);
	ft_usleep(philo->data->time_to_sleep, philo->data);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[0]]);
	printstuff(philo, TAKE_FORK);
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[1]]);
	printstuff(philo, TAKE_FORK);
	pthread_mutex_lock(&philo->data->statuslock);
	philo->status = 2;
	philo->lastmeal = timern();
	philo->mealcount++;
	pthread_mutex_unlock(&philo->data->statuslock);
	printstuff(philo, EAT);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_lock(&philo->data->statuslock);
	philo->status = 1;
	pthread_mutex_unlock(&philo->data->statuslock);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[0]]);
}
