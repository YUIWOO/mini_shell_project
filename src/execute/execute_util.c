/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:34:39 by youngwch          #+#    #+#             */
/*   Updated: 2023/03/30 19:36:01 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	exit_with_perror(char *message)
{
	perror(message);
	exit(errno);
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
