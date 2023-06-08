/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:59:46 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/08 19:20:25 by mphilip          ###   ########.fr       */
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


int	main(int argc, char **argv)
{
	if (argc != 5)
		error_state();

	(void)argv;
	// char	**in_n_out = get_in_and_out(argv);
	// char	***cmds = get_cmds(argv);

	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == 0)
	{
		int	fd[]={3, 4};
		pipe(fd);
		pid2 = fork();
		if (pid2 == 0)
		{
			close(fd[0]);
			int	infile = open("./infile", O_RDONLY);
			if (infile == -1)
				exit(0);
			if (dup2(infile, STDIN_FILENO) == -1)
				exit(0);
			close(infile);
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				exit(0);
			write(STDOUT_FILENO, "infile\ntest\nde\nla\ncomm\n", 23);
			// char	*cmd1_name = cmds[0][0];
			// if (execve(ft_strjoin("/bin/", cmd1_name), cmds[0], NULL) == -1)
			// 	perror("\n\nPAS CE PATH LA\n\n");
			// else if (execve(ft_strjoin("/bin/", cmd1_name), cmds[0], NULL) == -1)
			// 	perror("\n\ncommand not exist :)\n\n");
			close(fd[1]);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			int	outfile = open("./outfile", O_WRONLY | O_CREAT, 0777);
			if (outfile == -1)
				exit(0);
			if (dup2(outfile, STDOUT_FILENO) == -1)
				exit(0);
			close(outfile);
			if (dup2(fd[0], STDIN_FILENO) == -1)
				exit(0);
			// char	*buf[6];
			// read(STDIN_FILENO, buf, 6);

			char	*args[]={"cat", "-n", NULL};
			if (execve("/bin/cat", args, NULL) == -1)
				perror("\n\nPAS CE PATH LA\n\n");
			// else if (execve(ft_strjoin("/bin/", cmd2_name), cmds[1], NULL) == -1)
			// 	perror("\n\ncommand not exist :)\n\n");
			close(fd[0]);
			// char	*cmd2_name = cmds[1][0];
			// if (execve(ft_strjoin("/bin/", cmd2_name), cmds[1], NULL) == -1)
			// 	perror("\n\nPAS CE PATH LA\n\n");
			// else if (execve(ft_strjoin("/bin/", cmd2_name), cmds[1], NULL) == -1)
			// 	perror("\n\ncommand not exist :)\n\n");
		}
	}
	else
	{
		waitpid(-1, NULL, 0);
		// free(in_n_out);
		// free_cmds(cmds);
		ft_printf("\n\nFINISH\n\n");
	}
	return (0);
}



// ./pipex infile "grep -o '[[:alpha:]]'" "wc -l" outfile


// char	*arg[4];
// 	arg[0] = "a.out";
// 	arg[1] = "-n";
// 	arg[2] = "infie";
// 	arg[3] = NULL;
// 	if (execve("/bin/cat", arg, NULL) == -1)
// 		perror("Erreur lors de l'ouverture du fichier");
// 	ft_printf("ligne jamais atteinte\n");
