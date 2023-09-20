/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:35:42 by rfontes-          #+#    #+#             */
/*   Updated: 2023/09/20 17:13:37 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_data
{
	int         *fork;//fork[number_of_philosophers] content is 0 is available, 1 if taken
	int         number_of_philosophers
	int         time_to_eat;
    int         time_to_sleep;
    int         number_of_times_each_philosopher_must_eat;
	t_philo		*philo;
}				t_data;

typedef struct s_philo
{
	int         philo_num;
	char        *status;
	int			forksnum; 
}				t_philo;

long	ft_atol(const char *str, long negative);
t_philo	*args(void);

#endif