/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:53:31 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/28 10:22:43 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
	make_env_statement(envp, key, value);
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i ++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_ascii(char **str_arr, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i -1)
		{
			if (ft_strcmp(str_arr[j], str_arr[j + 1]) > 0)
			{
				temp = str_arr[j];
				str_arr[j] = str_arr[j + 1];
				str_arr[j + 1] = temp;
			}
			j++;
		}		
		i++;
	}	
}
