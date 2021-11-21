/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:39:20 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/21 01:01:43 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLATON_H
# define PLATON_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<sys/time.h>
# include	<pthread.h>
# include	<stdbool.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define MAGN "\033[1;35m"
# define WHT "\033[1;38m"
# define RESET "\033[1m"

# define LARG "\nInvalid Arguments\n\n"
# define NARG "\nThe number of philos cannot be 0\n\n"
# define MARG "\nThe number of philos cannot be major than 200\n\n"
# define PARSE "\nInvalid Character\n\n"
# define LESS "\nData cannot be less than 60\n\n"

typedef struct s_philo	t_philo;

typedef struct s_table
{
	uint64_t		start_time;
	int				total_philos;
	int				time_2_die;
	int				time_2_eat;
	int				time_2_sleep;
	int				limit_eat;
	int				is_dead;
	int				each_philo_eat;						
	t_philo			*philo;	
	pthread_mutex_t	write_mutex;					
}				t_table;	

typedef struct s_philo
{
	t_table					*table;
	int						last_eat;
	int						counter_eat;
	int						index;
	pthread_mutex_t			own_fork;
	pthread_t				thread;
}				t_philo;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_strcmp(char *s1, char *s2);
uint64_t	ft_get_time(uint64_t reference);
void		ft_usleep(uint64_t time_in_ms);
int			ft_fill_struct(int argc, char **argv, t_table *table);
int			ft_init_struct(t_table *table);
void		ft_init_mutex(t_table *global);
int			ft_create_threads(t_table *global);
void		*ft_loop(void *values);
void		ft_rutine(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_death(t_table *table);
int			ft_msg(t_philo *philo, char *status);
#endif