/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:35:31 by rfontes-          #+#    #+#             */
/*   Updated: 2024/01/15 20:04:54 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->data->number_of_philosophers < 2)
	{
		printstuff(philo, TAKE_FORK);
		ft_usleep(philo->data->time_to_die, philo->data);
	}
	if (philo->philo_num % 2 == 0)
		ft_usleep(50, philo->data);
	while (status_check(philo->data))
	{
		if (philo->philo_num % 2 == 0)
			think(philo);
		if (!status_check(philo->data))
			break ;
		eat(philo);
		if (!status_check(philo->data))
			break ;
		honkshoo(philo);
		if (philo->philo_num % 2)
			think(philo);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	grim_reaper;
	int			i;

	if (argc < 5 || argc > 6)
		return (-1);
	if (!parsing(argc, argv))
		return (-1);
	if (init_data(argc, argv, &data) == 1)
		return (-1);
	i = -1;
	pthread_create(&grim_reaper, NULL, &stop_sim, &data);
	pthread_detach(grim_reaper);
	while (++i < data.number_of_philosophers)
	{
		if (pthread_join(data.philo[i].thread_id, NULL) != 0)
			return (-1);
	}
	free_all(&data);
	return (0);
}
