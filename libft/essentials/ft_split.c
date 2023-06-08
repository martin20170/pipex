/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:15:35 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/04 00:15:38 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

static int	array_size(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			size++;
			while (*s != c && *s)
				s++;
		}
	}
	return (size);
}

static int	id_in_s(int i, char const *s, char c)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (s[j] == c)
		j++;
	while (count < i)
	{
		while (s[j] == c && s[j])
			j++;
		while (s[j] != c && s[j])
			j++;
		while (s[j] == c && s[j])
			j++;
		count++;
	}
	return (j);
}

static int	strlen_modd(int i, char const *s, char c)
{
	int	j;
	int	len;

	j = id_in_s(i, s, c);
	len = 0;
	while (s[j] != c && s[j])
	{
		len++;
		j++;
	}
	return (len);
}

static char	*fill_array(int i, char const *s, char c)
{
	char	*word;
	int		len;
	int		j;
	int		k;

	len = strlen_modd(i, s, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	k = id_in_s(i, s, c);
	while (j < len)
	{
		word[j] = s[k];
		j++;
		k++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = -1;
	result = malloc(sizeof(char *) * (array_size(s, c) + 1));
	if (!result)
		return (NULL);
	while (i < array_size(s, c))
	{
		result[i] = fill_array(i, s, c);
		if (!result[i])
		{
			while (++j < i)
				free(result[j]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
