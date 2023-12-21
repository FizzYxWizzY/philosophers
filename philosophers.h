/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:29:08 by mflury            #+#    #+#             */
/*   Updated: 2023/12/21 23:00:39 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>

// struct for philosophers list:
typedef struct	s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*next_mutex;
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

// philo mutex utils:
void	initphilomutex(t_philo *list);
void	setphilonextmutex(t_philo *list);
void	destroyphilomutex(t_philo *list);

// arguments utils:
int		ft_atoi(const char *str);
int		isvalidargs(int argc, char **argv);

// time utils:
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);

// routine common to all the philosophers:
void	*routine(void *arg);
void	philo_eat(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
// TODO LIST:

// argv:
// // use argv as parameters.
// timer:
// // make a timestamper for all the actions/philos.
// routine:
// // make the routine eat/think/sleep.
// // 

#endif
