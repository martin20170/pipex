/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:12:50 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/04 00:15:38 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

static int	final_size(int n)
{
	int	size;
	int	nbr;

	size = 0;
	nbr = n;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

static char	*min_int(void)
{
	char	*result;
	char	*val;

	val = "-2147483648";
	result = ft_strdup(val);
	return (result);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	int		size;
	char	*result;

	size = final_size(n);
	sign = 1;
	if (n == -2147483648)
		return (min_int());
	if (n < 0)
		sign = -1;
	result = malloc(size + ((sign - 1) / (-2)) + 1);
	if (!result)
		return ((void *)0);
	i = size + ((sign - 1) / (-2)) - 1;
	while (i >= 0)
	{
		result[i] = ((n * sign) % 10) + 48;
		n /= 10;
		i--;
	}
	result[size + ((sign - 1) / (-2))] = '\0';
	if (sign == -1)
		result[0] = '-';
	return (result);
}
