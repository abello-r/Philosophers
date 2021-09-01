/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:39:20 by abello-r          #+#    #+#             */
/*   Updated: 2021/09/01 19:28:13 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLATON_H
# define PLATON_H

/** Allow functions

*** Output messages ***
	1- printf
	2- write

*** Memory management ***
	1- malloc
	2- free
	3- memset

*** Time management ***
	1- usleep = Suspends execution of the calling thread for (at least) usec microseconds.
	2- gettimeofday = Actual time in microseconds.

*** Threads management ***
	1- pthread_create
	2- pthread_detach
	3- pthread_join
	4- pthread_mutex_init
	5- pthread_mutex_destroy
	6- pthread_mutex_lock
	7- pthread_mutex_unlock

**/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>

/** Min and Max INT **/
# define MAX_INT 2147483647
# define MIN_INT -2147483648


/** Colorize output **/
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

/** Arguments Error **/
# define LARG "\nInvalid Arguments\n\n"
# define NARG "\nThe number of philos cannot be 0\n\n"
# define PARSE "\nInvalid Character\n\n"

/** Struct Value arguments **/
typedef	struct	s_pa
{
	pthread_t	*philo;
	int			philo_num;
	uint64_t	t_2_eat;
	uint64_t	t_2_die;
	uint64_t	t_2_sleep;
	bool		eat_flag;
	int			c_2_eat;
	int			index;
}				t_pa;

/** Conversion functions **/
int		ft_atoi(const char *str);

/** Memory functions **/
void	ft_bzero(void *s, size_t n);

/** Basic functions **/
int		ft_isdigit(int c);
void	ft_fill_structs(t_pa **pa, int argc, char **argv);

int		ft_thread_x_philo(t_pa *pa);

/** Test functions **/
void	ft_print_data(t_pa **pa, char **argv);

#endif