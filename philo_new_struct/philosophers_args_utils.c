/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_args_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:42:09 by mflury            #+#    #+#             */
/*   Updated: 2024/02/10 16:03:32 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	showphiloparam(t_ctx *ctx)
{
	while (ctx->philolist)
	{
		printf("Philo %d:\n%d\n%d\n%d\n%d\n%d\n\n", ctx->philolist->id, ctx->philo_nb,
			ctx->death_time, ctx->eat_time, ctx->sleep_time, ctx->meal_nb);
		ctx->philolist = ctx->philolist->next;
	}
}

void	setphiloparam(int argc, char **argv, t_ctx *ctx)
{
	while (ctx->philolist)
	{
		if (argc == 5)
		{
			ctx->philo_nb = ft_atoi(argv[1]);
			ctx->death_time = ft_atoi(argv[2]);
			ctx->eat_time = ft_atoi(argv[3]);
			ctx->sleep_time = ft_atoi(argv[4]);
			ctx->meal_nb = 0;
		}
		else if (argc == 6)
		{
			ctx->philo_nb = ft_atoi(argv[1]);
			ctx->death_time = ft_atoi(argv[2]);
			ctx->eat_time = ft_atoi(argv[3]);
			ctx->sleep_time = ft_atoi(argv[4]);
			ctx->meal_nb = ft_atoi(argv[5]);
		}
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
