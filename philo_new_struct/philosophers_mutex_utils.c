/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_mutex_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:40:41 by mflury            #+#    #+#             */
/*   Updated: 2024/01/31 12:02:11 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initphilomutex(t_ctx *ctx)
{
	while (ctx->philolist)
	{
		pthread_mutex_init(&ctx->philolist->mutex, NULL);
		ctx->philolist = ctx->philolist->next;
	}
}

void	destroyphilomutex(t_ctx *ctx)
{
	while (ctx->philolist)
	{
		pthread_mutex_destroy(&ctx->philolist->mutex);
		ctx->philolist = ctx->philolist->next;
	}
}

void	setphilonextmutex(t_ctx *ctx)
{
	pthread_mutex_t *first_mutex;

	first_mutex = &ctx->philolist->mutex;
	while (ctx->philolist->next)
	{
		ctx->philolist->next_mutex = &ctx->philolist->next->mutex;
		ctx->philolist = ctx->philolist->next;
	}
	ctx->philolist->next_mutex = first_mutex;
}
