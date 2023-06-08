/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:43:34 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/04 00:15:38 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	start_id(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (is_in_set(s1[i], set) == 1 && s1[i])
		i++;
	return (i);
}

static int	end_id(char const *s1, char const *set)
{
	int		i;
	int		s1_len;

	s1_len = ft_strlen((char *)s1);
	i = s1_len - 1;
	if (i >= 0)
	{
		while (is_in_set(s1[i], set) == 1 && i >= 0)
			i--;
	}
	return (++i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = start_id(s1, set);
	end = end_id(s1, set);
	if (start == (int)ft_strlen((char *)s1))
	{
		start = 0;
		end = 0;
	}
	result = malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	while (i < (end - start))
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
