/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:27:47 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/10 15:28:12 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*name_with_slash(char *str)
{
	char	*result;

	result = ft_strjoin("/", str);
	if (!result)
		return (NULL);
	return (result);
}

char	**get_cmd_path(char **path, char *cmd_name)
{
	char	**result;
	char	*temp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (path[len])
		len++;
	result = malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		temp = name_with_slash(cmd_name);
		if (!temp)
			return (free_strlst(result), NULL);
		result[i] = ft_strjoin(path[i], temp);
		if (!result)
			return (free(temp), free_strlst(result), NULL);
		i++;
	}
	result[i] = NULL;
	return (result);
}
