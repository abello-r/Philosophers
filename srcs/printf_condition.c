/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_condition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 02:16:22 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/20 17:40:15 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

int ft_msg(t_philo *philo, char status)
{
    if (philo->table->is_dead == 1)
        return (1);

    pthread_mutex_lock(&philo->table->write_mutex);
    if (status == 'd')
    {
        ft_usleep(philo->table->time_2_die);
    	printf(RED "[%llu ms]\t[Philo %d] Died\n" RESET, ft_get_time(philo->table->start_time), philo->index);
   
    if (status == 'e')
         
   
    if (status == 's')
         
   
    if (status == 't')
         
   
    if (status == 'f')
         
    }
    pthread_mutex_unlock(&philo->table->write_mutex);
    return (0);
}
