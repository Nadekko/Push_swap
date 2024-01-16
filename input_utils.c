/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:07:13 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/01 16:54:07 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	is_nbr(char *av)
{
	int	i;

	i = 0;
	if ((av[0] == '+' || av[0] == '-') && av[1] != '\0')
		i++;
	while (av[i])
	{
		if (!is_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	nbr;
	int		neg;

	nbr = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	return (neg * nbr);
}

int	error_repeat(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
