/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:20:16 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/10 15:42:53 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*error_state(void)
{
	ft_printf("An error occured!\n");
	return (NULL);
}

void	free_cmds(char ***cmds)
{
	int	i;
	int	j;

	i = 0;
	while (cmds[i])
	{
		j = 0;
		while (cmds[i][j])
		{
			free(cmds[i][j]);
			j++;
		}
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

void	free_strlst(char **var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		free(var[i]);
		i++;
	}
	free(var);
}

void	free_process(char **path, char **inout, char ***cmds, int endmain)
{
	if (endmain == 1)
		while (wait(NULL) != -1 || errno != ECHILD);
	free(inout);
	free_cmds(cmds);
	free_strlst(path);
	if (endmain != 1)
		exit(EXIT_FAILURE);
}
