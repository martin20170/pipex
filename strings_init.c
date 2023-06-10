/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:16:07 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/10 15:17:28 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_in_and_out(char **input)
{
	char	**result;

	result = malloc(sizeof(char *) * 3);
	if (!result)
		error_state();
	result[0] = input[1];
	result[1] = input[4];
	result[2] = NULL;
	return (result);
}

char	**get_path(char **envp)
{
	int		i;
	char	**var;
	char	**result;

	i = 0;
	while (envp[i])
	{
		var = ft_split(envp[i], '=');
		if (ft_memcmp(var[0], "PATH\0", 5) == 0)
		{
			result = ft_split(var[1], ':');
			if (!result)
				return (free_strlst(var), NULL);

			return (free_strlst(var), result);
		}
		free_strlst(var);
		i++;
	}
	return (NULL);
}

char	***get_cmds(char **input)
{
	char	***result;

	result = malloc(sizeof(char **) * 3);
	if (!result)
		error_state();
	result[0] = ft_split(input[2], ' ');
	if (!result[0])
		error_state();
	result[1] = ft_split(input[3], ' ');
	if (!result[1])
		error_state();
	result[2] = NULL;
	return (result);
}

int	strings_init(char ***in_n_out_ad, char ***path_ad, char ****cmds_ad, t_args args)
{
	*in_n_out_ad = get_in_and_out(args.argv);
	if (!(*in_n_out_ad))
		return (0);
	*path_ad = get_path(args.envp);
	if (!path_ad)
		return (free_strlst(*in_n_out_ad), 0);
	*cmds_ad = get_cmds(args.argv);
	if (!(*cmds_ad))
		return (free_strlst(*in_n_out_ad), free_strlst(*path_ad), 0);
	return (1);
}
