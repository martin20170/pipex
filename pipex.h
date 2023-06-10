/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:00:43 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/10 15:44:25 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <time.h>
# include <sys/wait.h>

typedef struct s_cmds_p
{
	pid_t	cmd1_p;
	pid_t	cmd2_p;
	int		cmd1_status;
	int		cmd2_status;
	int		fd[2];
}			t_cmds_p;

typedef struct s_args
{
	char	**argv;
	char	**envp;
}			t_args;


/* ########################### STRINGS_INIT ########################### */


char	**get_path(char **envp);
char	***get_cmds(char **input);
char	**get_in_and_out(char **input);
int		str_init(char ***inout_a, char ***path_a, char ****cmds_a, t_args args);


/* ########################### FREE_FT ########################### */


void	*error_state(void);
void	free_cmds(char ***cmds);
void	free_strlst(char **var);
void	free_process(char **path, char **inout, char ***cmds, int endmain);


/* ########################### CMDS_PROCESS ########################### */


int		exec_loop(char **cmd_path, char **cmd);
void	cmds_process(char **path, char **inout, char ***cmds);
void	cmd1_process(t_cmds_p params, char **path, char **inout, char ***cmds);
void	cmd2_process(t_cmds_p params, char **path, char **inout, char ***cmds);


/* ########################### CMDS_PROCESS_UTILS ########################### */


void	cmd1_fd_switch(char **inout, int *fd);
void	cmd2_fd_switch(char **inout, int *fd);
void	cmd1_check(char **cmd1_path, t_cmds_p params, char ***cmds);
void	cmd2_check(char **cmd2_path, t_cmds_p params, char ***cmds);


/* ########################### CMDS_PATH ########################### */


char	*name_with_slash(char *str);
char	**get_cmd_path(char **path, char *cmd_name);


#endif
