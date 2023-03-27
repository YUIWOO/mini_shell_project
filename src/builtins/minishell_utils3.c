/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:53:31 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/27 20:56:47 by yuikim           ###   ########.fr       */
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
