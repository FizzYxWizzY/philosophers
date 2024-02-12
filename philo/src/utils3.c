/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:50:21 by mflury            #+#    #+#             */
/*   Updated: 2024/02/12 01:48:47 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	death(t_rules *rules, int *i)
{
	t_philosopher	*philo;

	philo = rules->philosopher;
	while (++*i < rules->number_of_philosophers && rules->dieded == 0)
	{
		pthread_mutex_lock(&rules->death_lock);
		if (time_diff(philo[*i].last_meal, get_time_in_ms()) 
			> rules->time_to_die)
		{
			print_action(rules, philo[*i].philo_id, "died", 1);
			pthread_mutex_lock(&rules->write_lock);
			rules->dieded = 1;
			pthread_mutex_unlock(&rules->write_lock);
		}
		pthread_mutex_unlock(&rules->death_lock);
	}
}

int	error_management(char **argv, int argc)
{
	if (input_check(argv, argc))
	{
		printf("invalid arguments\n");
		return (1);
	}
	if (validity_check(argv, argc) == 2)
		return (1);
	else if (validity_check(argv, argc) == 1)
	{
		printf("wrong input\n");
		return (1);
	}
	return (0);
}
