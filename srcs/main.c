/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:55:56 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/12 19:04:39 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platon.h"

static int	ft_no_philo(char **argv)
{
	int	value;

	value = ft_atoi(argv[1]);
	if (value == 0)
	{
		write(1, RED NARG, (sizeof(NARG) + sizeof(RED) - 2));
		return (-1);
	}
	else if (value > 200)
	{
		write(1, RED MARG, (sizeof(MARG) + sizeof(RED) - 2));
		return (-1);
	}
	return (0);
}

static int	ft_parse(int argc, char **argv)
{
	int	i;
	int	x;

	x = argc;
	while (--argc > 0)
	{
		i = -1;
		while (argv[argc][++i] != '\0')
			if (!ft_isdigit(argv[argc][i]))
				return (-1);
	}
	if (ft_no_philo(argv) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_global	global;

// Parse finish --------------------------------------

	if (argc < 5 || argc > 6)
	{
		write(1, RED LARG, (sizeof(LARG) + sizeof(RED) - 2));
		return (-1);
	}
	else if (argc == 5 || argc == 6)
		if (ft_parse(argc, argv) == -1)
			return (-1);

	ft_fill_struct(argc, argv, &global);

// Create struct x philo-------------------------------

	global.philo = malloc(sizeof(t_global) * ft_atoi(argv[1]));

	if (!global.philo)
		return (1);

	ft_init_struct(&global);
	ft_create_threads(&global);

	return (0);
}
