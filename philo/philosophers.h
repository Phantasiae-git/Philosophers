/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:35:42 by rfontes-          #+#    #+#             */
/*   Updated: 2023/09/21 15:32:06 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				philo_num;
	pthread_t		thread_id;
	char			*status;
	int				fork[2];
	int				eatcount;
	int				lastmeal;
}					t_philo;

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_philo			*philo;
	pthread_mutex_t	*fork_locks;// fork[number_of_philosophers]
}					t_data;



long				ft_atol(const char *str, long negative);
t_philo				*philo(void);

#endif