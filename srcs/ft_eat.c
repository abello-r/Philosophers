/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:08:21 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/20 17:12:37 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

void	ft_take_a_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write_mutex); // Bloquear mutex escritura
	printf(GREEN "[%llu ms]\t\t[Philo %d] Has taken fork\n" RESET, ft_get_time(philo->table->start_time), philo->index); // Escribir que tiene [1] tenedor y restar el tiempo inicial con el actual.
	pthread_mutex_unlock(&philo->table->write_mutex); // Desbloquear mutex escritura
}

void	ft_eat(t_philo *philo)
{
	unsigned int	right_index; // Auxiliar philo index

	right_index = philo->index; // Valor por defecto

	if (right_index == (unsigned int)philo->table->total_philos) // Sí ha llegado al último philo, el de la "derecha" será el '0' 
		right_index = 0;

	pthread_mutex_lock(&philo->own_fork); // Bloquear mi tenedor [1]
	ft_take_a_fork(philo); // [Imprime que ha cogido 1 tenedor]

	if (philo->table->total_philos == 1) // No puede coger 2 tenedores
	{
		philo->table->is_dead = 1; // Muere
	}

	pthread_mutex_lock(&philo->table->philo[right_index].own_fork); // Bloquear tenedor del de la derecha [2]
	ft_take_a_fork(philo); // [Imprime que ha cogido 2 tenedores]
	philo->last_eat = ft_get_time(philo->table->start_time);

	pthread_mutex_lock(&philo->table->write_mutex); // Bloquear mutex de escribir
	printf(BLUE "[%llu ms]\t[Philo %d] Is eating\n" RESET, ft_get_time(philo->table->start_time), philo->index); // Decir que el philo ha comido
	pthread_mutex_unlock(&philo->table->write_mutex); // Desbloquear mutex escribir

	ft_usleep(philo->table->time_2_eat); // Esperar el tiempo que dura comiendo [T_2_EAT]

	pthread_mutex_unlock(&philo->own_fork); // Desbloquear tenedor [1]
	pthread_mutex_unlock(&philo->table->philo[right_index].own_fork); // Desbloquear tenedor [2]

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
