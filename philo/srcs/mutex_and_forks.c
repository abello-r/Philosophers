/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_and_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:03:15 by abello-r          #+#    #+#             */
/*   Updated: 2021/10/15 16:02:46 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

void	ft_init_mutex(t_global *global)
{
	pthread_mutex_init(&global->args.end_mutex, NULL);
	pthread_mutex_init(&global->args.write_mutex, NULL);
	pthread_mutex_init(&global->args.t_eat_mutex, NULL);
	pthread_mutex_init(&global->args.dead_mutex, NULL);
}

int	ft_assigns_forks(t_global *global, int i)
{
	global->philo[i].own_fork = NULL;
	pthread_mutex_init(&global->philo[i].left_fork, NULL);

	if (global->args.total_philos == 1)
		return (1);

	if ((global->args.total_philos - 1) == i)
		global->philo[i].own_fork = &global->philo[0].left_fork;
	else
		global->philo[i].own_fork = &global->philo[i + 1].left_fork;
	return (0);
}

/*

int	ft_create_forks(t_sh *sh, int philo_num)
{
	sh->forks = malloc(sizeof(bool) * philo_num);
	if (!sh->forks)
		return (1);
	return (0);
}


int	ft_create_mutex(t_sh *sh, int philo_num)
{
	sh->mutex = malloc(sizeof(pthread_mutex_t) * philo_num);
	if (!sh->mutex)
		return (1);
	return (0);
}

void	ft_assigns_mutex(pthread_mutex_t *mutex, t_pa *pa, int pos, int count)
{
	pa->right_mut = &mutex[pos];
	if (pos == 0)
		pa->left_mut = &mutex[count -1];
	else
		pa->left_mut = &mutex[pos - 1];
}


int	ft_create_own_fork(t_pa *pa)
{
	pa->right_mut = malloc(sizeof(pthread_mutex_t) * pa->philo_num);
	if (!pa->right_mut)
		return (1);
	pthread_mutex_init(pa->right_mut, NULL);
	return (0);
}

*/