/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:22:12 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/24 20:51:59 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	get_dptr_size(char **dptr)
{
	int	i;

	i = 0;
	while (dptr[i])
		i++;
	return (i);
}
//export 관련한 함수이다. leak이 생길 우려가 있음
void	set_env_statement(char **env_addr, char *key, char *value)
{
	char	*str;
	char	*temp;

	str = key;
	temp = str;
	str = ft_strjoin(str, "=");
	temp = str;
	str = ft_strjoin(str, value);
	free(temp);
	temp = *env_addr;
	*env_addr = str;
	free(temp);
}

void	make_env_statement(char *key, char *value)
{
	char **
}

char	*set_env_value(char **envp, char *key, char *value)
{
	int	exist_idx;	
	int	i;

	i = 0;
	exist_idx = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, ft_strlen(key)) == 0
			&& envp[i][ft_strlen(key)] == '=')
			{
				set_env_statement(&envp[i], key, value);
				exist_idx = 1;
				break ;
			}
			// return (&envp[i][ft_strlen(key) + 1]);
		i++;
	}
	if (exist_idx == 0)
	{

	}
	//export 부분에서 새로 추가되는 key의 경우 추가해야 할 필요가 있음
	return (NULL);
}