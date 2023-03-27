#include "../include/main.h"

void	exit_with_perror(char *message)
{
	perror(message);
	exit(1);
}

int	open_file(char *file_name, int option)
{
	char	*file_path;
	int		fd;

	if (*file_name == '/')
		file_path = ft_strjoin("", file_name);
	else
		file_path = ft_strjoin("./", file_name);
	fd = open(file_path, option, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		exit_with_perror("open");
	free(file_path);
	return (fd);
}

void set_fd(t_redirect *redirect, int *i_fd_ref, int *o_fd_ref)
{
	int i = 0;
	int option;
	while(redirect[i].type != NULL_STATE)
	{
		if(redirect[i].type == REDIR_IN || redirect[i].type == REDIR_HEREDOC)
		{
			if(redirect[i].type == REDIR_IN)
				option = O_RDONLY;
			// if(redirect[i].type == REDIR_HEREDOC)
			// {

			// }
			*i_fd_ref = open_file(redirect[i].file_name, option);
		}
		else if(redirect[i].type == REDIR_OUT || redirect[i].type == REDIR_APPEND)
		{
			if(redirect[i].type == REDIR_OUT)
			option = O_CREAT | O_WRONLY;
			else if(redirect[i].type == REDIR_APPEND)
				option = O_CREAT | O_APPEND | O_WRONLY;
			*o_fd_ref = open_file(redirect[i].file_name, option);
		}
		i ++;
	}
}

int execute(t_execution *execution, char **envp, int **pipe_ar, int index)
{
	int input_fd;
	int output_fd;
	if(index == 0)
			input_fd = 0;
	else
	{
		input_fd = pipe_ar[index-1][0];
		close(pipe_ar[index-1][1]);
	}
	if(pipe_ar[index] == NULL)
	{
		output_fd = 1;
	}
	else
	{
		output_fd = pipe_ar[index][1];
		close(pipe_ar[index][0]);
	}
	set_fd(execution->redirect_ar, &input_fd, &output_fd);
	// printf("index : %d input : %d output : %d\n", index, input_fd, output_fd);
	dup2(input_fd, 0);
	dup2(output_fd, 1);
	char *cmd_path = make_command_path(execution->exev_argv[0], envp);
	if(!cmd_path)
		execve(execution->exev_argv[0], execution->exev_argv, envp);
	execve(cmd_path, execution->exev_argv, envp);
	return -1;
}