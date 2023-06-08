/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:16:33 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/04 00:15:38 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	i;

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	i = 0;
	if (dest_ptr == NULL && src_ptr == NULL)
		return (dest);
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
