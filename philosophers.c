/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:19:43 by mflury            #+#    #+#             */
/*   Updated: 2023/12/23 06:15:02 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	pthread_mutex_lock(philo->next_mutex);
	printf("Philo %d: eats.\n", philo->id);
	usleep(100);
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(philo->next_mutex);
}

void	philo_think(t_philo *philo)
{
	printf("Philo %d: thinks.\n", philo->id);
	usleep(100);
}

void	philo_sleep(t_philo *philo)
{
	printf("Philo %d: sleeps.\n", philo->id);
	usleep(100);
}

void	*routine(void *arg)
{
	int	i;

	i = 0;
	if (((t_philo *)arg)->id % 2)
		usleep(100);
	while (i < 1)
	{
		philo_eat((t_philo *)arg);
		philo_think((t_philo *)arg);
		philo_sleep((t_philo *)arg);
		i++;
	}
	return NULL;
}

int	main(int argc, char **argv)
{
	t_philo *list;
	int		id;

	id = 1;
	list = NULL;
	if (!isvalidargs(argc, argv))
		return 1;
	
	list = newphilo(id);
	while (id++ < 5)
		addphilo(list, newphilo(id));
	setphiloparam(argc, argv, list);
	showphiloparam(list);
	initphilomutex(list);
	setphilonextmutex(list);
	createphilothread(list);
	joinphilothread(list);
	destroyphilomutex(list);
	deletephilolist(list);
	return 0;
}
