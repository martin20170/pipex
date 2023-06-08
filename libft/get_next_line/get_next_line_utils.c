/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:39:44 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/08 20:17:43 by mphilip          ###   ########.fr       */
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
