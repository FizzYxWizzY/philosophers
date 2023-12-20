/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:29:08 by mflury            #+#    #+#             */
/*   Updated: 2023/12/20 06:25:46 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>

// philo list:
typedef struct	s_philo
{
	int				id;
	struct s_philo	*next;
}				t_philo;

// philo linked list utils:
t_philo	*newphilo(int id);
void	addphilo(t_philo *list, t_philo *new_philo);
t_philo	*lastphilo(t_philo *list);
void	deletephilolist(t_philo *list);

#endif
