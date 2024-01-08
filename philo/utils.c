/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:14:11 by rfontes-          #+#    #+#             */
/*   Updated: 2024/01/08 19:25:10 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*t_philo	*philo(void)
{
	static t_philo	philo;

	return (&philo);
}

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}*/

void printstuff(char *s, t_data *data, t_philo *philo)
{
	int time;

	//check if the simulation should stop
	pthread_mutex_lock(&data->printlock);
	time=timern();
	printf("%d %d %s", time-(data->start_time), philo->philo_num, s);
	pthread_mutex_unlock(&data->printlock);
}

void errormsg(char *msg)
{
	printf("ERROR: %s", msg);
	return;
}

int	timern(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(int time)
{
	int	rn;

	rn = timern();
	while ((timern() - rn) < time)
		usleep(time / 10);
}

void free_all(t_data *data)
{
	int i;

	i=-1;
	free(data->philo);
	while (++i<data->number_of_philosophers)
		pthread_mutex_destroy(&data->fork_locks[i]);
	free(data->fork_locks);
	free(data->philo);
	pthread_mutex_destroy(&data->printlock);
}