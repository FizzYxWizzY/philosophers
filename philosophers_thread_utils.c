/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_thread_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:31:42 by mflury            #+#    #+#             */
/*   Updated: 2023/12/21 04:50:08 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	createphilothread(t_philo *list)
{
	while (list)
	{
		pthread_create(&list->thread, NULL, &routine, (void *)list);
		list = list->next;
	}
}

void	joinphilothread(t_philo *list)
{
	while (list)
	{
		pthread_join(list->thread, NULL);
		list = list->next;
	}
}

void	createphilomutex(t_philo *list)
{
	while (list)
	{
		pthread_mutex_init(&list->mutex, NULL);
		list = list->next;
	}
}

void	destroyphilomutex(t_philo *list)
{
	while (list)
	{
		pthread_mutex_destroy(&list->mutex);
		list = list->next;
	}
}