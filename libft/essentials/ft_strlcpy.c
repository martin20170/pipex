/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:48:05 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/04 00:15:38 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			len;
	unsigned int	size_conv;

	len = 0;
	size_conv = size;
	if (size_conv <= 0)
		return ((size_t)ft_strlen((char *)src));
	while (len < size - 1 && src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return ((size_t)ft_strlen((char *)src));
}
