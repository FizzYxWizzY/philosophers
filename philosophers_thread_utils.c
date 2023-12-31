/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_thread_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:31:42 by mflury            #+#    #+#             */
/*   Updated: 2023/12/30 06:19:27 by mflury           ###   ########.fr       */
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
	size_t	start;

	start = get_current_time();
	while (list)
	{
		list->param->start_time = start;
		pthread_join(list->thread, NULL);
		list = list->next;
	}
}
