/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:20:29 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/12 18:58:25 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

void	ft_take_a_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->write_mutex);
	ft_show_condition(philo, "Has taken fork\n");
	pthread_mutex_unlock(&philo->args->write_mutex);
}

void	ft_show_condition(t_philo *philo, char *condition)
{
	uint64_t time;

	time = ft_get_time(0) - philo->args->start_time;
	if (time >= 0 && time <= MAX_INT)
	{
		printf("[%llu] Philo [%d] %s", time, philo->index, condition);
	}
}

void	*ft_loop(void *values)
{
	t_philo	*philo;

	philo = (t_philo *)values;
	if (philo->index % 2 == 0)
		ft_usleep(philo->args->time_2_eat);

	while (1)
	{
		ft_eat(philo);
		/*
			mutex lock write
			Imprimir mensaje de dormir
			mutex unlock write
			esperar tiempo que tarda en dormir [paramatro sleep]
		*/

		/*
			mutex lock write
			Imprimir mensaje de pensando
			mutex unlock write
		*/
	}

	return (0);
}

int	ft_create_threads(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->args.total_philos)
	{
		global->philo[i].args = &global->args;
		pthread_create(&global->philo[i].thread, NULL, ft_loop, &global->philo[i]);
		i++;
	}
	i = 0;
	while (i < global->args.total_philos)
	{
		pthread_join(global->philo[i].thread, NULL);
		i++;
	}
	return (1);
}
