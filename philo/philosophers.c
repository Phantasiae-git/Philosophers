/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:35:31 by rfontes-          #+#    #+#             */
/*   Updated: 2024/01/08 14:33:53 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_routine(void *args)
{
	gettimeofday();
	while (i < number_of_times_each_philosopher_must_eat || flag = 1)
	{
		if (thread_id % 2)
			printf("Think"); // outside of critical section
		pthread_mutex_lock(&lock);
		take fork n (if flag1=0, flag1=1, else if flag1=1, error)
		take fork n+1 (if flag2=0, flag2=1, else if flag2=1, error)
		(if flag1=1 && flag2=1?) eat
		pthread_mutex_unlock(&lock);
		usleep(args()->time_to_sleep); // outside of critical section
		if (!thread_id % 2)
			printf("Think"); // outside of critical section
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		error("usage:");
		return (0);
	}
	if (!parsing(argc, argv))
		return (0);
	threads = (pthread_t *)malloc(philo_num * sizeof(pthread_t));
	threads = memset(threads, '\0', philo_num); // 0 instead of \0?
	i = 0;
	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\n mutex init has failed\n");
		return (0);
	}
	gettimeofday(); //simulation start
	while (++i <= philo_num)
	{
		if (pthread_create(&threads[i], NULL, thread_routine, data) != 0)
			error("Thread can't be created \n");
	}
	while (++i <= philo_num)
	{
		if (pthread_join(threads[i], NULL) != 0)
			printf("\nError:[%s]", strerror(error));
	}
	pthread_mutex_destroy(&lock);
	i = -1;
	while (++i < philo_num)
		free(data->philo[i]);
	free(data);
	printf("Error");
	return (0);
}
