/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:17:04 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/04 00:15:38 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	init_destsize;

	i = 0;
	j = 0;
	init_destsize = ft_strlen(dst);
	if (!dst || !dstsize)
		return (ft_strlen((char *)src));
	while (dst[i] && i < dstsize)
		i++;
	if (i == dstsize)
		return (dstsize + ft_strlen((char *)src));
	while (i < dstsize - 1 && src[j] && dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (init_destsize + ft_strlen((char *)src));
}
