/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:37:15 by mflury            #+#    #+#             */
/*   Updated: 2023/11/15 02:04:41 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *mutex)
{
	static int	i = 0;
	
	while (1)
	{
		pthread_mutex_lock((pthread_mutex_t *)mutex);
		// pthread_mutex_lock((pthread_mutex_t *)mutex);
		printf("Thread: %d\n", i);
		i++;
		usleep(100000);
		pthread_mutex_unlock((pthread_mutex_t *)mutex);
		if (i >= 100)
		{
			printf("Thread: byebye friend.\n");
			return NULL;
		}
	}
	// pthread_mutex_unlock((pthread_mutex_t *)mutex);
	// printf("Thread: byebye friend.\n");
	// pthread_mutex_unlock((pthread_mutex_t *)mutex);
	// return NULL;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	pthread_t	t1;
	pthread_t	t2;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);	
	pthread_create(&t1, NULL, &routine, (void *)&mutex);
	pthread_create(&t2, NULL, &routine, (void *)&mutex);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&mutex);
	return (0);
}
