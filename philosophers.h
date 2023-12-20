/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:29:08 by mflury            #+#    #+#             */
/*   Updated: 2023/12/20 21:51:19 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>

// struct for philosophers list:
typedef struct	s_philo
{
	int				id;
	pthread_t		thread;
	struct s_philo	*next;
}				t_philo;

// philo linked list utils:
t_philo	*newphilo(int id);
t_philo	*lastphilo(t_philo *list);
void	addphilo(t_philo *list, t_philo *new_philo);
void	deletephilolist(t_philo *list);
void	showphilolist(t_philo *list);

// philo thread utils:
void	createphilothread(t_philo *list);
void	joinphilothread(t_philo *list);

// routine of all the philosophers:
void	*routine(void *arg);

// TODO LIST:

// add thread to list,
// // put thread in node,
// // make a function that create all threads
// // make a function that join the threads;
// add mutex to list,
// // need to put a delay to join the threads /!\ deadlocks /!\,
// // 
// need to make utils 

#endif
