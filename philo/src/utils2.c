/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:48:47 by mflury            #+#    #+#             */
/*   Updated: 2024/02/12 01:33:29 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	dynamic_sleep(long long t_to_sleep, t_rules *rules)
{
	int			death_instance;
	long long	i;

	i = get_time_in_ms();
	pthread_mutex_lock(&rules->write_lock);
	death_instance = rules->dieded;
	pthread_mutex_unlock(&rules->write_lock);
	while (!(death_instance))
	{
		if (time_diff(i, get_time_in_ms()) >= t_to_sleep)
			break ;
		usleep(5);
	}
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

int	validity_check(char **argv, int argc)
{
	if (ft_atoi(argv[1]) >= 201 || ft_atoi(argv[1]) <= 0)
		return (1);
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		return (1);
	if (argc == 6)
		if (ft_atoi(argv[5]) == 0)
			return (2);
	return (0);
}

void	print_action(t_rules *rules, int philo_id, char *print, int color)
{
	pthread_mutex_lock(&(rules->write_lock));
	if (rules->dieded == 1 || rules->meal_finished == 1)
	{
		pthread_mutex_unlock(&(rules->write_lock));
		return ;
	}
	if (color == 0 && rules->dieded != 1)
		printf("%s", CYAN);
	else if (color == 1 && rules->dieded != 1)
		printf("%s", RED);
	else if (color == 2 && rules->dieded != 1)
		printf("%s", GREEN);
	else if (color == 3 && rules->dieded != 1)
		printf("%s", PURPLE);
	printf("%lldms ", get_time_in_ms() - rules->prog_debut);
	printf("%d ", philo_id);
	printf("%s\n", print);
	printf("%s", RESET);
	pthread_mutex_unlock(&(rules->write_lock));
}

void	print_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		printf("philo number %d\n\n", i + 1);
		printf("left_fork_id = [%d]\n", rules->philosopher[i].left_fork_id);
		printf("right_fork_id = [%d]\n", rules->philosopher[i].right_fork_id);
		printf("x_meal = [%d]\n", rules->philosopher[i].x_meal);
		printf("philo_id = [%d]\n\n", rules->philosopher[i].philo_id);
		i++;
	}
}
