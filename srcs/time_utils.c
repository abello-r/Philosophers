/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:24:15 by abello-r          #+#    #+#             */
/*   Updated: 2021/10/11 18:38:41 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

void	ft_usleep(uint64_t time_in_ms)
{
	uint64_t			start_time;

	start_time = ft_get_time(0);
	while ((ft_get_time(0) - start_time) < time_in_ms)
		usleep(1);
}

uint64_t	ft_get_time(uint64_t reference)
{
	struct	timeval ti;

	if (gettimeofday(&ti, NULL) == -1)
		return (-1);
	return(ti.tv_sec * 1000 + ti.tv_usec / 1000 - reference);
}
