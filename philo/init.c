/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:27:24 by rfontes-          #+#    #+#             */
/*   Updated: 2023/09/29 16:31:21 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo **init_philo(t_data data)
{
	int i;
	t_philo **philos;
	
	philos=malloc(sizeof(t_philo)*data->number_of_philosophers);
	if(!philos)
		return(NULL);
	while(i<number_of_philosophers)
	{
		philos[i]=malloc(sizeof(t_philo));
		if(!philos[i])
			return(NULL);
		philos[i]->philo_num=i+1;
		philos[i]->fork[0]=i+1;
		philos[i]->fork[1]=i+2;
		philos[i]->eatcount=0;
		philos[i]->status=1;
		philos[i]->lastmeal=timern();
	}
	return(philos);
}

t_data *init_data(int argc, char **argv)
{
	t_data *data;
	
	data=malloc(sizeof(data));
	data->number_of_philosophers=ft_atol(argv[1]);
	data->time_to_die=ft_atol(argv[2]);
	data->time_to_eat=ft_atol(argv[3]);
	data->time_to_sleep=ft_atol(argv[4]);
	if(argc==6)
		data->number_of_times_each_philosopher_must_eat=ft_atol(argv[5]);
	data->philo=init_philo(data);
	return(data);
}
