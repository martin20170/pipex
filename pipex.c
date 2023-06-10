/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:59:46 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/10 15:29:33 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	main_p;
	t_args	args;
	char	**in_n_out;
	char	***cmds;
	char	**path;

	args.argv = argv;
	args.envp = envp;
	if (argc != 5)
		error_state();
	if (strings_init(&in_n_out, &path, &cmds, args) == 0)
		exit(EXIT_FAILURE);
	main_p = fork();
	if (main_p == 0)
		cmds_process(path, in_n_out, cmds);
	else
		free_process(path, in_n_out, cmds, 1);
	return (0);
}
