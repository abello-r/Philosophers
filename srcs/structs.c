/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 18:09:55 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/13 18:35:54 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

int	ft_fill_struct(int argc, char **argv, t_table *table)
{
	table->total_philos = ft_atoi(argv[1]);
	table->time_2_die = ft_atoi(argv[2]);
	table->time_2_eat = ft_atoi(argv[3]);
	table->time_2_sleep = ft_atoi(argv[4]);
	table->limit_eat = -1;
	if (argc == 6)
		table->limit_eat = ft_atoi(argv[5]);
	if (table->total_philos <= 0 || table->time_2_die <= 0
		|| table->time_2_eat <= 0 || table->time_2_sleep <= 0)
		return (1);
	return (0);
}

int	ft_init_struct(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = ft_get_time(0);
	ft_init_mutex(table);

	while (i < table->total_philos)
	{
		pthread_mutex_init(&table->philo[i].own_fork, NULL);
		table->philo[i].index = i + 1;
		i++;
	}
	return (1);
}
