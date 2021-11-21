/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_condition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 02:16:22 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/21 01:03:55 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

int	ft_msg(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->table->write_mutex);
	if (philo->table->is_dead == 1)
		return (1);
	if (ft_strcmp("dead", status) == 0)
		printf(RED "[%llu ms]\t\t[Philo %d] Died\n" RESET,
			ft_get_time(philo->table->start_time), philo->index);
	else if (ft_strcmp("eat", status) == 0)
		printf(BLUE "[%llu ms]\t\t[Philo %d] Is eating\n" RESET,
			ft_get_time(philo->table->start_time), philo->index);
	else if (ft_strcmp("fork", status) == 0)
		printf(GREEN "[%llu ms]\t\t[Philo %d] Has taken fork\n" RESET,
			ft_get_time(philo->table->start_time), philo->index);
	else if (ft_strcmp("think", status) == 0)
		printf(MAGN "[%llu ms]\t\t[Philo %d] Is thinking\n" RESET,
			ft_get_time(philo->table->start_time), philo->index);
	else if (ft_strcmp("sleep", status) == 0)
		printf(YELLOW "[%llu ms]\t\t[Philo %d] Is sleeping\n" RESET,
			ft_get_time(philo->table->start_time), philo->index);
	pthread_mutex_unlock(&philo->table->write_mutex);
	return (0);
}
