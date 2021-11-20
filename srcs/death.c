/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:34:29 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/20 17:37:35 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

void    ft_death(t_table *table)
{
	int i;
	int last_eat_time;

	while (1)
	{
		i = 0;
		while (i < table->total_philos)
		{
			last_eat_time = (ft_get_time(table->start_time) - table->philo[i].last_eat);
			if (last_eat_time >= table->time_2_die)
			{
				pthread_mutex_lock(&table->write_mutex);
				printf(RED "[%d]\t\t[Philo %d] Died\n" RESET, table->time_2_die, table->philo->index);
				pthread_mutex_unlock(&table->write_mutex);
				table->is_dead = 1;
				break ;
			}
			i++;
		}
		if (table->is_dead == 1)
			break ;
		usleep(100);
	}
}

/*************************************************************************************************************/
/** 1 -		Iterar sobre los filosofos																		**/
/** 1.1 -	Ver cuando fue la ultima vez que comieron														**/
/** 1.2 -	comprobar si es mayor al tiempo de muerte														**/
/** 1.3 -	[Activar variable de la estructura en la tabla "muerte"]										**/
/**																											**/
/** 2 - 	Ver sí todos han comido la cantidad de veces quie deberían comer [Contador en cada philo]		**/
/** 2.2 -	Si no han comido todas las veces necesarias, activar flag de muerte en la tabla					**/
/**																											**/
/** 3 -		Optimizar usando usleep(100)																	**/
/*************************************************************************************************************/
