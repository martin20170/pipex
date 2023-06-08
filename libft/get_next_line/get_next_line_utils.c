/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:39:44 by mphilip           #+#    #+#             */
/*   Updated: 2023/01/13 13:01:30 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*null_str(int size)
{
	char	*result;

	result = malloc(size + 1);
	if (!result)
		return (NULL);
	ft_bzero(result, size + 1);
	return (result);
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

char	*strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == (char)c)
			return (&ptr[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&ptr[i]);
	return (NULL);
}

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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	if (src_ptr == dest_ptr || n == 0)
		return (dest);
	if (src < dest)
	{
		while (n > 0)
		{
			dest_ptr[n - 1] = src_ptr[n - 1];
			n--;
		}
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, n));
}
