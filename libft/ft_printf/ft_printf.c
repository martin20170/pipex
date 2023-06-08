/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:04:15 by mphilip           #+#    #+#             */
/*   Updated: 2022/12/14 13:02:42 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_after_percent(char c)
{
	if (c == 0 || ft_strrchr("cspdiuxX%", c) == 0)
	{
		write(1, "\nerror: incomplete format specifier\n", 36);
		return (0);
	}
	return (1);
}

int	putchar_pp(char c, int result)
{
	ft_putchar_fd(c, 1);
	return (++result);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	args;
	char	*ptr;

	ptr = (char *)format;
	result = 0;
	if (write(1, 0, 0))
		return (-1);
	va_start(args, format);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (check_after_percent(*ptr) == 0)
				return (result);
			result += option(*ptr, args);
		}
		else
			result = putchar_pp(*ptr, result);
		ptr++;
	}
	va_end(args);
	return (result);
}
