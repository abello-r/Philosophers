/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_and_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:03:15 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/12 19:24:40 by abello-r         ###   ########.fr       */
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

