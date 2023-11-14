/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:37:15 by mflury            #+#    #+#             */
/*   Updated: 2023/11/14 19:09:36 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *tid)
{
	printf("hi, im thread%s! how are you doing folk?\n", (char *)tid);
	sleep(1);
	printf("Thread: byebye friend.\n");
	return NULL;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	pthread_t	t1;
	pthread_t	t2;
	
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
