/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:34:39 by youngwch          #+#    #+#             */
/*   Updated: 2023/03/31 09:31:46 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		exit_with_perror(file_name);
	free(file_path);
	return (fd);
}

int	is_regular_file(char *exec_path)
{
	struct stat	buf;

	stat(exec_path, &buf);
	if ((buf.st_mode & S_IFMT) == S_IFREG)
		return (1);
	return (0);
}

int	is_path(char *cmd_path)
{
	int	i;

	i = -1;
	while (cmd_path[++i])
	{
		if (cmd_path[i] == '/')
			return (1);
	}
	return (0);
}

int	is_dir(char *exec_path)
{
	struct stat	buf;

	stat(exec_path, &buf);
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}
