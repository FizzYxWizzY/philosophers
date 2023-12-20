/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:03 by mflury            #+#    #+#             */
/*   Updated: 2023/12/20 21:09:15 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	showphilolist(t_philo *list)
{
	while (list)
	{
		printf("Philo id: %d\n", list->id);
		list = list->next;
	}
}

void	deletephilolist(t_philo *list)
{
	t_philo	*tmp;
 
	while (list->next)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	free(list);
}

t_philo	*lastphilo(t_philo *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void	addphilo(t_philo *list, t_philo *new_philo)
{
	t_philo	*philo;

	if (!list)
		list = new_philo;
	philo = lastphilo(list);
	philo->next = new_philo;
}

t_philo	*newphilo(int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
	{
		return (NULL);
	}
	philo->id = id;
	philo->next = NULL;
	return (philo);
}
