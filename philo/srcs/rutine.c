/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:20:29 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/21 11:07:17 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

void	*ft_loop(void *values)
{
	t_philo	*philo;

	philo = (t_philo *)values;
	if (philo->index % 2 == 0)
		usleep(1000);
	while (philo->table->is_dead == 0)
	{
		ft_eat(philo);
		if (philo->counter_eat == philo->table->limit_eat)
		{
			philo->table->each_philo_eat = 1;
			break ;
		}
		ft_msg(philo, "sleep");
		ft_usleep(philo->table->time_2_sleep);
		ft_msg(philo, "think");
	}
	return (0);
}

int	ft_create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		table->philo[i].table = table;
		pthread_create(&table->philo[i].thread, NULL,
			ft_loop, &table->philo[i]);
		i++;
	}
	ft_death(table);
	i = 0;
	while (i < table->total_philos && table->is_dead == 0)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
	return (1);
}
