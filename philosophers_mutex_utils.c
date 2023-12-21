/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_mutex_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:04:02 by mflury            #+#    #+#             */
/*   Updated: 2023/12/21 07:01:15 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initphilomutex(t_philo *list)
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

void	setphilonextmutex(t_philo *list)
{
	pthread_mutex_t *first_mutex;

	first_mutex = &list->mutex;
	while (list->next)
	{
		list->next_mutex = &list->next->mutex;
		list = list->next;
	}
	list->next_mutex = first_mutex;
}
