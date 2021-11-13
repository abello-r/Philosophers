/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:08:21 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/13 10:50:29 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

void	ft_take_a_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->write_mutex); // Bloquear mutex escritura
	printf(GREEN "[%llu ms]\t\t[Philo %d] Has taken fork\n" RESET, ft_get_time(philo->args->start_time), philo->index); // Escribir que tiene [1] tenedor y restar el tiempo inicial con el actual.
	printf(GREEN "[%llu ms]\t\t[Philo %d] Has taken fork\n" RESET, ft_get_time(philo->args->start_time), philo->index); // Escribir que tiene [2] tenedores y restar el tiempo inicial con el actual.
	pthread_mutex_unlock(&philo->args->write_mutex); // Desbloquear mutex escritura
}

void	ft_eat(t_philo *philo)
{
	unsigned int	right_index; // Auxiliar philo index

	right_index = philo->index; // Valor por defecto

	if (right_index == (unsigned int)philo->args->total_philos) // Sí ha llegado al último philo, el de la "derecha" será el '0' 
		right_index = 0;

	ft_take_a_fork(philo); // [Imprime que ha cogido los tenedores]

	pthread_mutex_lock(&philo->own_fork); // Bloquear mi tenedor [1]
	pthread_mutex_lock(&philo[right_index + 1].own_fork); // Bloquear tenedor del de la derecha [2]

	pthread_mutex_lock(&philo->args->write_mutex); // Bloquear mutex de escribir
	printf(BLUE "[%llu ms]\t[Philo %d] Is eating\n" RESET, ft_get_time(philo->args->start_time), philo->index); // Decir que el philo ha comido
	pthread_mutex_unlock(&philo->args->write_mutex); // Desbloquear mutex escribir
	
	ft_usleep(philo->args->time_2_eat); // Esperar el tiempo que dura comiendo [T_2_EAT]

	pthread_mutex_unlock(&philo->own_fork); // Desbloquear tenedor [1]
	pthread_mutex_unlock(&philo[right_index + 1].own_fork); // Desbloquear tenedor [2]

	/*
	Revisar si alguno ha muerto,
	Controlar el right philo,
	Escribir que tengo los dos tenedores„
	Mutex lock del tenedor propio [1],
	mutex lock del tenedor de la derecha [2],
	Imprimir que he comido [tiempo recibido por parametro],
	Esperar por el tiempo de [Time_to_eat],
	han terminado de comer? soltar tenedores.
	*/
}
