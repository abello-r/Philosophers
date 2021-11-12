/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:08:19 by abello-r          #+#    #+#             */
/*   Updated: 2021/10/31 17:44:31 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

int     ft_cest_la_mort(t_philo *philo, int status)
{
    pthread_mutex_lock(&philo->args->dead_mutex);
    if (status)
        philo->args->stop = status;
    if (philo->args->stop)
    {
        pthread_mutex_unlock(&philo->args->dead_mutex);
        return (1);
    }
    pthread_mutex_unlock(&philo->args->dead_mutex);
    return (0);
}

void *ft_philo_dead(void *values)
{
    t_philo     *philo;

    philo = (t_philo *)values;
    pthread_mutex_lock(&philo->args->t_eat_mutex);
    pthread_mutex_lock(&philo->args->end_mutex);

    if (!ft_cest_la_mort(philo, 0))
    {
        
    }


    return (NULL);
}