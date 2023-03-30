/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:06:16 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/30 21:37:43 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	remove_env(char *key, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, ft_strlen(key)) == 0
			&& envp[i][ft_strlen(key)] == '=')
			break ;
		i++;
	}
	free(envp[i]);
	while (envp[i + 1])
	{
		envp[i] = envp[i + 1];
		i++;
	}
	envp[i] = NULL;
}

int	unset(char **args, char **envp)
{
	while (*(++args))
	{
		if (!get_env_value(envp, *args))
			continue ;
		if (*args[0] != '_' && !ft_isalpha(*args[0]))
		{
			printf("bash: unset: `%s': not a valid identifier\n", *args);
			continue ;
		}//unset도 합의 필요함
		remove_env(*args, envp);
	}
	return (0);
}
