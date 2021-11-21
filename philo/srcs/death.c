/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:34:29 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/21 00:55:09 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

void	ft_death(t_table *table)
{
	int	i;
	int	time;

	while (1)
	{
		i = 0;
		while (i < table->total_philos)
		{
			time = (ft_get_time(table->start_time) - table->philo[i].last_eat);
			if (time >= table->time_2_die)
			{
				ft_msg(table->philo, "dead");
				table->is_dead = 1;
				break ;
			}
			i++;
		}
		if (table->is_dead == 1 || table->each_philo_eat == 1)
			break ;
		usleep(100);
	}
}
