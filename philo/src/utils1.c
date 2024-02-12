/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:48:15 by mflury            #+#    #+#             */
/*   Updated: 2024/02/12 02:06:01 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_atoi(char *str)
{
	int	neg;
	int	res;
	int	i;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

int	is_number(char nb)
{
	if (nb >= '0' && nb <= '9')
		return (1);
	return (0);
}

int	argv_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	input_check(char **argv, int argc)
{
	if (argv_check(argv[1]))
		return (1);
	if (argv_check(argv[2]))
		return (1);
	if (argv_check(argv[3]))
		return (1);
	if (argv_check(argv[4]))
		return (1);
	if (argc == 6 && argv_check(argv[5]) == 1)
		return (1);
	return (0);
}

int	make_rules(t_rules *rules, char **argv, int argc)
{
	if (error_management(argv, argc))
		return (1);
	rules->number_of_philosophers = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	rules->dieded = 0;
	rules->meal_finished = 0;
	if (argc == 6)
		rules->meal_number = ft_atoi(argv[5]);
	else
		rules->meal_number = -1;
	if (rules->number_of_philosophers < 0 || rules->time_to_die < 0 
		|| rules->time_to_eat < 0 || rules->number_of_philosophers > 250)
		return (1);
	if (make_mutex(rules))
		return (1);
	init_philo(rules);
	return (0);
}
