/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:27:24 by rfontes-          #+#    #+#             */
/*   Updated: 2024/01/13 22:43:52 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*init_forks(t_data *data)
{
	int	i;

	i = -1;
	data->fork_locks = malloc(sizeof(pthread_mutex_t)
		* (data->number_of_philosophers));
	if (!data->fork_locks)
		return (NULL);
	while (++i < (data->number_of_philosophers))
	{
		if (pthread_mutex_init(&data->fork_locks[i], NULL) != 0)
		{
			free(data->fork_locks);
			return (NULL);
		}
	}
	return (data->fork_locks);
}

t_philo	*init_philo(t_data *data, int i)
{
	data->philo = malloc(sizeof(t_philo) * (data->number_of_philosophers));
	if (!data->philo)
		return (NULL);
	i = -1;
	while (++i < data->number_of_philosophers)
	{
		data->philo[i].philo_num = i + 1;
		data->philo[i].data = data;
		data->philo[i].fork[0] = i;
		if (i == data->number_of_philosophers - 1)
			data->philo[i].fork[1] = 0;
		else
			data->philo[i].fork[1] = i + 1;
		data->philo[i].mealcount = 0;
		data->philo[i].status = 1;
		if (pthread_create(&data->philo[i].thread_id, NULL, &thread_routine,
				&(data->philo[i])) != 0)
		{
			free(data->philo);
			free(data->fork_locks);
			return (NULL);
		}
		data->philo[i].lastmeal = timern();
	}
	return (data->philo);
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->number_of_philosophers = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->status = 1;
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	data->fork_locks = init_forks(data);
	if (!data->fork_locks)
		return (1);
	pthread_mutex_init(&data->printlock, NULL);
	pthread_mutex_init(&data->statuslock, NULL);
	data->start_time = timern();
	data->philo = init_philo(data, -1);
	if (data->philo == NULL)
		return (1);
	return (0);
}
