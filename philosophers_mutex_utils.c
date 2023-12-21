/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_mutex_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:04:02 by mflury            #+#    #+#             */
/*   Updated: 2023/12/21 05:10:17 by mflury           ###   ########.fr       */
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
