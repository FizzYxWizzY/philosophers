/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_thread_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:16:04 by mflury            #+#    #+#             */
/*   Updated: 2024/02/08 08:39:16 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	createphilothread(t_ctx *ctx)
{
	ctx->start_time = get_current_time();
	while (ctx->philolist)
	{
		pthread_create(&ctx->philolist->thread, NULL, &routine, (void *)ctx);
		ctx->philolist = ctx->philolist->next;
	}
}

void	joinphilothread(t_ctx *ctx)
{
	while (ctx->philolist)
	{
		pthread_join(ctx->philolist->thread, NULL);
		ctx->philolist = ctx->philolist->next;
	}
}
