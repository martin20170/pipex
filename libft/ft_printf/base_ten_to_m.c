/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_ten_to_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:08:18 by mphilip           #+#    #+#             */
/*   Updated: 2022/12/05 13:21:59 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	rec_div(unsigned long long nbr, unsigned long divis, int r)
{
	if (r == 0)
		return (nbr % divis);
	return (rec_div(nbr / divis, divis, r - 1));
}

char	*base_ten_to_m(unsigned long long nbr, char *bs, int s)
{
	int					i;
	int					c;
	unsigned long long	div;
	char				*res;

	i = 0;
	c = 1;
	if (nbr == 0)
		c = 2;
	div = nbr;
	while (div != 0)
	{
		div /= (long)ft_strlen(bs);
		c++;
	}
	res = malloc(sizeof(char) * (c + 1 + s));
	if (!res)
		return ((void *)0);
	while (--c > 0)
	{
		res[i + s] = bs[rec_div(nbr, (unsigned long)ft_strlen(bs), c - 1)];
		i++;
	}
	res[i + s] = '\0';
	return (res);
}
