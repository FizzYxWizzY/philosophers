/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 07:45:03 by mflury            #+#    #+#             */
/*   Updated: 2024/02/10 15:32:08 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_ctx *ctx)
{
	pthread_mutex_lock(&ctx->philolist->mutex);
	pthread_mutex_lock(philo->next_mutex);
	philo->param->start = get_current_time();
	printf("[%ldms]\tPhilo %d: eats.\n", (philo->param->start - philo->param->start_time), philo->id);
	while ((get_current_time() - philo->param->start) < philo->param->eat_time)
		usleep(100);
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(philo->next_mutex);
}

void	philo_think(t_ctx *ctx)
{
	ctx->start = get_current_time();
	printf("[%ldms]\tPhilo %d: thinks.\n", (philo->param->start - philo->param->start_time), philo->id);
	usleep(100);
}

void	philo_sleep(t_ctx *ctx)
{
	ctx->start = get_current_time();
	printf("[%ldms]\tPhilo %d: sleeps.\n", (philo->param->start - philo->param->start_time), philo->id);
	while ((get_current_time() - philo->param->start) < philo->param->sleep_time)
		usleep(100);
}

void	*routine(void *arg)
{
	int	i;

	i = 0;
	if (((t_ctx *)arg)->philolist->id % 2)
		usleep(((t_ctx *)arg)->eat_time / 2);
	while (1)
	{
		philo_eat((t_ctx *)arg);
		philo_sleep((t_ctx *)arg);
		philo_think((t_ctx *)arg);
		i++;
	}
	return NULL;
}

int	main(int argc, char **argv)
{
	t_ctx *ctx;
	int		id;

	id = 1;
	if (!isvalidargs(argc, argv))
		return 1;
	ctx = malloc(sizeof(t_ctx));
	setphiloparam(argc, argv, ctx);
	ctx->philolist = newphilo(id);
	while (id++ < ctx->philo_nb)
		addphilo(ctx->philolist, newphilo(id));
	// showphiloparam(ctx->philoslist);
	initphilomutex(ctx);
	setphilonextmutex(ctx);
	createphilothread(ctx, routine);
	joinphilothread(ctx);
	destroyphilomutex(ctx);
	deletephilolist(ctx);
	return 0;
}
