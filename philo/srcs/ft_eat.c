/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:08:21 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/21 00:15:16 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

void	ft_eat(t_philo *philo)
{
	unsigned int	right_index;

	right_index = philo->index; 

	if (right_index == (unsigned int)philo->table->total_philos)
		right_index = 0;

	pthread_mutex_lock(&philo->own_fork);
	ft_msg(philo, "fork");

	if (philo->table->total_philos == 1)
	{
		// TODO: Error cuando time_2_die es alto
		ft_usleep(philo->table->time_2_die);
		ft_msg(philo, "dead");
		philo->table->is_dead = 1;
	}

	pthread_mutex_lock(&philo->table->philo[right_index].own_fork);
	ft_msg(philo, "fork");

	philo->last_eat = ft_get_time(philo->table->start_time);
	philo->counter_eat += 1;
	ft_msg(philo, "eat");
	ft_usleep(philo->table->time_2_eat);

	pthread_mutex_unlock(&philo->own_fork);
	pthread_mutex_unlock(&philo->table->philo[right_index].own_fork);

	/******************************************************************/
	/**	1- Controlar el right philo,									 **/
	/**	2- Comprobar si solo es 1 philo, [Debe morir]  					 **/
	/**	3- Escribir que tengo los dos tenedores,						 **/
	/**	4- Mutex lock del tenedor propio [1],							 **/
	/**	5- mutex lock del tenedor de la derecha [2],					 **/
	/**	6- Imprimir que he comido [tiempo recibido por parametro],		 **/
	/**	7- Esperar por el tiempo de [Time_to_eat],						 **/
	/**	8- han terminado de comer? soltar tenedores.					 **/
	/******************************************************************/
}
