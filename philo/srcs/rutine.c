/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:20:29 by abello-r          #+#    #+#             */
/*   Updated: 2021/10/15 16:20:32 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

void	ft_take_a_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->args->write_mutex);
	ft_show_condition(philo, "Has taken fork\n");
	pthread_mutex_unlock(&philo->args->write_mutex);
}

void	ft_show_condition(t_philo *philo, char *condition)
{
	uint64_t time;

	time = ft_get_time(0) - philo->args->start_time;
	if (!supervisor(philo, 0))
	{
		printf("No sirve");
		printf("[%llu] Philo [%d] %s", time, philo->index, condition);
	}
}

int	supervisor(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->args->dead_mutex);
	if (status != 0)
		philo->args->stop = status;
	if (philo->args->stop != 0)
	{
		pthread_mutex_unlock(&philo->args->dead_mutex);
		return (1);
	}
	return (0);
}

void	*ft_loop(void *values)
{
	t_philo	*philo;

	philo = (t_philo *)values;
	if (philo->index % 2 == 0)
		ft_usleep(philo->args->time_2_eat);
	while (!supervisor(philo, 0))
	{
		ft_take_a_fork(philo);
	


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
		pthread_create(&global->philo[i].thread, 
			NULL, ft_loop, &global->philo[i]);
		i++;
	}
	return (1);
}




/*

// Show the state of philo.

void	ft_display_state(t_pa *pa, char *state, uint64_t reference)
{
	pthread_mutex_lock(pa->child->mutex);
	printf("[%llu ms] Philo %d %s\n", ft_get_time(0) - reference, pa->index, state);
	pthread_mutex_unlock(pa->child->mutex);
}

// --------------------------------------------------------------------------------------- 	end.

int	ft_go_to_fly(t_pa *pa)
{
	uint64_t	reference;

	reference = ft_get_time(0);
	if (pa->t_2_die < pa->t_2_eat || pa->t_2_die == pa->t_2_eat)
	{
		ft_usleep(pa->t_2_die);
		ft_display_state(pa, "Died ☄️", reference);
		exit (0);
	}
	return (0);
}

int	ft_go_to_eat(t_pa *pa)
{  
	uint64_t reference;

	ft_usleep(pa->t_2_eat);
	pthread_mutex_lock(&pa->child->mutex[pa->index]);
	reference = ft_get_time(0);
	reference -= pa->child->t_start;
	ft_display_state(pa, "Is eating 🥩", pa->child->t_start);
	pthread_mutex_unlock(&pa->child->mutex[pa->index]);
	return (0);
}

int	ft_rutine(t_pa *pa)
{
	uint64_t reference;
	int		i_r;

	i_r = pa->index;
	
	if (i_r == pa->philo_num)
		i_r = 0;
	reference = ft_get_time(0);
	
	if (pa->t_2_die < pa->t_2_eat || pa->t_2_die == pa->t_2_eat)
	{
		ft_go_to_fly(pa);
		return (0);
	}

	if (pa->philo_num > 1)
	{
		pthread_mutex_lock(pa->child->philos[i_r].right_mut);
		reference = ft_get_time(0);
		ft_display_state(pa, "Has taken a fork 🦖", reference);

		pthread_mutex_lock(pa->right_mut);
		reference = ft_get_time(0);
		ft_display_state(pa, "Has taken a fork 🦖", reference);

		ft_go_to_eat(pa);
	
		pthread_mutex_unlock(pa->child->philos[i_r].right_mut);
		pthread_mutex_unlock(pa->right_mut);
	}


	//ft_go_to_sleep(pa);
	//ft_go_to_think(pa);
	return (0);
}
	
*/