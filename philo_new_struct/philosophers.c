/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 07:45:03 by mflury            #+#    #+#             */
/*   Updated: 2024/02/09 16:12:30 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_ctx *ctx;
	int		id;

	id = 1;
	ctx->philolist = NULL;
	if (!isvalidargs(argc, argv))
		return 1;
	ctx->philolist = newphilo(id);
	while (id++ < 5)
		addphilo(ctx->philolist, newphilo(id));
	setphiloparam(argc, argv, &ctx);
	// showphiloparam(ctx->philoslist);
	initphilomutex(ctx->philolist);
	setphilonextmutex(ctx);
	createphilothread(ctx);
	joinphilothread(ctx);
	destroyphilomutex(ctx);
	deletephilolist(ctx);
	return 0;
}
