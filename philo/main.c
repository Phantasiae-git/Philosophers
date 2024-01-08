/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:35:31 by rfontes-          #+#    #+#             */
/*   Updated: 2024/01/08 19:08:38 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_routine(void *args)
{
	t_philo *
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
	t_data	data;
	int i;

	if (argc < 5 || argc > 6)
		return (-1);
	if (!parsing(argc, argv))
		return (-1);
	if (init_data(argc, argv, &data) == 1)
		return (-1);
	data.start_time = timern();
	i=-1;
	while (++i < data.number_of_philosophers)
	{
		if (pthread_join(data.philo[i].thread_id, NULL) != 0)
		{
			errormsg("thread join failed.");
			return(-1);
		}
	}
	free_all(data);
	return (0);
}
