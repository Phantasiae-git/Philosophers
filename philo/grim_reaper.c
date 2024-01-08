/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:30:58 by phantasiae        #+#    #+#             */
/*   Updated: 2024/01/08 23:52:05 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	*stop_sim(void *args)
{
	int		i;
	int		full;
	t_data	*data;

	i = -1;
	data = (t_data *)args;
	full = 0;
	while (data->status == 1)
	{
		while (++i < data->number_of_philosophers)
		{
			if (!grim_reaper(&data->philo[i]))
				data->status = 0;
			if (data->number_of_times_each_philosopher_must_eat
				&& data->philo[i].mealcount >= data->number_of_times_each_philosopher_must_eat)
				full++;
		}
		if (full == data->number_of_philosophers)
			data->status = 0;
	}
    return(NULL);
}
