/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:29:05 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/30 19:23:34 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	change_pwd_env(char *new_path, char ***envp)
{
	char	*buffer;

	if (chdir(new_path) == -1)
	{
		free(new_path);
		show_error("cd");
		return (1);
	}
	buffer = get_pwd();
	set_env_value(envp, "PWD", buffer);
	free(new_path);
	free(buffer);
	return (0);
}

int	cd(char *path, char ***envp)
{
	char	**path_info;
	char	*new_path;
	char	*buffer;

	printf("here %s\n", path);
	buffer = get_pwd();
	set_env_value(envp, "OLDPWD", buffer);
	free(buffer);
	if (!path)
		new_path = ft_strdup(get_env_value(*envp, "HOME"));//str_total_join(get_env_value(*envp, "HOME"), "/");
	else
	{
		path_info = ft_split(path, '/');
		new_path = str_total_join(path_info, "/");
		free_dptr(path_info, DEFAULT);
		//new_path = ft_strjoin("/", new_path);
	}
	printf("%s\n", new_path);
	return (change_pwd_env(new_path, envp));
}
