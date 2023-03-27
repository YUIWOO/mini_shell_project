/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:29:05 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/27 12:54:07 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

extern	t_info g_info;

int	cd(char *path)
{
	char	**path_info;
	char	*new_path;
	char	*buffer;
	int		result;

	buffer = get_pwd();
	set_env_value(&g_info.envp, "OLDPWD", buffer);
	free(buffer);
	path_info = ft_split(path, '/');
	if (ft_strncmp(path_info[0], "~",
			ft_strlen(path_info[0])) == 0)
	{
		free(path_info[0]);
		path_info[0] = get_env_value(g_info.envp, "HOME");
		new_path = str_total_join(path_info, "/");
		free_dptr(path_info, HOME);
	}
	else
	{
		new_path = str_total_join(path_info, "/");
		free_dptr(path_info, DEFAULT);
	}
	result = chdir(new_path);
	if (result == -1)
	{
		free(new_path);
		show_error("cd");
		return (1);
	}
	buffer = get_pwd();
	set_env_value(&g_info.envp, "PWD", buffer);
	free(new_path);
	free(buffer);
	return (0);
}
