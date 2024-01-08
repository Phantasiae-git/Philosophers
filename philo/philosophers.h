/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:35:42 by rfontes-          #+#    #+#             */
/*   Updated: 2024/01/08 14:29:19 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	int			philo_num;
	pthread_t	thread_id;//not sure abt this
	int			status;
	int			fork[2];
	int			mealcount;
	int			lastmeal;
}				t_philo;

typedef struct s_data
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	t_philo		**philo;
	pthread_mutex_t *fork_locks; // fork[number_of_philosophers]
	pthread_mutex_t printlock;
	int			start_time;
}				t_data;

int			ft_atol(const char *str);
t_philo			*philo(void);
int				timern(void);

#endif