/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:03 by mflury            #+#    #+#             */
/*   Updated: 2023/12/20 06:25:41 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	{
		list = list->next;
	}
	return (list);
}

void	addphilo(t_philo *list, t_philo *new_philo)
{
	t_philo	*philo;

	philo = lastphilo(list);
	if (!philo)
		list = new_philo;
	else
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
