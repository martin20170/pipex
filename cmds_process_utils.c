/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_process_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:26:22 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/10 15:42:53 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd1_fd_switch(char **inout, int *fd)
{
	int	infile;

	infile = open(inout[0], O_RDONLY);
	if (infile == -1)
		exit(0);
	if (dup2(infile, STDIN_FILENO) == -1)
		exit(0);
	close(infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit(0);
}

void	cmd2_fd_switch(char **inout, int *fd)
{
	int	outfile;

	outfile = open(inout[1], O_WRONLY | O_CREAT, 0777);
	if (outfile == -1)
		exit(0);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		exit(0);
	close(outfile);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit(0);
}

void	cmd1_check(char **cmd1_path, t_cmds_p params, char ***cmds)
{
	if (waitpid(params.cmd1_p, &(params.cmd1_status), 0) == -1)
		exit(EXIT_FAILURE);
	if (WEXITSTATUS(params.cmd1_status) == EXIT_FAILURE)
		ft_printf("command not found : %s\n", cmds[0][0]);
	free_strlst(cmd1_path);
}

void	cmd2_check(char **cmd2_path, t_cmds_p params, char ***cmds)
{
	if (waitpid(params.cmd2_p, &(params.cmd2_status), 0) == -1)
		exit(EXIT_FAILURE);
	if (WEXITSTATUS(params.cmd2_status) == EXIT_FAILURE)
		ft_printf("command not found : %s\n", cmds[1][0]);
	free_strlst(cmd2_path);
}
