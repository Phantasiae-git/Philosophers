/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:30:58 by phantasiae        #+#    #+#             */
/*   Updated: 2024/01/13 23:55:42 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int status_check(t_data *data)
{
	pthread_mutex_lock(&data->statuslock);
	if(data->status==1)
	{
		pthread_mutex_unlock(&data->statuslock);
		return(1);
	}
	else
	{
		pthread_mutex_unlock(&data->statuslock);
		return(0);
	}
}

void status_set0(t_data *data)
{
	pthread_mutex_lock(&data->statuslock);
	if(data->status==1)
		data->status=0;
	pthread_mutex_unlock(&data->statuslock);
}

int	grim_reaper(t_philo *philo)
{
	if (philo->status == 1 && (timern()
			- (philo->lastmeal) >= philo->data->time_to_die))
	{
		printstuff(philo, X);
		philo->status = 0;
	}
	return (philo->status);
}

int check_full(t_data *data, int i)
{
	if (data->philo[i].mealcount < data->number_of_times_each_philosopher_must_eat)
		return(0);
	return(1);
}

void	*stop_sim(void *args)
{
	int		i;
	int		full;
	t_data	*data;

	data = (t_data *)args;
	while (status_check(data))
	{
		full = 1;
		i = -1;
		while (++i < data->number_of_philosophers)
		{
			if (!grim_reaper(&data->philo[i]))
				status_set0(data);
			if (data->number_of_times_each_philosopher_must_eat>0)
			{
				if (!check_full(data, i))
					full=0;
			}
		}
		if (full == 1 && data->number_of_times_each_philosopher_must_eat>0)
			status_set0(data);
	}
    return(NULL);
}
