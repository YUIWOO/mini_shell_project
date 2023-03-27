/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:22:12 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/27 12:53:01 by yuikim           ###   ########.fr       */
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
	free(*env_addr);
	*env_addr = str;
}

char *create_env_statement(char *key, char *value)
{
	char	*str;
	char	*temp;

	str = ft_strjoin(key, "=");
	temp = str;
	str = ft_strjoin(str, value);
	free(temp);
	return (str);
}

void	make_env_statement(char ***envp_ptr, char *key, char *value)
{
	char	*statement;

	statement = create_env_statement(key, value);
	
	// statement = ft_strdup("");
	append_dptr(envp_ptr, statement);
	// set_env_statement(&statement, key, value);
	// printf("%s\n", statement);
	// append_dptr(envp_ptr, statement);
	free(statement);
}

void	append_dptr(char ***dptr, char *statement)
{
	int		i;
	int		size;
	char	**new_dptr;

	// printf("%p\n", *dptr);
	if (!dptr)
		return ;
	size = get_dptr_size(*dptr) + 1;
	new_dptr = malloc(sizeof(char *) * (size + 1));
	// printf("%p\n", new_dptr);
	if (new_dptr)
	{
		i = -1;
		while (++i < size - 1)
		{
			new_dptr[i] = (*dptr)[i];
			// free((*dptr)[i]);
		}
		new_dptr[size - 1] = statement;
		printf("sdfsdffds %s\n\n\n\n", new_dptr[size - 1]);
		new_dptr[size] = 0;
		// free(*dptr);
	}
	*dptr = new_dptr;
	// free(new_dptr);
}

char	*set_env_value(char ***envp, char *key, char *value)
{	
	int	i;

	i = 0;
	while ((*envp)[i])
	{
		if (ft_strncmp((*envp)[i], key, ft_strlen(key)) == 0
			&& (*envp)[i][ft_strlen(key)] == '=')
			{
				set_env_statement(&(*envp)[i], key, value);
				return (&(*envp)[i][ft_strlen(key) + 1]);
			}
		i++;
	}
	// //export 부분에서 새로 추가되는 key의 경우 추가해야 할 필요가 있음
	make_env_statement(&(*envp), key, value);
	return (0);
}