/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:14:11 by rfontes-          #+#    #+#             */
/*   Updated: 2024/01/13 23:22:29 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	printstuff(t_philo *philo, char *s)
{
	t_data	*data;
	int		time;

	data = philo->data;
	pthread_mutex_lock(&data->printlock);
	time = timern() - data->start_time;
	if(time<0)
		time=0;
	if(status_check(data))
		printf("%d %d %s\n", time, philo->philo_num, s);
	pthread_mutex_unlock(&data->printlock);
}

int	timern(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		return (0);
	return ((int)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

void	ft_usleep(int time, t_data *data)
{
	int	rn;

	rn = timern();
	while ((timern() - rn) < time)
	{
		if(!status_check(data))
			break;
		usleep(time / 10);
	}
}

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->fork_locks[i]);
	free(data->fork_locks);
	free(data->philo);
	pthread_mutex_destroy(&data->printlock);
	pthread_mutex_destroy(&data->statuslock);
}
