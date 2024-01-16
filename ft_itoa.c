/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:37:59 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/15 13:45:45 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

static int	ft_count(long n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		digit++;
	}
	while (n)
	{
		n /= 10;
		digit++;
	}
	return ((int)digit);
}

char	*ft_itoa(int n)
{
	int		d_count;
	long	nb;
	char	*rst;

	nb = n;
	d_count = ft_count(n);
	rst = (char *)malloc(d_count + 1);
	if (!rst)
		return (NULL);
	rst[d_count] = '\0';
	if (nb < 0)
	{
		rst[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		rst[0] = '0';
	while (nb)
	{
		rst[--d_count] = 48 + (nb % 10);
		nb /= 10;
	}
	return (rst);
}
