/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:52:47 by mflury            #+#    #+#             */
/*   Updated: 2024/01/31 11:57:49 by mflury           ###   ########.fr       */
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
 
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->param);
		free(tmp);
	}
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
