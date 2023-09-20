/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:35:31 by rfontes-          #+#    #+#             */
/*   Updated: 2023/09/20 17:18:08 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int parsing(char **argv)
{
	if(atol(argv[1])<1 || atol(argv[1])>200)
		{
			printf("Error");
			return(0);
		}
		args()->philo_num=atol(argv[1]);
		if(atol(argv[2])<0 || atol(argv[2])>2147483647)
		{
			printf("Error");
			return(0);
		}
		args()->time_to_die=atol(argv[2]);
		if(atol(argv[3])<0 || atol(argv[3])>2147483647)
		{
			printf("Error");
			return(0);
		}
		args()->time_to_eat=atol(argv[3]);
		if(atol(argv[4])<0 || atol(argv[4])>2147483647)
		{
			printf("Error");
			return(0);
		}
		args()->time_to_sleep=atol(argv[4]);
		if(argc>5)
		{
			if(atol(argv[5])<0 || atol(argv[5])>2147483647)
			{
				printf("Error");
				return(0);
			}
			args()->number_of_times_each_philosopher_must_eat=atol(argv[5]);
		}
}

void *thread_routine(void *args)
{

	gettimeofday();
	
	printf("Think");//outside of critical section
	
	pthread_mutex_lock(&lock);
	take fork n (if flag1=0, flag1=1, else if flag1=1, error)
	take fork n+1 (if flag2=0, flag2=1, else if flag2=1, error)
	(if flag1=1 && flag2=1?) eat
	pthread_mutex_unlock(&lock);
	usleep(args()->time_to_sleep);//outside of critical section
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t *threads malloc;
    int i;
	
    
	if(argc>4&&argc<7)
	{
		if(!parsing(argv))
		{
			printf("Error");
			return(0);
		}
		
		threads=(pthread_t *)malloc(philo_num*sizeof(pthread_t));
		threads=memset(threads, '\0',philo_num);//0 instead of \0?
		i=0;
		if (pthread_mutex_init(&lock, NULL) != 0) 
		{
    		printf("\n mutex init has failed\n");
     		return(0);
    	}
    	while(++i<=philo_num)
    	{
    	    if(pthread_create(&threads[i], NULL, thread_routine, &threads[i])!=0)
    	        printf("\nThread can't be created :[%s]", strerror(error));
    	}
		
		while(++i<=philo_num)
    	{
    	    if(pthread_join(threads[i], NULL)!=0)
    	        printf("\nError:[%s]", strerror(error));
    	}
		pthread_mutex_destroy(&lock);
		free(threads);
	}
	else
		printf("Error");
		return(0);
}