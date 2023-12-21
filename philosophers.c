/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:19:43 by mflury            #+#    #+#             */
/*   Updated: 2023/12/21 07:16:32 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	if (((t_philo *)arg)->id % 2)
		usleep(100000);
	pthread_mutex_lock(&((t_philo *)arg)->mutex);
	pthread_mutex_lock(((t_philo *)arg)->next_mutex);
	printf("Philo%d: Hello!\n", ((t_philo *)arg)->id);
	printf("philo's mutex: %p\n", &((t_philo *)arg)->mutex);
	printf("next mutex: %p\n", ((t_philo *)arg)->next_mutex);
	pthread_mutex_unlock(&((t_philo *)arg)->mutex);
	pthread_mutex_unlock(((t_philo *)arg)->next_mutex);
	return NULL;
}

int	main()
{
	t_philo *list;
	int		id;
	
	id = 1;
	list = NULL;
	list = newphilo(id);
	while (id++ < 5)
		addphilo(list, newphilo(id));
	initphilomutex(list);
	setphilonextmutex(list);
	createphilothread(list);
	joinphilothread(list);
	destroyphilomutex(list);
	deletephilolist(list);
	return 0;
}
