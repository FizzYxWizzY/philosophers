/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_args_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:32:49 by mflury            #+#    #+#             */
/*   Updated: 2023/12/30 05:36:57 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	showphiloparam(t_philo *list)
{
	while (list)
	{
		printf("Philo %d:\n%d\n%ld\n%ld\n%ld\n%d\n\n", list->id, list->param->philo_nb,
			list->param->death_time, list->param->eat_time,
			list->param->sleep_time, list->param->meal_nb);
		list = list->next;
	}
}

void	setphiloparam(int argc, char **argv, t_philo *list)
{
	while (list)
	{
		list->param = malloc(sizeof(t_param));
		if (argc == 5)
		{
			list->param->philo_nb = ft_atoi(argv[1]);
			list->param->death_time = ft_atoi(argv[2]);
			list->param->eat_time = ft_atoi(argv[3]);
			list->param->sleep_time = ft_atoi(argv[4]);
			list->param->meal_nb = 0;
		}
		if (argc == 6)
		{
			list->param->philo_nb = ft_atoi(argv[1]);
			list->param->death_time = ft_atoi(argv[2]);
			list->param->eat_time = ft_atoi(argv[3]);
			list->param->sleep_time = ft_atoi(argv[4]);
			list->param->meal_nb = ft_atoi(argv[5]);
		}
		list = list->next;
	}
}

int	isvalidargs(int argc, char **argv)
{
	int i;
	int	j;

	i = 1;
	j = 0;
	if ((argc != 5) & (argc != 6))
		return 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((argv[i][j] > '9') | (argv[i][j] < '0'))
				return 0;
			j++;
		}
		j = 0;
		i++;
	}
	return 1;
}

int	ft_atoi(const char *str)
{
	int				res;
	int				sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
