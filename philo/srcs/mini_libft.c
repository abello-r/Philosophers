/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:21:20 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/21 00:56:22 by abello-r         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ' )
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = (unsigned int)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, n, 0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[x] != '\0')
		x++;
	if (x != i)
		return (1);
	i = -1;
	while (s1[++i] != '\0')
		if (s1[i] != s2[i])
			return (1);
	return (0);
}
