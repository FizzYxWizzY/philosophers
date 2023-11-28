/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:37:15 by mflury            #+#    #+#             */
/*   Updated: 2023/11/28 15:42:31 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *mutex)
{
	static int	i = 0;
	
	while (1)
	{
		if (!(i < 10000))
		{
			printf("Thread: byebye friend.\n");
			return NULL;
		}
		pthread_mutex_lock(mutex);
		if (i < 10000)
		{
			printf("Thread: %d\n", i + 1);
			i++;
			usleep(1000);
		}
		pthread_mutex_unlock(mutex);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	pthread_t	t1;
	pthread_t	t2;
	pthread_t	t3;
	pthread_t	t4;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);	
	pthread_create(&t1, NULL, &routine, &mutex);
	pthread_create(&t2, NULL, &routine, &mutex);
	pthread_create(&t3, NULL, &routine, &mutex);
	pthread_create(&t4, NULL, &routine, &mutex);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	pthread_mutex_destroy(&mutex);
	return (0);
}
