/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_options_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:32:45 by mphilip           #+#    #+#             */
/*   Updated: 2022/12/14 12:53:13 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	option(char c, va_list args)
{
	int	result;

	if (c == 'c')
		result = c_option(va_arg(args, int));
	if (c == 's')
		result = s_option(va_arg(args, char *));
	if (c == 'p')
		result = p_option(va_arg(args, void *));
	if (c == 'd' || c == 'i')
		result = d_i_option(va_arg(args, int));
	if (c == 'u')
		result = u_option(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		result = x_x_option(c, va_arg(args, int));
	if (c == '%')
		result = (int)write(1, "%", 1);
	return (result);
}

int	c_option(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	s_option(char *str)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		return ((int)ft_strlen(str));
	}
	write(1, "(null)", 6);
	return (6);
}

int	p_option(void *ptr)
{
	char	*value;
	int		len;
	char	*hex;

	hex = ft_strdup("0123456789abcdef");
	write(1, "0x", 2);
	if ((long long)ptr >= 0 || (long long)ptr == LONG_MIN || \
		(unsigned long long)ptr >= LONG_MAX)
	{
		value = base_ten_to_m((unsigned long)ptr, hex, 0);
		len = (int)ft_strlen(value) + 2;
	}
	else
	{
		write(1, "ffffffff", 8);
		value = base_ten_to_m(ULONG_MAX + (unsigned long)ptr + 1, hex, 0);
		len = (int)ft_strlen(value) + 10;
	}
	ft_putstr_fd(value, 1);
	free(value);
	free(hex);
	return (len);
}

int	d_i_option(int nb)
{
	int	div;
	int	result;

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
	ft_putnbr_fd(nb, 1);
	if (nb < 0)
		return (++result);
	return (result);
}
