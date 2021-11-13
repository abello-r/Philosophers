/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 18:09:55 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/13 10:25:14 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

int	ft_fill_struct(int argc, char **argv, t_global *global)
{
	global->args.total_philos = ft_atoi(argv[1]);
	global->args.time_2_die = ft_atoi(argv[2]);
	global->args.time_2_eat = ft_atoi(argv[3]);
	global->args.time_2_sleep = ft_atoi(argv[4]);
	global->args.limit_eat = -1;
	if (argc == 6)
		global->args.limit_eat = ft_atoi(argv[5]);
	if (global->args.total_philos <= 0 || global->args.time_2_die <= 0
		|| global->args.time_2_eat <= 0 || global->args.time_2_sleep <= 0)
		return (1);
	return (0);
}

int	ft_init_struct(t_global *global)
{
	int	i;

	i = 0;
	global->args.start_time = ft_get_time(0);
	ft_init_mutex(global);

	while (i < global->args.total_philos)
	{
		pthread_mutex_init(&global->philo[i].own_fork, NULL);
		global->philo[i].index = i + 1;
		i++;
	}
	return (1);
}
