/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:59:46 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/12 14:46:53 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	main_p;
	t_args	args;
	char	**inout;
	char	***cmds;
	char	**path;

	args.argv = argv;
	args.envp = envp;
	args.main_status = 0;
	if (argc != 5)
		error_state();
	if (str_init(&inout, &path, &cmds, args) == 0)
		exit(EXIT_FAILURE);
	main_p = fork();
	if (main_p == 0)
		cmds_process(path, inout, cmds);
	else
	{
		args.wpid_cmds = wait(&(args.main_status));
		while (args.wpid_cmds > 0)
			args.wpid_cmds = wait(&(args.main_status));
		free_process(path, inout, cmds, 1);
	}
	return (0);
}
