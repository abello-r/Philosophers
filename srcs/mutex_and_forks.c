/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_and_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:03:15 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/12 19:00:25 by abello-r         ###   ########.fr       */
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

void	ft_eat(t_philo *philo)
{
	unsigned int right_index;

	if (philo->args->meteorite)
		return ;

	right_index = philo->index;

	if (right_index == (unsigned int)philo->args->total_philos)
		right_index = 0;

	pthread_mutex_lock(&philo->args->write_mutex);
	printf("[%d ms]\t\t[Philo %d] Has taken fork\n", 0, philo->index);
	pthread_mutex_unlock(&philo->args->write_mutex);

	pthread_mutex_lock(&philo->own_fork);
	pthread_mutex_lock(&philo[right_index + 1].own_fork);

	pthread_mutex_lock(&philo->args->write_mutex);
	printf("[%d ms]\t[Philo %d] Is eating\n", philo->args->time_2_eat, philo->index);
	pthread_mutex_unlock(&philo->args->write_mutex);
	ft_usleep(philo->args->time_2_eat);

	pthread_mutex_unlock(&philo->own_fork);
	pthread_mutex_unlock(&philo[right_index + 1].own_fork);

	/*
	Mutex lock del tenedor propio
	mutex lock del tenedor de la derecha [1]
	Imprimir que he comido [tiempo recibido por parametro]
	han terminado de comer? soltar tenedores.
	*/

}
