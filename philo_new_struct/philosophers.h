/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 07:49:13 by mflury            #+#    #+#             */
/*   Updated: 2024/02/10 16:03:39 by mflury           ###   ########.fr       */
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

// struct for the arguments;
typedef struct	s_ctx
{
	struct s_philo	*philolist;
	int				philo_nb;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				meal_nb;
	size_t			start_time;
}				t_ctx;

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
void	deletephilolist(t_ctx *ctx);
void	showphilolist(t_philo *list);

// philo thread utils:
void	createphilothread(t_ctx *ctx, void *routine);
void	joinphilothread(t_ctx *ctx);

// philo mutex utils:
void	initphilomutex(t_ctx *ctx);
void	setphilonextmutex(t_ctx *ctx);
void	destroyphilomutex(t_ctx *ctx);

// arguments utils:
int		isvalidargs(int argc, char **argv);
void	setphiloparam(int argc, char **argv, t_ctx *ctx);
void	showphiloparam(t_ctx *ctx);
int		ft_atoi(const char *str);

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
