/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:35:42 by rfontes-          #+#    #+#             */
/*   Updated: 2024/01/08 19:06:07 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int			philo_num;
	pthread_t	thread_id;
	int			status;
	int fork[2]; // not necessarily left and right, but 1st and 2nd to be picked up
	int			mealcount;
	int			lastmeal;
}				t_philo;

typedef struct s_data // both forks and philosophers start at 1
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	t_philo *philo;              // array starts at 0 tho ofc
	pthread_mutex_t *fork_locks; // fork[number_of_philosophers]
	pthread_mutex_t printlock;
	int start_time;
	int status;
}				t_data;

int				ft_atol(const char *str);
t_philo			*philo(void);
int				timern(void);
int				init_data(int argc, char **argv, t_data *data);
void			*thread_routine(void *args);
void			errormsg(char *msg);

#endif