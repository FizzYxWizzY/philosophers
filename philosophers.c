/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:19:43 by mflury            #+#    #+#             */
/*   Updated: 2023/12/19 17:17:58 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main()
{
	t_philo *list;
	t_philo	*tmp;
	int		id;
	id = 1;
	list = NULL;
	list = newphilo(id);
	while (id++ < 4)
		addphilo(list, newphilo(id));
	tmp = list;
	while (tmp)
	{
		printf("philo id = %d\n", tmp->id);
		tmp = tmp->next;
	}
	deletephilolist(list);
	return 0;
}
