/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:19:43 by mflury            #+#    #+#             */
/*   Updated: 2023/12/21 06:04:08 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	pthread_mutex_lock(&((t_philo *)arg)->mutex);
	printf("Philo%d: Hello!\n", ((t_philo *)arg)->id);
	printf("philo's mutex: %p\n", &((t_philo *)arg)->mutex);
	pthread_mutex_unlock(&((t_philo *)arg)->mutex);
	return NULL;
}

int	main()
{
	t_philo *list;
	int		id;
	
	id = 1;
	list = NULL;
	list = newphilo(id);
	while (id++ < 4)
		addphilo(list, newphilo(id));
	initphilomutex(list);
	createphilothread(list);
	joinphilothread(list);
	// showphilolist(list);
	destroyphilomutex(list);
	deletephilolist(list);
	return 0;
}
