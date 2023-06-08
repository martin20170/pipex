/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_c_by_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:07:15 by mphilip           #+#    #+#             */
/*   Updated: 2023/04/10 21:04:43 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

void	ft_fill_c_by_c(char *str, int nb_of_c, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, nb_of_c);
	while (i < nb_of_c)
	{
		str[i] = va_arg(args, int);
		i++;
	}
	va_end(args);
}
