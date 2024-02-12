/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:47:18 by mflury            #+#    #+#             */
/*   Updated: 2024/02/12 01:39:42 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	make_mutex(t_rules *rules)
{
	int	i;

	i = rules->number_of_philosophers;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->fork[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->write_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->death_lock), NULL))
		return (1);
	return (0);
}

void	set_philo(t_rules *rules, int actual_philo)
{
	t_philosopher	*philo;

	philo = rules->philosopher;
	if (rules->number_of_philosophers == 1)
	{
		philo[actual_philo].right_fork_id = actual_philo;
		philo[actual_philo].left_fork_id = 0;
		philo[actual_philo].last_meal = get_time_in_ms();
		philo[actual_philo].philo_id = (actual_philo + 1);
		philo[actual_philo].rules = rules;
		return ;
	}
	if (actual_philo == 0)
		philo[actual_philo].left_fork_id = rules->number_of_philosophers - 1;
	else
		philo[actual_philo].left_fork_id = actual_philo - 1;
	philo[actual_philo].right_fork_id = actual_philo;
	philo[actual_philo].last_meal = get_time_in_ms();
	philo[actual_philo].philo_id = (actual_philo + 1);
	philo[actual_philo].rules = rules;
}

void	init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		set_philo(rules, i);
		i++;
	}
}
