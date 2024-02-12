/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:46:46 by mflury            #+#    #+#             */
/*   Updated: 2024/02/11 13:37:24 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc < 5 || argc > 6)
	{
		printf("Bad Arguments.\n");
		return (1);
	}
	if (make_rules(&rules, argv, argc))
		return (1);
	if (make_philo_thread(&rules))
	{
		printf("Thread error.\n");
		return (1);
	}
	return (0);
}
