/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:59:46 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/09 17:59:28 by mphilip          ###   ########.fr       */
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

// [[cat, -n], [wc, -l]]
// tab[0] = [cat, -n]
// tab[0][0] = cat
// tab[0][0][0] = c


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

char	*complete_output(char *incomplete, char *to_add)
{
	char	*result;

	result = ft_strjoin(incomplete, to_add);
	if (!result)
		return (NULL);
	free(incomplete);
	free(to_add);
	return (result);
}

char	*get_cmd_result(int fd)
{
	char	*temp;
	char	*temp_result;

	temp_result = malloc(1);
	if (!temp_result)
		return (NULL);
	temp_result[0] = 0;
	temp = get_next_line(fd);
	if (!temp)
		return (free(temp_result), NULL);
	while (temp[0])
	{
		temp_result = complete_output(temp_result, temp);
		if (!temp_result)
			return (free(temp), free(temp_result), NULL);
		temp = get_next_line(fd);
		if (!temp)
			return (free(temp), free(temp_result), NULL);
	}
	return (free(temp), temp_result);
}

int	main(int argc, char **argv)
{
	if (argc != 5)
		error_state();

	char	**in_n_out = get_in_and_out(argv);
	char	***cmds = get_cmds(argv);

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

			char	*cmd1_name = cmds[0][0];
			char	*path1 = ft_strjoin("/usr/bin/", cmd1_name);
			char	*path2 = ft_strjoin("/bin/", cmd1_name);
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
				if (execve(path1, cmds[0], NULL) == -1 && execve(path2, cmds[0], NULL) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				if (waitpid(step1_p, &step_1_status, 0) == -1)
					exit(EXIT_FAILURE);
				if (WEXITSTATUS(step_1_status) == EXIT_FAILURE)
					ft_printf("command not found : %s\n", cmd1_name);

				free(path1);
				free(path2);
				close(fd[1]);
				while (wait(NULL) != -1 || errno != ECHILD);
			}
		}
		else
		{
			// if (waitpid(cmds_p, &cmds_status, 0) == -1)
			// 	exit(EXIT_FAILURE);
			// if (!WIFEXITED(cmds_status))
			// 	exit(EXIT_FAILURE);

			close(fd[1]);

			char	*cmd2_name = cmds[1][0];
			char	*path1 = ft_strjoin("/usr/bin/", cmd2_name);
			char	*path2 = ft_strjoin("/bin/", cmd2_name);
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
				if (execve(path1, cmds[1], NULL) == -1 && execve(path2, cmds[1], NULL) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				if (waitpid(step2_p, &step_2_status, 0) == -1)
					exit(EXIT_FAILURE);
				if (WEXITSTATUS(step_2_status) == EXIT_FAILURE)
					ft_printf("command not found : %s\n", cmd2_name);

				free(path1);
				free(path2);
				close(fd[1]);
				while (wait(NULL) != -1 || errno != ECHILD);
			}
		}
	}
	else
	{
		while (wait(NULL) != -1 || errno != ECHILD);
		free(in_n_out);
		free_cmds(cmds);
	}
	return (0);
}
