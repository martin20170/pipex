/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_options_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:33:11 by mphilip           #+#    #+#             */
/*   Updated: 2023/02/27 16:04:41 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_option(unsigned int nb)
{
	char			mod;
	char			a;
	unsigned int	div;
	int				result;

	div = nb;
	if (nb == 0)
		result = 1;
	else
	{
		result = 0;
		while (div != 0)
		{
			result++;
			div /= 10;
		}
	}
	if ((int)nb < 0)
		nb = 4294967295;
	mod = nb % 10;
	if (nb > 9)
		u_option(nb / 10);
	a = '0' + mod;
	write(1, &a, 1);
	return (result);
}

int	x_x_option(char c, long nb)
{
	char	*str;
	int		len;

	if (nb < 0)
		nb = 4294967295 + nb + 1;
	if (c == 'x')
	{
		str = base_ten_to_m(nb, "0123456789abcdef", 0);
		ft_putstr_fd(str, 1);
		len = (int)ft_strlen(str);
		free(str);
		return (len);
	}
	else
	{
		str = base_ten_to_m(nb, "0123456789ABCDEF", 0);
		ft_putstr_fd(str, 1);
		len = (int)ft_strlen(str);
		free(str);
		return (len);
	}
}
