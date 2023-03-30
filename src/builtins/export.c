/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:33:04 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/30 19:37:06 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	export(char **args, char ***envp)
{
	char	*arg_copy;
	char	*key;
	char	*value;
	char	*temp;

	while (*(++args))
	{
		if (!(*envp))
			return (1);
		if (ft_strchr(*args, '=') == NULL)
			continue ;
		arg_copy = ft_strdup(*args);
		temp = ft_strchr(arg_copy, '=');
		*temp = 0;
		key = arg_copy;
		value = temp + 1;
		set_env_value(envp, key, value);
		free(key);
	}
	return (0);
}

int	export_no_option(char **envp)
{
	char	**envp_copy;
	int		i;

	envp_copy = dptr_dup(envp);
	ft_sort_ascii(envp_copy, get_dptr_size(envp_copy));
	i = -1;
	while (envp_copy[++i])
		printf("declare -x %s\n", envp[i]);
	free_dptr(envp_copy, DEFAULT);
	return (0);
}
