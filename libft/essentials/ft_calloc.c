/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:13:42 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/04 00:15:38 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		total;
	int		i;

	total = nmemb * size;
	i = 0;
	ptr = (char *)malloc(total);
	if (!ptr)
		return (NULL);
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
