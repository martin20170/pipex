/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:23:37 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/10 15:43:10 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_loop(char **cmd_path, char **cmd)
{
	int		i;

	i = 0;
	while (cmd_path[i])
	{
		execve(cmd_path[i], cmd, NULL);
		i++;
	}
	return (-1);
}

void	cmd1_process(t_cmds_p params, char **path, char **inout, char ***cmds)
{
	char	**cmd1_path;

	cmd1_path = get_cmd_path(path, cmds[0][0]);
	if (!cmd1_path)
		free_process(path, inout, cmds, 0);
	close(params.fd[0]);
	params.cmd1_p = fork();
	if (params.cmd1_p == 0)
	{
		cmd1_fd_switch(inout, params.fd);
		if (exec_loop(cmd1_path, cmds[0]) == -1)
			free_process(path, inout, cmds, 0);
	}
	else
	{
		cmd1_check(cmd1_path, params, cmds);
		close(params.fd[1]);
		while (wait(NULL) != -1 || errno != ECHILD);
	}
}

void	cmd2_process(t_cmds_p params, char **path, char **inout, char ***cmds)
{
	char	**cmd2_path;

	cmd2_path = get_cmd_path(path, cmds[1][0]);
	if (!cmd2_path)
		free_process(path, inout, cmds, 0);
	close(params.fd[1]);
	params.cmd2_p = fork();
	if (params.cmd2_p == 0)
	{
		cmd2_fd_switch(inout, params.fd);
		if (exec_loop(cmd2_path, cmds[1]) == -1)
			free_process(path, inout, cmds, 0);
	}
	else
	{
		cmd2_check(cmd2_path, params, cmds);
		close(params.fd[1]);
		while (wait(NULL) != -1 || errno != ECHILD);
	}
}

void	cmds_process(char **path, char **inout, char ***cmds)
{
	t_cmds_p	cmds_params;
	pid_t		cmds_p;

	cmds_params.cmd1_status = 0;
	cmds_params.cmd2_status = 0;
	pipe(cmds_params.fd);
	cmds_p = fork();
	if (cmds_p == 0)
		cmd1_process(cmds_params, path, inout, cmds);
	else
		cmd2_process(cmds_params, path, inout, cmds);
}
