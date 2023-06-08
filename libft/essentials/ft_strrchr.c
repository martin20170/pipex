/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:27:18 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/04 00:15:38 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*memo;

	memo = ((void *)0);
	while (*s)
	{
		if ((int)*s == (char)c)
			memo = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (memo);
}
