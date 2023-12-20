/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:19:43 by mflury            #+#    #+#             */
/*   Updated: 2023/12/20 21:53:08 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	(void) arg;
	printf("Hello!\n");
	return NULL;
}

int	main()
{
	t_philo *list;
	int		id;
	
	id = 1;
	list = NULL;
	list = newphilo(id);
	while (id++ < 4)
		addphilo(list, newphilo(id));
	createphilothread(list);
	joinphilothread(list);
	showphilolist(list);
	deletephilolist(list);
	return 0;
}
