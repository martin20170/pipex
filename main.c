/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:59:46 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/10 01:06:53 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_state()
{
	ft_printf("An error occured!\n");
	exit(EXIT_FAILURE);
}

char	**get_in_and_out(char **input)
{
	// input :     pipex      infile       "grep -o 'xxxxxx'"        "wc -l"       outfile
	char	**result;

	result = malloc(sizeof(char *) * 3);
	if (!result)
		error_state();
	result[0] = input[1];
	result[1] = input[4];
	result[2] = NULL;
	return (result);
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

char	*complete_border(char *str)
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
		temp = complete_border(cmd_name);
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

void	print_strlst(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		ft_printf("%s\n", lst[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		error_state();

	char	**in_n_out = get_in_and_out(argv);
	char	***cmds = get_cmds(argv);
	char	**path = get_path(envp);
	if (!path)
		exit(EXIT_FAILURE);

	pid_t	main_p;
	pid_t	cmds_p;
	pid_t	step1_p;
	pid_t	step2_p;

	main_p = fork();
	if (main_p == 0)
	{
		int	fd[]={3, 4};
		pipe(fd);
		cmds_p = fork();
		if (cmds_p == 0)
		{
			close(fd[0]);

			char	**cmd1_path = get_cmd_path(path, cmds[0][0]);
			int		step_1_status = 0;

			step1_p = fork();

			if (step1_p == 0)
			{
				int	infile = open(in_n_out[0], O_RDONLY);
				if (infile == -1)
					exit(0);
				if (dup2(infile, STDIN_FILENO) == -1)
					exit(0);
				close(infile);
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					exit(0);
				if (exec_loop(cmd1_path, cmds[0]) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				if (waitpid(step1_p, &step_1_status, 0) == -1)
					exit(EXIT_FAILURE);
				if (WEXITSTATUS(step_1_status) == EXIT_FAILURE)
					ft_printf("command not found : %s\n", cmds[0][0]);

				close(fd[1]);
				free_strlst(cmd1_path);
				while (wait(NULL) != -1 || errno != ECHILD);
			}
		}
		else
		{
			close(fd[1]);

			char	**cmd2_path = get_cmd_path(path, cmds[1][0]);
			int		step_2_status = 0;

			step2_p = fork();

			if (step2_p == 0)
			{
				int	outfile = open(in_n_out[1], O_WRONLY | O_CREAT, 0777);
				if (outfile == -1)
					exit(0);
				if (dup2(outfile, STDOUT_FILENO) == -1)
					exit(0);
				close(outfile);
				if (dup2(fd[0], STDIN_FILENO) == -1)
					exit(0);
				if (exec_loop(cmd2_path, cmds[1]) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				if (waitpid(step2_p, &step_2_status, 0) == -1)
					exit(EXIT_FAILURE);
				if (WEXITSTATUS(step_2_status) == EXIT_FAILURE)
					ft_printf("command not found : %s\n", cmds[1][0]);

				close(fd[1]);
				free_strlst(cmd2_path);
				while (wait(NULL) != -1 || errno != ECHILD);
			}
		}
	}
	else
	{
		while (wait(NULL) != -1 || errno != ECHILD);
		free(in_n_out);
		free_cmds(cmds);
		free_strlst(path);
	}
	return (0);
}
