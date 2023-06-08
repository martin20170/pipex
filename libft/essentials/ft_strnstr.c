/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:33:37 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/04 00:15:38 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

char	*ft_strnstr(const char	*haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	needle_len;

	i = 0;
	needle_len = ft_strlen((char *)needle);
	if (*haystack == 0 && *needle == 0)
		return ((char *)haystack);
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack && i < (unsigned int)len)
	{
		j = 0;
		while (*(haystack + j) == needle[j] && (i + j) < (unsigned int)len && \
			*(haystack + j) && needle[j])
			j++;
		if (j == needle_len)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
