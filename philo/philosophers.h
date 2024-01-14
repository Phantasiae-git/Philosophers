/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:35:42 by rfontes-          #+#    #+#             */
/*   Updated: 2024/01/13 23:13:58 by phantasiae       ###   ########.fr       */
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

# define TAKE_FORK "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define X "died"

struct	s_data;

typedef struct s_philo
{
	int				philo_num;
	pthread_t		thread_id;
	int				status;
	int				fork[2];
	int				mealcount;
	int				lastmeal;
	struct s_data	*data;
}					t_philo;

typedef struct s_data // philosophers start at 1 (not the array ofc), forks at 0
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_philo			*philo;
	pthread_mutex_t	*fork_locks;
	pthread_mutex_t	printlock;
	pthread_mutex_t	statuslock;
	int				start_time;
	int				status;
}					t_data;

int					timern(void);
int					parsing(int argc, char **argv);
int					ft_atol(const char *s);
int					init_data(int argc, char **argv, t_data *data);
void				*thread_routine(void *args);
void				printstuff(t_philo *philo, char *s);
void				ft_usleep(int time, t_data *data);
void				think(t_philo *philo);
void				honkshoo(t_philo *philo);
void				eat(t_philo *philo);
int					grim_reaper(t_philo *philo);
void				*stop_sim(void *args);
int					status_check(t_data *data);
void				free_all(t_data *data);

#endif