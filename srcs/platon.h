 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:39:20 by abello-r          #+#    #+#             */
/*   Updated: 2021/09/27 18:37:57 by abello-r         ###   ########.fr       */
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
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

/** Arguments Error **/
# define LARG "\nInvalid Arguments\n\n"
# define NARG "\nThe number of philos cannot be 0\n\n"
# define MARG "\nThe number of philos cannot be major than 200\n\n"
# define PARSE "\nInvalid Character\n\n"

/*** [ Table ] ********************************************/
/**/	typedef struct	s_args							/**/
/**/	{												/**/
/**/		uint64_t		start_time;					/**/
/**/		int				total_philos;				/**/
/**/		int				time_2_die;					/**/
/**/		int				time_2_eat;					/**/
/**/		int				time_2_sleep;				/**/
/**/		int				limit_eat;					/**/
/**/													/**/
/**/		pthread_mutex_t write_mutex;				/**/
/**/													/**/
/**/	}				t_args;							/**/
/**********************************************************/


/*** [ Struct by philo ] **********************************/
/**/	typedef struct s_philo							/**/
/**/	{												/**/
/**/		t_args					*args;				/**/
/**/													/**/
/**/		pthread_mutex_t			own_fork;			/**/
/**/		pthread_t				thread;				/**/
/**/													/**/
/**/		int			index;							/**/
/**/													/**/
/**/	}				t_philo;						/**/
/**********************************************************/


/*** [ Global struct ] ************************************/
/**/	typedef struct 	s_global						/**/
/**/	{												/**/
/**/		t_philo		*philo;							/**/
/**/		t_args		args;							/**/
/**/													/**/
/**/	}							t_global;			/**/
/**********************************************************/




	/***[ MINI_LIBFT.C ] functions ****************************/
	/**/int			ft_atoi(const char *str);    	 	   /**/
	/**/int			ft_isdigit(int c);				      /**/
	/*******************************************************/


	/***[ TIME_UTILS.C ] functions ********************************/
	/**/uint64_t	ft_get_time(uint64_t reference);	 	   /**/	
	/**/void		ft_usleep(uint64_t time_in_ms);			  /**/
	/***********************************************************/


	/***[ STRUCTS.C ] functions *****************************************************/
	/**/int			ft_fill_struct(int argc, char **argv, t_global *global);	 /**/
	/**/int			ft_init_struct(t_global *global);							/**/
	/*****************************************************************************/


	/***[ INIT_MUTEX.C ] functions *******************************/
	/**/void		ft_init_mutex(t_global *global);		  /**/
	/***********************************************************/

	
	/***[ RUTINE.C ] functions ************************************/
	/**/int			ft_create_threads(t_global *global); 	   /**/
	/**/void		*ft_loop(void *values);					  /**/
	/**/void		ft_rutine(t_philo *philo);		   		 /**/
	/**********************************************************/

	/***[ FT_EAT.C ] functions *************************************/
	/**/void		ft_take_a_fork(t_philo *philo);				/**/
	/**/void		ft_eat(t_philo *philo);					   /**/
	/************************************************************/


	void		ft_show_condition(t_philo *philo, char *condition);

#endif