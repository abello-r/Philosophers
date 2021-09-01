/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 18:09:55 by abello-r          #+#    #+#             */
/*   Updated: 2021/09/01 19:30:15 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	write(1, RED PARSE, (sizeof(PARSE) + sizeof(RED) - 2));
	return (0);
}

void	ft_fill_structs(t_pa **pa, int argc, char **argv)
{
	int	i;
	int total_philo;

	total_philo = ft_atoi(argv[1]);
	i = -1;
	while (++i < total_philo)
	{
		pa[i] = malloc(sizeof(t_pa));
		ft_bzero(pa[i], sizeof(t_pa));
		pa[i]->philo_num = ft_atoi(argv[1]);
		pa[i]->t_2_die = ((uint64_t)ft_atoi(argv[2]));
		pa[i]->t_2_eat = ((uint64_t)ft_atoi(argv[3]));
		pa[i]->t_2_sleep = ((uint64_t)ft_atoi(argv[4]));
		if (argc == 6)
		{
			pa[i]->eat_flag = true;
			pa[i]->c_2_eat = ft_atoi(argv[5]);
		}
	}
}

/*static void	*ft_first_action(void *build)
{
	t_pa	*pa;
	pa = (t_pa *)build;

	printf("soy el philo [%d]\n", pa->index);

	return (NULL);
}

int	ft_thread_x_philo(t_pa *pa)
{
	int	platones = pa->philo_num;

	pa->philo = malloc(sizeof(pthread_t));
	if (!pa->philo)
		return (1);

	while (platones > 0)
	{
		pa->index = platones;
		pthread_create(pa->philo, NULL, ft_first_action, (void *)pa);
		platones--;
	}
	pthread_join(*pa->philo, NULL);

	return (0);
}
*/