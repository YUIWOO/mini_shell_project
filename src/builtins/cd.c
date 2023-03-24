/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:29:05 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/24 21:01:13 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

extern	t_info g_info;

int	cd(char *path)
{
	char	**path_info;
	char	*new_path;
	int		result;

	path_info = ft_split(path, '/');
	if (ft_strncmp(path_info[0], "~",
			ft_strlen(path_info[0])) == 0)
	{
		// free(path_info[0]);
		path_info[0] = get_env_value(g_info.envp, "HOME");
	}
	else
		;
		// free(path_info[0]);
	new_path = str_total_join(path_info, "/");
	// free_dptr(path_info);
	result = chdir(new_path);
	if (result == -1)
	{
		show_error("cd");
		return (1);
	}
	set_env_value(g_info.envp, "PWD", new_path);
	return (0);
}

// char **get_path_info(char *path)
// {
// 	char	**raw_path_info;
// 	char	*pwd;
// 	char	*home;

// 	raw_path_info = ft_split("path", '/');
// 	//home 경로 받기 0 -> ~이면
// 	//중간에 .이나 .. 나오면 연산된 pwd의 현재 경로, 이전 경로
// 	//연산된 경로를 최종 반환
// }



// int main()
// {
// 	cd("/");
// 	int i = 0;
// 	while(1)
// 		if (i == 0)
// 			pwd();
// 		i++;
// 		;
// 	return (0);
// }